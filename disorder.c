/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborabi <aborabi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 23:21:45 by aborabi           #+#    #+#             */
/*   Updated: 2026/10/14 01:18:55 by Haitham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_inversions(t_stack *stack)
{
	int		inversions;
	t_node	*i;
	t_node	*j;

	inversions = 0;
	if (!stack || !stack->head)
		return (0);
	i = stack->head;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->number > j->number)
				inversions++;
			j = j->next;
		}
		i = i->next;
	}
	return (inversions);
}

double	compute_disorder(t_stack *stack)
{
	int		size;
	int		inversions;
	double	max_inversions;

	size = stack_size(stack);
	if (size <= 1)
		return (0.0);
	inversions = count_inversions(stack);
	max_inversions = (double)(size * (size - 1)) / 2.0; //this is the most pairs we could have
	return ((double)inversions / max_inversions * 100.0);//need more study  and why we do *100
}
