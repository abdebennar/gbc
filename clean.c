#include "gbc.h"
#include <stdio.h>

void	__attribute__((destructor)) clean()
{
	printf("HERE\n");
	gbc(NULL, CLEAN);
}
