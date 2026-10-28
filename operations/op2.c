/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 10:36:02 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/10/15 14:18:20 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	op_rra(t_data *data)
{
	if (!data->a || !data->a->head || !data->a->head->next)
		return ;
	reverse_rot(data->a);
	write (1, "rra\n", 4);
	data->bench->rra++;
	data->bench->total++;
}

void	op_rrb(t_data *data)
{
	if (!data->b || !data->b->head || !data->b->head->next)
		return ;
	reverse_rot(data->b);
	write (1, "rrb\n", 4);
	data->bench->rrb++;
	data->bench->total++;
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
