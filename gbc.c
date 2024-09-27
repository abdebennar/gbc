#include "gbc.h"

// TODO removing doubly lincked list from gbc

void	gbc_add(t_gbc **list, void *data)
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

void	gbc_remove(t_gbc **list, void *data)
{
	t_gbc *tmp = *list;
	t_gbc *tofree;
	if (tmp && tmp->addr != data)
		while (tmp->next && tmp->next->addr != data)
			tmp = tmp->next;
	if (tmp->next && tmp->next->addr == data)
	{
		tofree = tmp->next;
		tmp->next = tmp->next->next;
		// free (tofree->addr);
		// free(tofree);
	}
}

void	gbc(void	*data, t_mode mode)
{
	static	t_gbc* list;
	static	int capacity;

	if (mode == ADD)
	{
		gbc_add(&list, data);
		capacity++;
	}


	else if (mode == REMOVE)
	{
		gbc_remove(&list, data);
		capacity--;
	}

	else if (mode == EARSE)
	{
		t_gbc *tmp = list;
		while (tmp && tmp->next)
		{
			tmp->addr = NULL;
			// if (tmp->addr == tmp->next->addr)
			// {
			// 	gbc_remove(&list, tmp->addr);
			// 	tmp = list;
			// }
			tmp = tmp->next;
		}
	}


}
void	leaks()
{
	system("leaks gbc");
}

int main() 
{
	atexit(leaks);

	char  *mm = alloc(1000);
	if (!mm)
		strcpy(mm, "llolll");

	mm = NULL;

	// gbc(NULL, EARSE);
    // delete(intPtr);
    // delete(arrayPtr);

    return 0;
	

}

