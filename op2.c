/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 10:36:02 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/10/14 20:18:30 by Haitham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rra(t_stack *a)
{
	if (!a || !a->head || !a->head->next)
		return ;
	reverse_rot(a);
	write (1, "rra\n", 4);
}

void	op_rrb(t_stack *b)
{
	if (!b || !b->head || !b->head->next)
		return ;
	reverse_rot(b);
	write (1, "rrb\n", 4);
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
