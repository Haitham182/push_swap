/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 11:36:46 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/11/02 14:09:39 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_complex(t_data *data)
{
	int		size;
	int		max_bits;
	int		i;
	int		j;
	t_node	*current;

	if (!data || !data->a)
		return ;
	size = stack_size(data->a);
	current = data->a->head;
	while (current) //** added this to inialize index
	{
		current->index = get_index(data, current->number);
		current = current->next;
	}
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if ((data->a->head->index >> i) & 1)
				op_ra(data);
			else
				op_pb(data);
		}
		while (data->b && data->b->size > 0)
			op_pa(data);
	}
}
