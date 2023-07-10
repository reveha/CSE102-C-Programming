all:  clean compile run


compile:
	@gcc -c main.c utils.c
	@echo -------compiling-------
	@gcc -o test main.o utils.o
	@echo -------successful-------

run:
	@echo -------running-------
	@./test


clean:
	@echo -------cleaning-------
	@rm -f *.o
	@rm -f test
	@rm -f customeraccount.txt

