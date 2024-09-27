
CFLAGS =  

main :
	@gcc $(CFLAGS) *.c -o gbc
	@./gbc