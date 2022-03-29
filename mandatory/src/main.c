#include "../include/push_swap.h"
#include<stdio.h>

void	push_node(t_stack *a, int data)
{
	t_stack	*node;

	a->data =2;
	node = (t_stack *)malloc(sizeof(t_stack));
	node->data = data;
	node->next = a;
	printf("data : %d\n", data);
}

int main()
{
	t_stack	*a;
	t_stack	*b;

	a = (t_stack *)malloc(sizeof(t_stack));
	printf("qwe\n");
	push_node(a, 1);
	push_node(a, 2);

	printf("%d\n", a->data);


}