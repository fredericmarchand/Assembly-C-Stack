play: a4.o assign4.c 
	gcc -m32 -o play assign4.c a4.o 
a4.o: a4.asm
	nasm -f elf a4.asm
