# object = N_queens.c
# object = main.c
# object = cpu_usage_multi_thread.c
# object = cpu_usage.c
object = main_ultimate.c

CC = gcc
# CC =/home/anubhab/Desktop/Agnikul/cross_compiler/gcc-arm-10.3-2021.07-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-gcc


all:
	@$(CC) $(object) -o main
	
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
