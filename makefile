FLAGS=-Wall -Wextra -Wpedantic -g
SRC=$(wildcard *.c)
OBJ=$(patsubst %.c,%.o,$(SRC))

virtual.out: $(OBJ)
	gcc $(FLAGS) -o $@ $^

%.o: %.c
	gcc -c $(FLAGS) -o $@ $<

clean:
	rm -f *.o
	rm -f *.out
