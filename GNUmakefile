microvim:
	rm -rf build
	mkdir build
	$(CC) src/microvim.c -o build/microvim -Wall -Wextra -pedantic -std=c99
	cp src/after/thankyou.txt build/thankyou.txt
	./build/microvim build/thankyou.txt


install:
	sudo cp build/microvim /usr/local/bin/microvim
	echo "alias mvim=/usr/local/bin/microvim" >> ~/.bashrc
	echo "alias mim=/usr/local/bin/microvim" >> ~/.bashrc
