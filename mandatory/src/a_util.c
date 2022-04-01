

#include "../include/push_swap.h"

int		get_max_data(t_stack *stk, int size)
{
	int	data;
	int	i;

	if (!stk)
		error_msg("Error\n");
	data = stk->data;
	i = 0;
	while (i < size)
	{
		if (data < stk->data)
			data = stk->data;
		stk = stk->next;
		i++;
	}
	return (data);
}

void	check_two(t_stack **a)
{
	if (check_ascending(*a, 2))
		return;
	sa(a);
}


void	a_check_three(t_stack **a)
{
	int	max;

	if (check_ascending(*a, 3))
		return ;
	max = get_max_data(*a, 3);
	if ((*a)->data == max)
	{
		ra(a);
		if (!check_ascending(*a, 3))
			sa(a);
		return ;
	}
	if ((*a)->next->data == max)
	{
		sa(a);
		ra(a);
		if (!check_ascending(*a, 3))
			sa(a);
		return ;
	}
	else
		if (!check_ascending(*a, 3))
			sa(a);
	return ;
}