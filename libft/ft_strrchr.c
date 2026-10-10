/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 09:01:47 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/09/20 09:01:51 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *arr, int c)
{
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	if (arr[i] == c)
		return ((char *)&arr[i]);
	while (i > 0)
	{
		i--;
		if ((unsigned char)arr[i] == ((unsigned char)c))
			return ((char *)&arr[i]);
	}
	return (NULL);
}
