/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 09:26:08 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/09/12 09:37:19 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_lstadd_back(t_stack *stack, int num)
{
	t_node *temp;

	temp = lstnew_node(num);
	if (!temp)
		return (false);
	if (!stack->head)
	{
		stack->head = temp;
		stack->last = temp;
		return (true);
	}
	stack->last->next = temp;
	temp->prev = stack->last;
	stack->last = temp;
	return (true);
}
