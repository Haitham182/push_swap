/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborabi <aborabi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 23:26:38 by aborabi           #+#    #+#             */
/*   Updated: 2026/10/14 00:41:41 by Haitham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

bool	has_duplicate(t_node *node, int num)//why not stack instead of node??
{
	while (node)
	{
		if (node->number == num)
			return (true);
		node = node->next;
	}
	return (false);
}

static int	skip_whitespaces_and_sign(const char *str, int *i, int *sign)
{
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	if (!str[*i]) //is this to make sure there is a number after the sign?
		return (0);
	return (1);
}

long	ft_atoi_ps(const char *str, int *error)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (!skip_whitespaces_and_sign(str, &i, &sign))
		return (*error = 1, 0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (*error = 1, 0);
		res = res * 10 + (str[i] - '0');
		if ((sign == 1 && res > 2147483647)
			|| (sign == -1 && res > 2147483648LL))//why ll to cast the number to long long // still why
			return (*error = 1, 0);
		i++;
	}
	return (res * sign);
}
