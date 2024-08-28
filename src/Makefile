CFLAGS = -std=c99 -Wall -g
LDFLAGS = -lm -lelf -l:libbsd.a

.PHONY: all clean

all: simulator

objects = main.o include/cpu.o include/instructions.o include/memory.o include/reader.o

simulator: $(objects)
	gcc $(CFLAGS) -o simulator.exe $(objects) $(LDFLAGS)


main.o: main.c
	gcc $(CFLAGS) -c main.c $(LDFLAGS)

cpu.o: include/cpu.c
	gcc $(CFLAGS) -c include/cpu.c $(LDFLAGS)

instructions.o: include/instructions.c
	gcc $(CFLAGS) -c include/instructions.c $(LDFLAGS)

memory.o: include/memory.c
	gcc $(CFLAGS) -c include/memory.c $(LDFLAGS)

reader.o: include/reader.c
	gcc $(CFLAGS) -c include/reader.c $(LDFLAGS)

clean:
	rm -f simulator.exe
	rm -f $(objects)
