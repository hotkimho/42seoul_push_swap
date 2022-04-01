

#include "../include/push_swap.h"

void	b_check_two(t_stack **b)
{
	if (check_descending(*b, 2))
		return;
	sb(b);
}


void	b_check_three(t_stack **b)
{
	int	max;

	if (check_descending(*b, 3))
		return ;
	max = get_max_data(*b, 3);
	if ((*b)->data == max)
	{
		sb(b);
		rb(b);
		return ;
	}
	if ((*b)->next->data == max)
	{
		if ((*b)->data < (*b)->next->next->data)
			rb(b);
		else
			sb(b);
		return ;
	}
	else
	{
		if ((*b)->data < (*b)->next->data)
			sb(b);
		rrb(b);
	}
	return ;
}