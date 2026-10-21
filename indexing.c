/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborabi <aborabi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 03:16:04 by aborabi           #+#    #+#             */
/*   Updated: 2026/10/21 03:16:31 by aborabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_indices(t_stack *a)
{
	t_node	*curr;
	t_node	*compare;
	int		index;

	if (!a || !a->head)
		return ;
	curr = a->head;
	while (curr)
	{
		index = 0;
		compare = a->head;
		while (compare)
		{
			if (compare->value < curr->value)
				index++;
			compare = compare->next;
		}
		curr->index = index;
		curr = curr->next;
	}
}
