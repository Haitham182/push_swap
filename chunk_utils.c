/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborabi <aborabi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 03:10:11 by aborabi           #+#    #+#             */
/*   Updated: 2026/10/21 03:17:07 by aborabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_stack *stack)
{
	t_node	*curr;
	int		max_val;
	int		max_idx;
	int		i;

	if (!stack || !stack->head)
		return (-1);
	curr = stack->head;
	max_val = curr->number;
	max_idx = 0;
	i = 0;
	while (curr)
	{
		if (curr->number > max_val)
		{
			max_val = curr->number;
			max_idx = i;
		}
		curr = curr->next;
		i++;
	}
	return (max_idx);
}

void	bring_to_top_b(t_data *data, int target_idx)
{
	int	size;

	if (!data || !data->b)
		return ;
	size = data->b->size;
	if (target_idx <= size / 2)
	{
		while (target_idx > 0)
		{
			op_rb(data->b, data);
			target_idx--;
		}
	}
	else
	{
		while (target_idx < size)
		{
			op_rrb(data->b, data);
			target_idx++;
		}
	}
}

int	get_chunk_size(int size)
{
	if (size <= 20)
		return (4);
	else if (size <= 100)
		return (15);
	else if (size <= 500)
		return (30);
	return (45);
}
