
#include "../include/push_swap.h"

void	b_five_last_case(t_stack **a, t_stack **b)
{
	exec_num_rb(b, 3);
	exec_num_sb_rrb(b, 3);
	sb(b);
	b_exec_four_sort(a, b);
}

void	b_five_sort(t_stack **a, t_stack **b)
{

	if ((*b)->data == get_max_data(*b, 5))
		b_exec_four_sort(a, b);
	else if ((*b)->next->data == get_max_data(*b, 5))
	{
		sb(b);
		b_exec_four_sort(a, b);
	}
	else if ((*b)->next->next->data == get_max_data(*b, 5))
	{
		rb(b);
		exec_num_sb_rrb(b, 1);
		sb(b);
		b_exec_four_sort(a, b);
	}
	else if ((*b)->next->next->next->data == get_min_data(*b, 5))
	{
		exec_num_rb(b, 2);
		exec_num_sb_rrb(b, 2);
		sb(b);
		b_exec_four_sort(a, b);
	}
	else
		b_five_last_case(a, b);
}

void	b_five_optimize_sort(t_stack **a, t_stack **b)
{
	if ((*b)->data == get_max_data(*b, 5))
		b_exec_four_sort(a, b);
	else if ((*b)->next->data == get_max_data(*b, 5))
	{
		sb(b);
		b_exec_four_sort(a, b);
	}
	else if ((*b)->next->next->data == get_max_data(*b, 5))
	{
		rb(b);
		sb(b);
		b_exec_four_sort(a, b);
	}
	else if ((*b)->next->next->next->data == get_min_data(*b, 5))
	{
		rrb(b);
		rrb(b);
		b_exec_four_sort(a, b);
	}
	else
	{
		rrb(b);
		b_exec_four_sort(a, b);
	}
}
