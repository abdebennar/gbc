#include "gbc.h"

void	gbc_add(t_gbc *list, void *data)
{
		
}

void	gbc_remove(t_gbc *list, void *data)
{
	
}

void	gbc(void	*data, t_mode mode)
{
	static	t_gbc* list = NULL;

	if (mode == ADD)
	{
		auto t_gbc *tmp = list;
	t_gbc	*cur = NULL;
	t_gbc	*tofree = NULL;
	while (tmp && tmp->addr != data)
		tmp = tmp->next;
	cur = tmp;
	if (cur)
	{
		tofree = cur;
		free (cur->addr);
		tmp = cur->prev;
		cur->prev = cur->next;
		cur->next = tmp;
		free(tofree);
	}
	}

	else if (mode == REMOVE)
	{
		t_gbc *new;
		new = malloc(sizeof(t_gbc));
		new->next = NULL;
		new->prev = NULL;
		if (!list)
			list = new;
		else
		{
			list->prev = new;
			new->next = list;
			list = new;
		}
		new->addr = data;
	}
}

void	leaks()
{
	system("leaks gbc");
}

int main() 
{
	atexit(leaks);
    // Step 1: Allocate memory for an integer
    int* intPtr = (int*)alloc(sizeof(int));
    if (intPtr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Step 2: Assign a value to the allocated memory
    *intPtr = 42;
    printf("Value assigned to intPtr: %d\n", *intPtr);

    // Step 3: Free the allocated memory
    delete(intPtr);
    printf("Memory freed for intPtr\n");

    // Step 4: Allocate memory for an array of integers
    int* arrayPtr = (int*)alloc(5 * sizeof(int));
    if (arrayPtr == NULL) {
        printf("Memory allocation for array failed\n");
        return 1;
    }

    // Step 5: Assign values to the array
    for (int i = 0; i < 5; i++) {
        arrayPtr[i] = i * 10;
        printf("arrayPtr[%d] = %d\n", i, arrayPtr[i]);
    }

	gbc(NULL, EARSE);
    // Step 6: Free the allocated memory for the array
    delete(arrayPtr);
    printf("Memory freed for arrayPtr\n");

    return 0;
}

