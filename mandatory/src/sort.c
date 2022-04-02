/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:16:35 by hkim2             #+#    #+#             */
/*   Updated: 2022/04/02 21:45:45 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	init_sorting(t_stack *stk, int size, int *a_count, int *b_count)
{
	if (!stk)
		error_msg("Error\n");
	*a_count = 0;
	*b_count = 0;
	return get_pivot(stk, size);
}

int		b_check_sorting(t_stack **a , t_stack **b, int size)
{
	if (size == 1)
	{
		pa(a, b);
		return (1);
	}
	if (size == 2)
	{
		b_check_two(b);
		pa(a, b);
		pa(a, b);
		return (1);
	}
	else if (size == 3)
	{
		b_check_three(a, b);
		pa(a, b);
		pa(a, b);
		pa(a, b);
		return (1);
	}
	else if (size ==500000)
		a = NULL;
	return (0);
}

void	B_to_A(t_stack **a, t_stack **b, int size)
{
	int	i;
	int a_count;
	int b_count;
	int pivot;

	pivot = init_sorting(*b, size, &a_count, &b_count);
	if (b_check_sorting(a, b, size))
		return ;
	i = -1;
	while (++i < size)
	{
		if ((*b)->data >= pivot)
		{
			pa(a, b);
			a_count++;
		}
		else
		{
			rb(b);
			b_count++;
		}
	}
	i = -1;
	while (++i < b_count)
		rrb(b);
	A_to_B(a, b, a_count);
	B_to_A(a, b, b_count);
}

int		b_check_sorting(t_stack **a , t_stack **b, int size)
{
	if (size == 1)
	{
		pa(a, b);
		return (1);
	}
	if (size == 2)
	{
		b_check_two(b);
		pa(a, b);
		pa(a, b);
		return (1);
	}
	else if (size == 3)
	{
		b_check_three(a, b);
		pa(a, b);
		pa(a, b);
		pa(a, b);
		return (1);
	}
	return (0);
}


int		a_check_sorting(t_stack **a, t_stack **b, int size)
{
	if (size == 1)
		return (1);
	if (size == 2)
	{
		a_check_two(a);
		return (1);
	}
	else if (size == 3)
	{
		a_check_three(a, b);
		return (1);
	}
	else if (size ==22222)
		*b = NULL;
	return (0);
}

void	A_to_B(t_stack **a, t_stack **b, int size)
{
	int	i;
	int a_count;
	int b_count;
	int pivot;

	pivot = init_sorting(*a, size, &a_count, &b_count);
	//pivot = get_pivot(*a, size);
	if (a_check_sorting(a, b, size))
		return ;
	i = 0;
	while (i < size)
	{
		if ((*a)->data >= pivot)
		{
			ra(a);
			a_count++;
		}
		else
		{
			pb(b, a);
			b_count++;
		}
		i++;
	}
	i = -1;
	while (++i < a_count)
		rra(a);
	A_to_B(a, b, a_count);
	B_to_A(a, b, b_count);
}
