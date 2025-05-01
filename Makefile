CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJ = main.o modules/processor.o modules/sorter.o modules/validator.o

tarea2: $(OBJ)
	$(CC) $(CFLAGS) -o tarea2 $(OBJ)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

modules/processor.o: modules/processor.c modules/processor.h modules/validator.h
	$(CC) $(CFLAGS) -c modules/processor.c -o modules/processor.o

modules/sorter.o: modules/sorter.c modules/sorter.h modules/processor.h
	$(CC) $(CFLAGS) -c modules/sorter.c -o modules/sorter.o

modules/validator.o: modules/validator.c modules/validator.h
	$(CC) $(CFLAGS) -c modules/validator.c -o modules/validator.o

clean:
	rm -f *.o modules/*.o tarea2
