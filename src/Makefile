CFLAGS = -std=c99 -Wall -g
LDFLAGS = -lm -lelf -l:libbsd.a

.PHONY: all clean

all: simulator

objects = main.o include/reader.o

simulator: $(objects)
	gcc $(CFLAGS) -o simulator.exe $(objects) $(LDFLAGS)


main.o: main.c
	gcc $(CFLAGS) -c main.c $(LDFLAGS)

reader.o: include/reader.c
	gcc $(CFLAGS) -c include/reader.c $(LDFLAGS)

clean:
	rm -f simulator.exe
	rm -f $(objects)
