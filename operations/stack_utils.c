/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborabi <aborabi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 17:14:17 by aborabi           #+#    #+#             */
/*   Updated: 2026/11/02 14:05:42 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	stack_size(t_stack *stk)
{
	size_t	counter;
	t_node	*temp;

	counter = 0;
	if (!stk)
		return (0);
	temp = stk->head;
	while (temp)
	{
		counter++;
		temp = temp->next;
	}
	return (counter);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i])
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

bool	add_node_back(t_stack *stack, int num)
{
	t_node	*temp;

	temp = lstnew_node(num);
	if (!temp)
		return (false);
	if (!stack->head)
	{
		stack->head = temp;
		stack->last = temp;
	}
	else
	{
		stack->last->next = temp;
		temp->prev = stack->last;
		stack->last = temp;
	}
	stack->size++;
	return (true);
}

void	delete_stack(t_stack *stk)
{
	t_node	*temp;

	if (!stk)
		return ;
	while (stk->head)
	{
		temp = stk->head;
		stk->head = stk->head->next;
		free(temp);
	}
	free(stk);
}
