
#include <unistd.h>

typedef	enum e_mode
{
	ADD = 0,
	REMOVE,
	UNIQUE,
	CLEAN
}	t_mode;


typedef struct s_gbc
{
	void	*addr;
	struct s_gbc *next;
} 	t_gbc;

void	gbc(void	*data, t_mode mode);
void	*alloc(size_t size);
void	delete(void	*addr);
void	__attribute__((destructor)) clean();
