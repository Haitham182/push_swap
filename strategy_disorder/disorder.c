/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 11:54:04 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/10/28 11:54:06 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long long	count_inversions(t_stack *stack)
{
	long long	inversions;
	t_node		*i;
	t_node		*j;

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
	long long	size;
	long long	total_pairs;
	long long	inversions;

	if (!stack || stack->size <= 1)
		return (0.0);
	size = stack->size;
	total_pairs = size * (size - 1) / 2;
	inversions = count_inversions(stack);
	return ((double)inversions / (double)total_pairs);
}
