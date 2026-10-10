/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 10:03:52 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/09/12 10:17:04 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*current;

	head = *lst;
	current = head;
	if (head == NULL)
		return ;
	while (head->next != NULL)
	{
		head = head->next;
		del(current->content);
		free (current);
		current = head;
	}
	del(head->content);
	free (head);
	head = NULL;
	current = NULL;
	*lst = NULL;
}
