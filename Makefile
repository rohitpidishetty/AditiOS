
AS = nasm
CC = gcc
LD = ld

ASFLAGS = -f elf32

CFLAGS = -m32 \
         -std=gnu99 \
         -ffreestanding \
         -O2 \
         -Wall \
         -Wextra \
         -fno-pie \
         -fno-stack-protector

LDFLAGS = -m elf_i386 \
          -T linker.ld \
          -nostdlib

KERNEL = kernel.elf
ISO = AditiOS.iso

SOURCES = kernel/kernel.c \
          kernel/memory/heap.c

OBJECTS = kernel.o heap.o

all: $(ISO)

boot.o: boot/boot.asm
	$(AS) $(ASFLAGS) $< -o $@

kernel.o: kernel/kernel.c
	$(CC) $(CFLAGS) -c $< -o $@

heap.o: kernel/memory/heap.c
	$(CC) $(CFLAGS) -c $< -o $@

$(KERNEL): boot.o $(OBJECTS) linker.ld
	$(LD) $(LDFLAGS) -o $@ boot.o $(OBJECTS)

$(ISO): $(KERNEL)
	mkdir -p isodir/boot/grub
	cp $(KERNEL) isodir/boot/kernel.elf
	cp grub/grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o $(ISO) isodir

run: $(ISO)
	qemu-system-i386 -cdrom $(ISO) -m 128M

check: $(KERNEL)
	grub-file --is-x86-multiboot $(KERNEL)

clean:
	rm -rf *.o $(KERNEL) $(ISO) isodir

.PHONY: all run check clean
