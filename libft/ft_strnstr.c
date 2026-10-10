/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 08:00:41 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/09/18 23:50:10 by Haitham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *bigarr, const char *smallarr, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (smallarr[0] == '\0')
		return ((char *)bigarr);
	while (bigarr[i] && (i < size))
	{
		j = 0;
		while (smallarr[j] && (i + j < size) && bigarr[i + j] == smallarr[j])
		{
			j++;
		}
		if (smallarr[j] == '\0')
			return ((char *)&bigarr[i]);
		i++;
	}
	return (NULL);
}
