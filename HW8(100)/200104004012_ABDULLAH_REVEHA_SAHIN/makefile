all: clean compile run

compile: main.c util.c util.h
	@echo "Compiling..."
	@gcc -o test main.c util.c

run:
	@echo "-------------------------------------------"
	@echo "Running..."
	@./test

clean:
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f test
