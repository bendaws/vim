si:
	rm -rf build
	mkdir build
	$(CC) si.c -o build/si -Wall -Wextra -pedantic -std=c99
	cp after/thankyou.txt build/thankyou.txt
	./build/si build/thankyou.txt


install:
	sudo cp build/si /usr/local/bin/si
	echo "alias siedit=/usr/local/bin/si" >> ~/.bashrc
	echo "alias simodify=/usr/local/bin/si" >> ~/.bashrc
