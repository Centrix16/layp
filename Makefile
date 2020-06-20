all:
	gcc -Wall -O0 -g layp.c tree.c -o layp
clean:
	rm -f layp report.log
