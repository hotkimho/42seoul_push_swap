/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:20:05 by hkim2             #+#    #+#             */
/*   Updated: 2022/04/02 20:21:07 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include<stdio.h>

int count;

void print_stack(t_stack *stk)
{
	while(stk)
	{
		printf("%d\n", stk->data);
		stk = stk->next;
	}
	printf("\n");
}

void	print(t_stack *a, t_stack *b)
{
	int len;
	int i;

	if (get_stack_size(a) > get_stack_size(b))
		len = get_stack_size(a);
	else
		len = get_stack_size(b);
	for (i = 0; i < len; i++)
	{
		if (a)
		{
			printf("%d ", a->data);
			a = a->next;
		}
		else
			printf("  ");
		if (b)
		{
			printf("%d", b->data);
			b = b->next;
		}
		else
			printf("  ");
		printf("\n");
	}
	printf("- -\n");
	printf("a b\n");
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
		print_stack(*a);
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

	a_count = 0;
	b_count = 0;
	pivot = get_pivot(*b, size);
	printf("BStart - size : %d pivot : %d\n", size, pivot);
	if (b_check_sorting(a, b, size))
	{
		print(*a, *b);
		return ;
	}
	i = 0;
	while (i < size)
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
		i++;
	}
	i = -1;
	
	while (++i < b_count)
	{
		rrb(b);
	}
	print(*a, *b);
	A_to_B(a, b, a_count);
	B_to_A(a, b, b_count);
}

void	A_to_B(t_stack **a, t_stack **b, int size)
{
	int	i;
	int a_count;
	int b_count;
	int pivot;

	a_count = 0;
	b_count = 0;
	pivot = get_pivot(*a, size);
	printf("AStart - size : %d pivot : %d\n", size, pivot);
	if (a_check_sorting(a, b, size))
	{
		print(*a, *b);
		return ;
	}
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
	print(*a, *b);
	A_to_B(a, b, a_count);
	B_to_A(a, b, b_count);
}

//2 1 3 6 5 8

/*
b
pb
ra
ra
ra
ra
rra
rra
rra
rra
rra
rra

*/
int main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	init_stack(&a, &b);
	parse_argv(argc, argv, &b);
	init_push_a(&a, &b);
	check_duplicate(a, get_stack_size(a));
	// 2 3 4 
	// 3 2 4 
	//b = NULL;
	A_to_B(&a, &b, get_stack_size(a));
	//printf("\n----------------끝--------------\n");
	//push_node(&a, 8);
	//push_node(&a, 5);
	//print_stack(a);
	//pb(&b, &a);
	//pb(&b, &a);
	//print(a, b);
	//ra(&a);
	//ra(&a);
	//ra(&a);
	//ra(&a);
	//print(a, b);
	//rra(&a);
	//rra(&a);
	//rra(&a);
	//rra(&a);
	//rra(&a);
	//rra(&a);
	//print(a, b);
	//push_node(&a, 6);
	//push_node(&a, 3);
	//push_node(&a, 1);
	//push_node(&a, 2);
	//print(a, b);
	//pb(&b, &a);
	//print(a, b);
	//pb(&b, &a);
	//print(a, b);
	//ra(&a);
	//ra(&a);
	//ra(&a);
	//ra(&a);
	//print(a, b);
	//rra(&a);
	//rra(&a);
	//rra(&a);
	//rra(&a);
	//rra(&a);
	//rra(&a);
	//print_stack(a);
	exit(0);
}

