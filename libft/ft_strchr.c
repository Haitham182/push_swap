/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 10:55:57 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/09/18 23:16:36 by Haitham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *arr, int c)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		if ((unsigned char)arr[i] == ((unsigned char)c))
		{
			return ((char *)&arr[i]);
		}
		i++;
	}
	if ((unsigned char)arr[i] == ((unsigned char)c))
		return ((char *)&arr[i]);
	return (NULL);
}
