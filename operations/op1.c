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

void	op_ra(t_stack *a, t_data *data)
{
	if (!a || !a->head || !a->head->next)
		return ;
	rotate(a);
	write (1, "ra\n", 3);
	data->bench->ra++;
	data->bench->total++;

}

void	op_rb(t_stack *b, t_data *data)
{
	if (!b || !b->head || !b->head->next)
		return ;
	rotate(b);
	write (1, "rb\n", 3);
	data->bench->rb++;
	data->bench->total++;
}

void	op_rr(t_stack *a, t_stack *b, t_data *data)
{
	int	c;
	c = 0;
	if (a && a->head && a->head->next)
	{
		c = 1;
		rotate(a);
	}
	if (b && b->head && b->head->next)
	{
		c = 1;
		rotate(b);
	}
	if (c)
	{
		write (1, "rr\n", 3);
		data->bench->rr++;
		data->bench->total++;
	}
}

void	op_ss(t_stack *a, t_stack *b, t_data *data)
{
	int	c;

	c = 0;
	if (a && a->head && a->head->next)
	{
		c = 1;
		swap(a);
	}
	if (b && b->head && b->head->next)
	{
		c = 1;
		swap(b);
	}
	if (c)
	{
		write (1, "ss\n", 3);
		data->bench->ss++;
		data->bench->total++;
	}
}

void	op_rrr(t_stack *a, t_stack *b, t_data *data)
{
	int	c;

	c = 0;
	if (a && a->head && a->head->next)
	{
		c = 1;
		reverse_rot(a);
	}
	if (b && b->head && b->head->next)
	{
		c = 1;
		reverse_rot(b);
	}
	if (c)
	{
		write (1, "rrr\n", 4);
		data->bench->rrr++;
		data->bench->total++;
	}
}
