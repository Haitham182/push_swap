/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 14:34:45 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/10/11 16:52:39 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rot(stack *stk)
{
	t_node	*temp;

	temp = stk->last;
	//to make the node before the last points to null i need a while big O(n)
	//so i need to change the t_node to be doubly list so it be big O(1)
}

