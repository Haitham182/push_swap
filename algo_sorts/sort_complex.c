/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 11:36:46 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/11/03 12:53:19 by aborabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	radix_pass(t_data *data, int size, int max_bits)
{
	int	i;
	int	j;

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

void	sort_complex(t_data *data)
{
	int		size;
	int		max_bits;
	t_node	*current;

	if (!data || !data->a)
		return ;
	size = stack_size(data->a);
	current = data->a->head;
	while (current)
	{
		current->index = get_index(data, current->number);
		current = current->next;
	}
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	radix_pass(data, size, max_bits);
}
