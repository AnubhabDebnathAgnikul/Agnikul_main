all:
	gcc main.c definition.c -o main
	
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
	@gcc main.c definition.c -o main;\
	echo "main file rebuilt";\