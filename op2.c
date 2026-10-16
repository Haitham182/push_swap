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

#include "push_swap.h"

void	op_rra(t_stack *a, t_data *data)
{
	if (!a || !a->head || !a->head->next)
		return ;
	reverse_rot(a);
	write (1, "rra\n", 4);
	data->bench->rra++;
	data->bench->total++;
}

void	op_rrb(t_stack *b, t_data *data)
{
	if (!b || !b->head || !b->head->next)
		return ;
	reverse_rot(b);
	write (1, "rrb\n", 4);
	data->bench->rrb++;
	data->bench->total++;
}

void	delete_stack(t_stack *stk)
{
	t_node	*temp;

	if (!stk)
		return ;
	while (stk->head)
	{
		temp = stk->head;
		stk->head = stk->head->next;
		free(temp);
	}
	free(stk);
}
