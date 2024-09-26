#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef	enum e_mode
{
	ADD = 0,
	REMOVE,
	EARSE
}	t_mode;


typedef struct s_gbc
{
	void	*addr;
	struct s_gbc *next;
	struct s_gbc *prev;
} 	t_gbc;

void	*alloc(size_t size);
void	gbc(void	*data, t_mode mode);
void	delete(void	*addr);
