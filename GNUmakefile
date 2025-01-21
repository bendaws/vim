all:
	rm -rf build
	mkdir build
	$(CC) editor.c -o build/editor -Wall -Wextra -pedantic -std=c99
	sudo cp build/editor /usr/local/bin/editor

editor:
	rm -rf build
	mkdir build
	$(CC) editor.c -o build/editor -Wall -Wextra -pedantic -std=c99

install:
	sudo cp build/editor /usr/local/bin/editor