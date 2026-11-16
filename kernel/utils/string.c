#include "../memory/heap.h"
#include <stddef.h>

static int string_compare(const char* a, const char* b)
{
    while (*a && *b)
    {
        if (*a != *b)
            return 0;
        a++;
        b++;
    }

    return *a == '\0' && *b == '\0';
}

static void print_prompt(void)
{
    terminal_color = COLOR_GREEN;
    terminal_write("root@AditiOS");

    terminal_color = COLOR_WHITE;
    terminal_write(":~$ ");
}



const char* append(const char **a, const char *b) {

    const char *a_ptr = *a;
    const char *b_ptr = b;

    size_t len = 0;

    while (*a_ptr++) len++;
    while (*b_ptr++) len++;

    char *temp = kmalloc(len + 1);

    if (temp == NULL)
        return NULL;

    char *temp_ptr = temp;

    a_ptr = *a;

    while (*a_ptr)
        *temp_ptr++ = *a_ptr++;

    while (*b)
        *temp_ptr++ = *b++;

    *temp_ptr = '\0';

    return temp;
}