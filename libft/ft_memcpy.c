/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 07:52:36 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/09/07 07:52:37 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *arr1, const void *arr2, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((unsigned char *)arr1)[i] = ((unsigned char *)arr2)[i];
		i++;
	}
	return (arr1);
}
