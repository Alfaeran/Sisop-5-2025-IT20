prepare:
	mkdir -p bin

bootloader:
	nasm src/bootloader.asm -f bin -o bin/bootloader

stdlib:
	i386-elf-gcc -m32 -ffreestanding -c src/std_lib.c -o bin/std_lib.o

shell:
	i386-elf-gcc -m32 -ffreestanding -c src/shell.c -o bin/shell.o

kernel:
	i386-elf-gcc -m32 -ffreestanding -c src/kernel.c -o bin/kernel.o
	nasm src/kernel.asm -f elf -o bin/kernelasm.o

link:
	i386-elf-ld -m elf_i386 -Ttext 0x1000 -o bin/kernel.bin bin/kernel.o bin/std_lib.o bin/shell.o bin/kernelasm.o --oformat binary
	cat bin/bootloader bin/kernel.bin > bin/os-image

build: prepare bootloader stdlib shell kernel link
