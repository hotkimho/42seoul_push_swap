/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_optimization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:20:24 by hkim2             #+#    #+#             */
/*   Updated: 2022/04/04 19:53:38 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	a_exec_three_sort(t_stack **a, t_stack **b)
{
	pb(b, a);
	if (get_stack_size(*a) == 3)
		a_three_optimize_sort(a);
	else
		a_check_three(a, b);
	pa(a, b);
}

void	a_exec_four_sort(t_stack **a, t_stack **b)
{
	pb(b, a);
	if (get_stack_size(*a) == 4)
		a_four_optimize_sort2(a, b);
	else
		a_four_optimize_sort(a, b);
	pa(a, b);
}

void	a_three_optimize_sort(t_stack **a)
{
	if (check_ascending(*a, 3))
		return ;
	if ((*a)->data == get_max_data(*a, 3))
	{
		ra(a);
		if (!check_ascending(*a, 3))
			sa(a);
	}
	else if ((*a)->next->data == get_max_data(*a, 3))
	{
		if ((*a)->data < (*a)->next->next->data)
		{
			sa(a);
			ra(a);
		}
		else
			rra(a);
	}
	else
		if (!check_ascending(*a, 3))
			sa(a);
	return ;
}


int	a_four_optimize_sort(t_stack **a, t_stack **b)
{	
	if ((*a)->data == get_min_data(*a, 4))
		a_exec_three_sort(a, b);
	else if ((*a)->next->data == get_min_data(*a, 4))
	{
		sa(a);
		a_exec_three_sort(a, b);
	}
	else if ((*a)->next->next->data == get_min_data(*a, 4))
		return (1);
	else
		return (1);
	return (0);
}

int	a_four_optimize_sort2(t_stack **a, t_stack **b)
{	
	if ((*a)->data == get_min_data(*a, 4))
		a_exec_three_sort(a, b);
	else if ((*a)->next->data == get_min_data(*a, 4))
	{
		sa(a);
		a_exec_three_sort(a, b);
	}
	else if ((*a)->next->next->data == get_min_data(*a, 4))
	{
		ra(a);
		sa(a);
		a_exec_three_sort(a, b);
	} 
	else
	{
		rra(a);
		a_exec_three_sort(a, b);
	}
	return (0);
}


int	a_five_optimize_sort(t_stack **a, t_stack **b)
{	
	if ((*a)->data == get_min_data(*a, 5))
		a_exec_four_sort(a, b);
	else if ((*a)->next->data == get_min_data(*a, 5))
	{
		sa(a);
		a_exec_four_sort(a, b);
	}
	else if ((*a)->next->next->data == get_min_data(*a, 5))
	{
		ra(a);
		sa(a);
		rra(a);
		sa(a);
		a_exec_three_sort(a, b);
	} 
	else
		return (1);
	return (0);
}


/*
1 2 3 4 5
2 1 3 4 5
3 2 1 4 5
4 3 2 1 5


4 3 1 5 2
3 1 5 2
4 3 2 0 1
*/

int	a_five_optimize_sort2(t_stack **a, t_stack **b)
{	
	if ((*a)->data == get_min_data(*a, 5))
		a_exec_four_sort(a, b);
	else if ((*a)->next->data == get_min_data(*a, 5))
	{
		sa(a);
		a_exec_four_sort(a, b);
	}
	else if ((*a)->next->next->data == get_min_data(*a, 5))
	{
		ra(a);
		ra(a);
		a_exec_four_sort(a, b);
	} 
	else if ((*a)->next->next->next->data == get_min_data(*a, 5))
	{
		rra(a);
		rra(a);
		a_exec_four_sort(a, b);
	} 
	else
	{
		rra(a);
		a_exec_four_sort(a, b);
	}
	return (0);
}