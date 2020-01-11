FLAGS=-Wall -Wextra -Wpedantic -g

virtual.out: virtual.o organism.o
	gcc $(FLAGS) -o $@ $^

virtual.o: virtual.c
	gcc -c $(FLAGS) -o $@ $<

organism.o: organism.c
	gcc -c $(FLAGS) -o $@ $<

clean:
	rm -f *.o
	rm -f *.out
