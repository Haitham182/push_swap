/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 14:34:45 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/10/12 10:05:14 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rot(t_stack *stk)
{
	t_node	*temp;

	if (!stk || !stk->head || !stk->head->next)
		return ;
	temp = stk->last;
	stk->last = stk->last->prev;
	temp->prev = NULL;
	stk->last->next = NULL;
	temp->next = stk->head;
	stk->head->prev = temp;
	stk->head = temp;
}

void	op_ra(t_stack *a)
{
	if (!a || !a->head || !a->head->next)
		return ;
	swap(a);
	write(1, "ra\n", 3);
}

void	op_rb(t_stack *b)
{
	if (!b || !b->head || !b->head->next)
		return ;
	swap(b);
	write (1, "rb\n", 3);
}
void op_pa(t_stack *a, t_stack *b)
{
	if (!a || !b || !b->head)
		return ;
	push(a, b);
	write (1, "pa\n", 3);
}
void op_pb(t_stack *b, t_stack *a)
{
	if (!a || !b || !a->head)
		return ;
	push(b, a);
	write (1, "pb\n", 3);
}
