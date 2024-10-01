#include "gbc.h"
#include <stdlib.h>

void	*alloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	gbc(ret, ADD);

	return (ret);
}
