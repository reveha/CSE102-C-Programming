all: clean compile run

compile: main.c
	@echo "Compiling..."
	@gcc -o test main.c

run:
	@echo "-------------------------------------------"
	@echo "Running..."
	@./test

clean:
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f test
