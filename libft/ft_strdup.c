/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 09:27:55 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/09/08 09:40:00 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *arr)
{
	int		i;
	char	*p;

	i = 0;
	while (arr[i])
		i++;
	p = malloc(i + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		p[i] = arr[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
