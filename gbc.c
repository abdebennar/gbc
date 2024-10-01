#include "gbc.h"
#include <stdlib.h>

static  t_gbc*	gbc_add(t_gbc *list, void *data)
{
		t_gbc *new;
		new = malloc(sizeof(t_gbc));
		new->next = NULL;
		new->next = list;
		new->addr = data;
		list = new;
		return (list);
}

static t_gbc*	gbc_remove(t_gbc *list, void *data)
{
	t_gbc *tmp = list;
	t_gbc *prev = NULL;
	t_gbc *tofree;
	while (tmp && tmp->addr != data)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp && tmp->addr == data)
	{
		tofree = tmp;
		if (prev == NULL)
			list = tmp->next;
		else
			prev->next = tmp->next;
		free (tofree->addr);
		free(tofree);
	}
	return (list);
}

void	gbc(void	*data, t_mode mode)
{
	static	t_gbc* list;

	if (mode == ADD)
		list = gbc_add(list, data);
	else if (mode == REMOVE)
		list = gbc_remove(list, data);
	else if (mode == CLEAN)
	{
		while (list)
		{
			t_gbc *toremove = list;
			list = list->next;
			free(toremove->addr);
			free(toremove);
		}
	}
}

