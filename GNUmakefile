vim2:
	rm -rf build
	mkdir build
	$(CC) vim.c -o build/vim2 -Wall -Wextra -pedantic -std=c99
	cp after/thankyou.txt build/thankyou.txt
	./build/vim build/thankyou.txt

install:
	sudo cp build/vim2 /usr/local/bin/vim2