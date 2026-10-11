/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 12:08:45 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/10/11 14:07:44 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lstnew_node(int number)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->number = number;
	node->next = NULL;
	return (node);
}

t_stack	*lstnew_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->last = NULL;
}

void	push(t_stack *dest, t_stack *source)
{
	t_node	*temp;

	if (!source || !source->head || !dest)
		return ;
	temp = source->head;
	source->head = source->head->next;
	temp->next = dest->head;
	dest->head = temp;
	if (!dest->last)
		dest->last = dest->head;
	if (source->last == temp)
		source->last = NULL;
}

void	swap(t_stack *stk)
{
	t_node	*temp;

	if (!stk || !stk->head || !stk->head->next)
		return ;
	temp = stk->head;
	stk->head = stk->head->next;
	temp->next = temp->next->next;
	stk->head->next = temp;
	if (!temp->next) //if there is only two nodes in the stack
		stk->last = temp;
}
void	rotate(t_stack *stk)
{
	t_node	*temp;
	
	if (!stk || !stk->head || !stk->head->next)
		return ;
	temp = stk->head;
	stk->head = temp->next;
	stk->last->next = temp;
	stk->last = temp;
	temp->next = NULL;
}
