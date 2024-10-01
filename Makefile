
CFLAGS = -Wall -Wextra -Werror -pedantic 

main :
	cc $(CFLAGS) *.c -o gbc
	@ valgrind ./gbc