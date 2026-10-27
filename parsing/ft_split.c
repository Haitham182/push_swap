/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 11:30:45 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/09/09 17:44:07 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	countwords(const char *p, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (p[i])
	{
		while (p[i] == c && p[i])
			i++;
		if (p[i])
			count++;
		while (p[i] != c && p[i])
			i++;
	}
	return (count);
}

static char	*allocate_word(const char *p, char c)
{
	int		i;
	char	*res;

	i = 0;
	while (p[i] && p[i] != c)
		i++;
	res = malloc(i + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (p[i] && p[i] != c)
	{
		res[i] = p[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static void	free__split(char **p, size_t j)
{
	while (j > 0)
		free(p[--j]);
	free(p);
}

static int	fill_split(char **p, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			p[j] = allocate_word(&s[i], c);
			if (!p[j])
			{
				free__split(p, j);
				return (0);
			}
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	p[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**p;

	p = malloc(sizeof(char *) * (countwords(s, c) + 1));
	if (!p)
		return (NULL);
	if (!fill_split(p, s, c))
		return (NULL);
	return (p);
}
