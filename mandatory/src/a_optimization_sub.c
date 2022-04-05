/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:20:05 by hkim2             #+#    #+#             */
/*   Updated: 2022/04/04 20:42:00 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	five_last_case(t_stack **a, t_stack **b)
{
	exec_num_ra(a, 3);
	exec_num_sa_rra(a, 3);
	sa(a);
	a_exec_three_sort(a, b);
}
//32 25 16 33 17
//4  3  1  5  2
//4 1 3 5 2

//
int	a_five_sort(t_stack **a, t_stack **b)
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
		exec_num_sa_rra(a, 1);
		sa(a);
		a_exec_four_sort(a, b);
	}
	else if ((*a)->next->next->next->data == get_min_data(*a, 5))
	{
		exec_num_ra(a, 2);
		exec_num_sa_rra(a, 2);
		sa(a);
		a_exec_four_sort(a, b);
	}
	else
		five_last_case(a, b);
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
		exec_num_ra(a, 2);
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