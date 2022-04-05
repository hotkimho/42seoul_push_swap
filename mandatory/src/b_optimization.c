/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_optimization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:20:24 by hkim2             #+#    #+#             */
/*   Updated: 2022/04/04 19:21:29 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	b_exec_three_sort(t_stack **a, t_stack **b)
{
	pa(a, b);
	if (get_stack_size(*b) == 3)
		b_three_optimize_sort(b);
	else
		b_check_three(a, b);
	pb(b, a);


}

//void	b_exec_four_sort(t_stack **a, t_stack **b)
//{
//	pb(b, a);
//	if (get_stack_size(*a) == 4)
//		a_four_optimize_sort(a, b);
//	else
//		a_four_sort(a, b);
//	pa(a, b);
//}

void	b_three_optimize_sort(t_stack **b)
{
	if (check_descending(*b, 3))
		return ;
	if ((*b)->data == get_max_data(*b, 3))
	{
		if (check_descending(*b, 3))
			return;
		rrb(b);
		sb(b);
	}
	else if ((*b)->next->data == get_max_data(*b, 3))
	{
		if ((*b)->data < (*b)->next->next->data)
			rb(b);
		else
			sb(b);
	}
	else
	{
		if ((*b)->data < (*b)->next->data)
			sb(b);
		rrb(b);
	}
	return ;
}


// 4 2 1 3
//void	b_four_optimize_sort(t_stack **a, t_stack **b)
//{
//	if ((*b)->data == get_max_data(*b, 4))
//		b_exec_three_sort(a, b);
//	else if ((*b)->next->data == get_max_data(*b, 4))
//	{
//		sb(b);
//		b_exec_three_sort(a, b);
//	}
//	else if ((*b)->next->next->data == get_max_data(*b, 4))
//	{
//		rb(b);
//		exec_num_sb_rrb(b, 1);
//		sb(b);
//		b_exec_three_sort(a, b);
//	}
//	else
//	{
//		exec_num_rb(b, 2);
//		exec_num_sb_rrb(b, 2);
//		sb(b);
//		b_exec_three_sort(a, b);
//	}
//}

void	b_four_sort(t_stack **a, t_stack **b)
{
	if ((*b)->data == get_max_data(*b, 4))
		b_exec_three_sort(a, b);
	else if ((*b)->next->data == get_max_data(*b, 4))
	{
		sb(b);
		b_exec_three_sort(a, b);
	}
	else if ((*b)->next->next->data == get_max_data(*b, 4))
	{
		rb(b);
		exec_num_sb_rrb(b, 1);
		sb(b);
		b_exec_three_sort(a, b);
	}
	else
	{
		exec_num_rb(b, 2);
		exec_num_sb_rrb(b, 2);
		sb(b);
		b_exec_three_sort(a, b);
	}
}

void	b_four_optimize_sort(t_stack **a, t_stack **b)
{
	if ((*b)->data == get_max_data(*b, 4))
		b_exec_three_sort(a, b);
	else if ((*b)->next->data == get_max_data(*b, 4))
	{
		sb(b);
		b_exec_three_sort(a, b);
	}
	else if ((*b)->next->next->data == get_max_data(*b, 4))
	{
		rb(b);
		sb(b);
		b_exec_three_sort(a, b);
	}
	else
	{
		rrb(b);
		b_exec_three_sort(a, b);
	}
}