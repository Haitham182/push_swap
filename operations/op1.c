/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 10:05:42 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/10/15 18:36:21 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	op_ra(t_data *data)
{
	if (!data->a || !data->a->head || !data->a->head->next)
		return ;
	rotate(data->a);
	write (1, "ra\n", 3);
	data->bench->ra++;
	data->bench->total++;

}

void	op_rb(t_data *data)
{
	if (!data->b || !data->b->head || !data->b->head->next)
		return ;
	rotate(data->b);
	write (1, "rb\n", 3);
	data->bench->rb++;
	data->bench->total++;
}

void	op_rr(t_data *data)
{
	int	c;
	c = 0;
	if (data->a && data->a->head && data->a->head->next)
	{
		c = 1;
		rotate(data->a);
	}
	if (data->b && data->b->head && data->b->head->next)
	{
		c = 1;
		rotate(data->b);
	}
	if (c)
	{
		write (1, "rr\n", 3);
		data->bench->rr++;
		data->bench->total++;
	}
}

void	op_ss(t_data *data)
{
	int	c;

	c = 0;
	if (data->a && data->a->head && data->a->head->next)
	{
		c = 1;
		swap(data->a);
	}
	if (data->b && data->b->head && data->b->head->next)
	{
		c = 1;
		swap(data->b);
	}
	if (c)
	{
		write (1, "ss\n", 3);
		data->bench->ss++;
		data->bench->total++;
	}
}

void	op_rrr(t_data *data)
{
	int	c;

	c = 0;
	if (data->a && data->a->head && data->a->head->next)
	{
		c = 1;
		reverse_rot(data->a);
	}
	if (data->b && data->b->head && data->b->head->next)
	{
		c = 1;
		reverse_rot(data->b);
	}
	if (c)
	{
		write (1, "rrr\n", 4);
		data->bench->rrr++;
		data->bench->total++;
	}
}
