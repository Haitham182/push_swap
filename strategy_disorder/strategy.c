/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 11:54:16 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/10/28 12:05:02 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	execute_strategy(t_data *data)
{
	t_strategy	effective_strategy;

	effective_strategy = data->strategy;
	if (effective_strategy == ADAPTIVE)
	{
		if (data->disorder < 0.2)
			effective_strategy = SIMPLE;
		else if (data->disorder < 0.5)
			effective_strategy = MEDIUM;
		else
			effective_strategy = COMPLEX;
	}
	if (effective_strategy == SIMPLE)
	{
		if (data->a->size == 2) // to handle two numbers in --simple
			op_sa(data);
		else if (data->a->size <= 3)
			sort_three(data);
		else
			sort_simple(data);
	}
	else if (effective_strategy == MEDIUM)
		sort_medium(data);
	else if (effective_strategy == COMPLEX)
		sort_complex(data);
}
