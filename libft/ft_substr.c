/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 09:39:04 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/09/17 19:57:10 by Haitham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	stringlen;

	if (!s)
		return (NULL);
	stringlen = ft_strlen(s);
	if (start >= stringlen)
		len = 0;
	else if (stringlen - start < len)
		len = stringlen - start;
	i = 0;
	sub = malloc (len + 1);
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub [i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
