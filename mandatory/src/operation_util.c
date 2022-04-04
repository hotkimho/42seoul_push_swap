
#include "../include/push_swap.h"

void	exec_num_ra(t_stack **a, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		ra(a);
		i++;
	}
}

void	exec_num_sa_rra(t_stack **a, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		sa(a);
		rra(a);
		i++;
	}
}

void	exec_num_rb(t_stack **b, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		rb(b);
		i++;
	}
}

void	exec_num_sb_rrb(t_stack **b, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		sb(b);
		rrb(b);
		i++;
	}
}