all: clear clean compile run

clear:
	@clear

compile:

	@gcc -c main.c -lm
	@gcc -o main.out main.o -lm

run:
	@./main.out	

clean:
	@rm -f *o
	@rm -f main.out
		
