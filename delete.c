#include "gbc.h"

void	delete(void	*addr)
{
	gbc(addr, REMOVE);
}
