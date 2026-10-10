/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 11:01:59 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/09/09 11:08:15 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	inset(char c, char const *set)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (c == set[j])
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*res;
	int		index;
	int		backindex;

	index = 0;
	backindex = ft_strlen(s1) - 1;
	while (s1[index] && inset(s1[index], set))
		index++;
	while (backindex >= index && inset(s1[backindex], set))
		backindex--;
	res = malloc(backindex - index + 2);
	if (!res)
		return (NULL);
	i = 0;
	while (index <= backindex)
	{
		res[i] = s1[index];
		i++;
		index++;
	}
	res[i] = '\0';
	return (res);
}
