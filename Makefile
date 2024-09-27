
CFLAGS = -g3

main :
	@gcc $(CFLAGS) *.c -o gbc
	@./gbc