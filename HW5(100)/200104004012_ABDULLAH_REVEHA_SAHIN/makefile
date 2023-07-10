all: clean compile run

compile: main.c
	@echo "Compiling..."
	@gcc -c main.c
	@gcc -o test main.o -lm

run:
	@echo "Running the tests...."
	@./test
	@echo "Completed tests...."

clean:
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f test
