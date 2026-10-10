/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 13:02:51 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/09/08 09:20:13 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *p, int c, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (((const unsigned char *)p)[i] == (unsigned char)c)
			return ((unsigned char *)p + i);
		i++;
	}
	return (NULL);
}
