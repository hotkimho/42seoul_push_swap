

#include "../include/push_swap.h"

void	check_duplicate(t_stack *stk, int size)
{
	int	i;
	int	j;
	int	arr[size];

	if (!stk)
		error_msg("Error\n");
	i = 0;
	while (i < size)
	{
		arr[i++] = stk->data;
		stk = stk->next;
	}
	i = 0;
	while (i < (size - 1))
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				error_msg("Error\n");
			j++;
		}
		i++;
	}
}

int	check_ascending(t_stack *stk, int size)
{
	int	i;
	int	data;

	if (!stk)
		return (0);
	i = 0;
	data = stk->data;
	while (i < size)
	{
		if (data > stk->data && i != 0)
			return (0);
		data = stk->data;
		stk = stk->next;
		i++;
	}
	if (i == size)
		return (1);
	return (0);
}

int	check_descending(t_stack *stk, int size)
{
	int	i;
	int	data;

	if (!stk)
		return (0);
	i = 0;
	data = stk->data;
	while (i < size)
	{

		if (data < stk->data && i != 0)
			return (0);
		data = stk->data;
		stk = stk->next;
		i++;
	}
	if (i == size)
		return (1);
	return (0);
}