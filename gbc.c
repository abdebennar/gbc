#include "gbc.h"

static void	gbc_add(t_gbc **list, void *data)
{
		t_gbc *new;
		new = malloc(sizeof(t_gbc));
		new->next = NULL;
		if (!*list)
			*list = new;
		else
		{
			new->next = *list;
			*list = new;
		}
		new->addr = data;
}

static void	gbc_remove(t_gbc **list, void *data)
{
	t_gbc *tmp = *list;
	t_gbc *prev;
	t_gbc *tofree;
	while (tmp && tmp->addr != data)
	{
		// printf("loop\n");
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp && tmp->addr == data)
	{
		tofree = tmp;
		if (prev == NULL)
			*list = tmp->next;
		else
			prev->next = tmp->next;
		free (tofree->addr);
		free(tofree);
	}
}

void	gbc(void	*data, t_mode mode)
{
	static	t_gbc* list;

	if (mode == ADD)
		gbc_add(&list, data);
	else if (mode == REMOVE)
		gbc_remove(&list, data);
	else if (mode == CLEAN)
	{
		while (list)
		{
			gbc_remove(&list, list->addr);
			list = list->next;
		}
	}
}

