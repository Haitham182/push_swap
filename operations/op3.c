/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revers_rot_and_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 14:34:45 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/10/13 18:01:01 by Haitham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	op_sa(t_data *data)
{
	if (!data->a || !data->a->head || !data->a->head->next)
		return ;
	swap(data->a);
	write(1, "sa\n", 3);
	data->bench->sa++;
	data->bench->total++;
}

void	op_sb(t_data *data)
{
	if (!data->b || !data->b->head || !data->b->head->next)
		return ;
	swap(data->b);
	write (1, "sb\n", 3);
	data->bench->sb++;
	data->bench->total++;
}

void	op_pa(t_data *data)
{
	if (!data->a || !data->b || !data->b->head)
		return ;
	push(data->a, data->b);
	write (1, "pa\n", 3);
	data->bench->pa++;
	data->bench->total++;
	//a should have the size  from the first
	data->a->size++;
	data->b->size--;
}

void	op_pb(t_data *data)
{
	if (!data->a || !data->b || !data->a->head)
		return ;
	push(data->b, data->a);
	write (1, "pb\n", 3);
	data->bench->pb++;
	data->bench->total++;
	data->b->size++;
	data->a->size--;
}
