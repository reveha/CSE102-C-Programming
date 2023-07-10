all: clean compile run

compile:
	@gcc -c main.c -lm
	@gcc -o test main.o -lm
	@echo COMPILING SUCCESFUL
	@echo -------------------

run:
	@echo RUNNING
	@echo -----------------
	@./test
	
	
clean:
	@rm -f *.o
	@rm -f test
