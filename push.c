/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 12:08:45 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/10/11 16:49:46 by hmuqasqu         ###   ########.fr       */
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
	node->prev = NULL;
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
	return (stack);
}

void	push(t_stack *dest, t_stack *source)
{
	t_node	*temp;

	if (!source || !source->head || !dest)
		return ;
	temp = source->head;
	source->head = source->head->next;
	if (source->head)
		source->head->prev = NULL;
	else
		source->last = NULL;
	temp->next = dest->head;
	temp->prev = NULL;
	if (dest->head)
		dest->head->prev = temp;
	else
		dest->last = temp;
	dest->head = temp;
}

void	swap(t_stack *stk)
{
	t_node	*temp;

	if (!stk || !stk->head || !stk->head->next)
		return ;
	temp = stk->head;
	stk->head = stk->head->next;
	stk->head->prev = NULL;
	temp->next = stk->head->next;
	if (temp->next) //to make sure there is more than 2 nodes
		stk->head->next->prev = temp;
	stk->head->next = temp;
	temp->prev = stk->head;
	if (!temp->next)
		stk->last = temp;
}

void	rotate(t_stack *stk)
{
	t_node	*temp;

	if (!stk || !stk->head || !stk->head->next)
		return ;
	temp = stk->head;
	stk->head = temp->next;
	stk->head->prev = NULL;
	stk->last->next = temp;
	temp->prev = stk->last;
	temp->next = NULL;
	stk->last = temp;
}
