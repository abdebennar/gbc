
CFLAGS =  -Wextra -Wall -pedantic -g3 -O3  -std=c11

main :
	@gcc $(CFLAGS) *.c -o gbc
	@./gbc