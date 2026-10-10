/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 07:53:12 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/09/07 07:53:18 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *source, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (source[i] != '\0' && i < size - 1)
		{
			dest[i] = source[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (source[i] != '\0')
		i++;
	return (i);
}
