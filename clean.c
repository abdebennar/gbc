#include "gbc.h"
#include <stdio.h>

void	__attribute__((destructor)) clean()
{
	gbc(NULL, CLEAN);
}
