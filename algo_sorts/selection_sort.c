/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborabi <aborabi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 22:28:39 by aborabi           #+#    #+#             */
/*   Updated: 2026/10/20 22:48:25 by aborabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_min_index(t_stack *stack)
{
	t_node	*curr;
	int		min_val;
	int		min_idx;
	int		i;

	if (!stack || !stack->head)
		return (-1);
	curr = stack->head;
	min_val = curr->number;
	min_idx = 0;
	i = 0;
	while (curr)
	{
		if (curr->number < min_val)
		{
			min_val = curr->number;
			min_idx = i;
		}
		curr = curr->next;
		i++;
	}
	return (min_idx);
}

static void	bring_to_top_a(t_data *data, int target_idx)
{
	int	size;

	size = data->a->size;
	if (target_idx <= size / 2)
	{
		while (target_idx > 0)
		{
			op_ra(data->a, data);
			target_idx--;
		}
	}
	else
	{
		while (target_idx < size)
		{
			op_rra(data->a, data);
			target_idx++;
		}
	}
}

void	sort_simple(t_data *data)
{
	int	min_pos;

	if (data->a->size == 2)
	{
		op_sa(data->a, data);
		return ;
	}
	while (data->a->size > 3)
	{
		min_pos = find_min_index(data->a);
		if (min_pos < 0) //لانه الfind_min_index   ممكن ترجع -1
			return ;
		bring_to_top_a(data, min_pos);
		op_pb(data->a, data->b, data);
	}
	sort_three(data->a, data);
	while (data->b->size > 0)
		op_pa(data->a, data->b, data);
}
