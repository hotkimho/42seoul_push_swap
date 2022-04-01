/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:20:05 by hkim2             #+#    #+#             */
/*   Updated: 2022/03/31 20:16:59 by hkim2            ###   ########.fr       */
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
		if (b)
		{
			printf("%d", b->data);
			b = b->next;
		}
		printf("\n");
	}
}
void	B_to_A(t_stack **a, t_stack **b, int size)
{

}



void	A_to_B(t_stack **a, t_stack **b, int size)
{
	int	idx;
	int a_count, b_count;

	a_count = b_count = 0;
	if (size == 1)
		return;
	idx = 0;
	while (idx < size)
	{
		if ((*a)->data >= 5)
		{
			ra(a);
			a_count++;
		}
		else
		{
			pb(b, a);
			b_count++;
		}
		idx++;
	}
	A_to_B(a, b, )
}

//10 5 11 5 12 6 13 6


int main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	init_stack(&a, &b);
	parse_argv(argc, argv, &b);
	init_push_a(&a, &b);

	check_duplicate(a, get_stack_size(a));
	//check_two(&a);
	b_check_three(&a);
	print_stack(a);
	//A_to_B(&a, &b, get_stack_size(a));
	//print(a, b);
	exit(0);
}

