#include "gbc.h"

void	*alloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	gbc(ret, ADD);

	return (ret);
}
