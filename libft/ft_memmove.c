/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 07:52:42 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/09/07 07:52:43 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t size)
{
	size_t	i;

	if (dest == source)
		return (dest);
	if (dest < source)
	{
		i = 0;
		while (i < size)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)source)[i];
			i++;
		}
	}
	else
	{
		i = size;
		while (i > 0)
		{
			i--;
			((unsigned char *)dest)[i] = ((unsigned char *)source)[i];
		}
	}
	return (dest);
}
