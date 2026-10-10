/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 09:22:38 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/09/08 09:23:14 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t size)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)arr1;
	p2 = (unsigned char *)arr2;
	i = 0;
	while (p1[i] == p2[i] && size > i)
		i++;
	if (size == i)
		return (0);
	return (p1[i] - p2[i]);
}
