
/*
 * OS v0.1.0
 * Interactive Kernel Terminal
 */




typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define VGA_WIDTH  80
#define VGA_HEIGHT 25

#define VGA_MEMORY ((volatile u16*)0xB8000)

#define COLOR_WHITE  0x0F
#define COLOR_GREEN  0x02
#define COLOR_CYAN   0x0B
#define COLOR_RED    0x0C

#define KEYBOARD_DATA_PORT   0x60
#define KEYBOARD_STATUS_PORT 0x64

#define INPUT_SIZE 128

static u32 row = 0;
static u32 column = 0;

static u8 terminal_color = COLOR_WHITE;

static char input[INPUT_SIZE];
static u32 input_length = 0;

static int shift_pressed = 0;






static u16 vga_entry(char c, u8 color)
{
    return (u16)c | ((u16)color << 8);
}

static inline void outb(u8 value, u16 port)
{
    __asm__ volatile (
        "outb %0, %1"
        :
        : "a"(value), "Nd"(port)
    );
}



static void update_cursor(void)
{
    u16 position = row * VGA_WIDTH + column;

   

    outb(0x0F, 0x3D4);

    outb((position & 0xFF), 0x3D5);

    outb(0x0E, 0x3D4);

    outb((position >> 8), 0x3D5);

}


static void terminal_clear(void)
{
    for (u32 i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++)
      VGA_MEMORY[i] = vga_entry(' ', terminal_color);
    

    row = 0;
    column = 0;

    update_cursor();
}


static void terminal_scroll(void)
{
    for (u32 y = 1; y < VGA_HEIGHT; y++)
        for (u32 x = 0; x < VGA_WIDTH; x++)
            VGA_MEMORY[(y - 1) * VGA_WIDTH + x] =
                VGA_MEMORY[y * VGA_WIDTH + x];
        

    for (u32 x = 0; x < VGA_WIDTH; x++)
        VGA_MEMORY[(VGA_HEIGHT - 1) * VGA_WIDTH + x] =
            vga_entry(' ', terminal_color);
    

    row = VGA_HEIGHT - 1;
}

static void terminal_newline(void)
{
    column = 0;
    row++;

    if (row >= VGA_HEIGHT)
        terminal_scroll();
    
    update_cursor();
}

static void terminal_putchar(char c)
{
    if (c == '\n')
    {
        terminal_newline();
        return;
    }

    if (c == '\b')
    {
        if (column > 0)
        {
            column--;
        }
        else if (row > 0)
        {
            row--;
            column = VGA_WIDTH - 1;
        }

        VGA_MEMORY[row * VGA_WIDTH + column] =
            vga_entry(' ', terminal_color);

        update_cursor();
        return;
    }

    VGA_MEMORY[row * VGA_WIDTH + column] =
        vga_entry(c, terminal_color);

    column++;

    if (column >= VGA_WIDTH)
      terminal_newline();
    else
      update_cursor();
    
}

static void terminal_write(const char* str)
{
    while (*str)
    {
        terminal_putchar(*str);
        str++;
    }
}



#include "utils/string.c"
#include "drivers/keyboard.c"





static void command_execute(const char* cmd)
{
  if (string_compare(cmd, ""))
    return;
  const char *command = append(&cmd, "\n");
  terminal_write(command);

   

}

/* ================= SHELL ================== */

static void shell_start(void)
{
    while (1)
    {
        print_prompt();

        input_length = 0;

        while (1)
        {
            char c = keyboard_read_char();

            if (c == '\n')
            {
                terminal_putchar('\n');

                input[input_length] = '\0';

                break;
            }

            if (c == '\b')
            {
                if (input_length > 0)
                {
                    input_length--;
                    terminal_putchar('\b');
                }

                continue;
            }

            if (c == '\t')
                continue;

            if (input_length < INPUT_SIZE - 1)
            {
                input[input_length++] = c;
                terminal_putchar(c);
            }
        }

        command_execute(input);
    }
}


/* ============= KERNEL ENTRY =============== */

void aditi_kernel(void)
{
    terminal_color = COLOR_WHITE;

    terminal_clear();

    terminal_color = COLOR_CYAN;

    terminal_write("================================\n");
    terminal_write("       Welcome to AditiOS       \n");
    terminal_write("================================\n");

    terminal_color = COLOR_GREEN;

    terminal_write("[OK] Kernel initialized\n");
    terminal_write("[OK] VGA terminal initialized\n");
    terminal_write("[OK] Keyboard driver initialized\n");
    terminal_write("[OK] Shell initialized\n");

    terminal_color = COLOR_WHITE;

    terminal_write("\nAditiOS v0.1.0\n");
    terminal_write("Type 'help' to see commands.\n\n");

    shell_start();

    
    while (1)
        __asm__ volatile ("hlt");
    
}
