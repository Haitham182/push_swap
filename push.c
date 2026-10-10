/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 12:08:45 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/10/10 14:14:41 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
