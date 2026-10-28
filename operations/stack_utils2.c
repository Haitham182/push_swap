/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 12:08:45 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/10/11 16:49:46 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*lstnew_node(int number)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->number = number;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack	*lstnew_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->last = NULL;
	stack->size = 0;
	return (stack);
}

size_t	ft_strlen(const char *arr)
{
	size_t	i;

	i = 0;
	while (arr[i] != '\0')
		i++;
	return (i);
}
