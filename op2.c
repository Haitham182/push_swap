/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 10:36:02 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/10/12 10:42:54 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra(t_stack *a)
{
	if (!a || !a->head || !a->head->next)
		return ;
	reverse_rot(a);
	write (1, "rra\n", 4);
}

void	op_rrb(t_stack *b)
{
	if (!b || !b->head || !b->head->next)
		return ;
	reverse_rot(b);
	write (1, "rrb\n", 4);
}
