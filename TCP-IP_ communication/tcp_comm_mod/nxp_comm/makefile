object = client_mod.c
# object = march_test.c

# CC = gcc
CC =/home/anubhab/Desktop/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-gcc

all:
	@$(CC) $(object) -o main -lm
	
clean:
	@if [ -f main ]; then\
		rm main;\
		echo "previous main file removed";\
	fi
rebuild:
	@if [ -f main ]; then\
		rm main;\
		echo "previous main file removed";\
	fi
	@$(CC) main.c -o main;\
	echo "main file rebuilt";\