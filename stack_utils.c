/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborabi <aborabi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 17:14:17 by aborabi           #+#    #+#             */
/*   Updated: 2026/10/14 17:14:49 by aborabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *head)
{
	int		size;
	t_node	*current;

	size = 0;
	current = head;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}
