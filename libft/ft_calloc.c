/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 10:35:59 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/09/17 19:41:58 by Haitham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void			*p;
	unsigned char	*c;
	size_t			i;
	size_t			total;

	i = 0;
	total = num * size;
	if (size != 0 && total / size != num)
		return (NULL);
	p = malloc(num * size);
	if (!p)
		return (NULL);
	c = (unsigned char *)p;
	while (i < num * size)
	{
		c[i] = 0;
		i++;
	}
	return (p);
}
