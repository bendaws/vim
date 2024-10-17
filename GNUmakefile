.PHONY: valgrind format

microvim: *.c
	$(CC) microvim.c point.c history.c -o microvim -Wall -Wextra -pedantic -std=c99

clangformat:
	clang-format -i *.c *.h

install:
	echo "Please use install-nvim or install-microvim. See README for more info"

install-mvim:
	sudo cp microvim /usr/local/bin/mvim

install-microvim:
	sudo cp microvim /usr/local/bin/microvim

install-both:
	sudo cp microvim /usr/local/bin/mvim
	sudo cp microvim /usr/local/bin/microvim