/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 07:53:03 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/09/18 22:46:01 by Haitham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *source, size_t size)
{
	size_t	destlen;
	size_t	sourcelen;
	size_t	i;

	destlen = 0;
	sourcelen = 0;
	i = 0;
	while (destlen < size && dest[destlen] != '\0')
		destlen++;
	while (source[sourcelen] != '\0')
		sourcelen++;
	if (destlen == size)
		return (size + sourcelen);
	while (source[i] != '\0' && destlen + i + 1 < size)
	{
		dest[destlen + i] = source[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (destlen + sourcelen);
}
