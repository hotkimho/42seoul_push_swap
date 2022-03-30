/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkim2 <hkim2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 16:20:13 by hkim2             #+#    #+#             */
/*   Updated: 2022/03/30 20:26:46 by hkim2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_stack
{
	int		data;
	struct 	s_stack *next;
	struct	s_stack *prev;
}					t_stack;

//error
void	error_msg(char *message);

//stack_util
void	push_node(t_stack **stk, int data);
int		pop_node(t_stack **stk);
int		get_stack_size(t_stack *stk);
void	stack_init(t_stack **a, t_stack **b);

//operation_swap
void	sa(t_stack **a);
void	sb(t_stack **b);

//oeration_push
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

//operation_rotate
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

//operation_reverse_rotate
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
#endif