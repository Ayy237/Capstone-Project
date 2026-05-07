CC=gcc
CFLAGS=-Wall

all: calendar

calendar: main.o event.o
	$(CC) $(CFLAGS) main.o event.o -o calendar

main.o: main.c event.h
	$(CC) $(CFLAGS) -c main.c

event.o: event.c event.h
	$(CC) $(CFLAGS) -c event.c

clean:
	rm -f *.o calendar