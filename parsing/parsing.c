/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborabi <aborabi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 23:24:39 by aborabi           #+#    #+#             */
/*   Updated: 2026/10/28 11:43:22 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_flag(char *arg, t_data *data)
{
	if (ft_strcmp(arg, "--simple") == 0)
		return (data->strategy = SIMPLE, 1);
	else if (ft_strcmp(arg, "--medium") == 0)
		return (data->strategy = MEDIUM, 1);
	else if (ft_strcmp(arg, "--complex") == 0)
		return (data->strategy = COMPLEX, 1);
	else if (ft_strcmp(arg, "--adaptive") == 0)
		return (data->strategy = ADAPTIVE, 1);
	if (ft_strcmp(arg, "--bench") == 0) //  ****if there is bench it will calculate disorder ******
		return (data->bench_enabled = true, 1);
	return (0);
}

static bool	parse_token(char *token, t_stack *stack_a)
{
	int		error;
	long	num;

	error = 0;
	num = ft_atoi_ps(token, &error);
	if (error || has_duplicate(stack_a->head, (int)num)) //we cast bec mybe the num is bigger than the biggest int
		return (false);
	if (!add_node_back(stack_a, (int)num))
		return (false);
	return (true);
}

static bool	process_arg(char *arg, t_stack *stack_a)
{
	char	**split;
	int		j;

	split = ft_split(arg, ' ');
	if (!split || !split[0])
		return (free_split(split), false);
	j = 0;
	while (split[j])
	{
		if (!parse_token(split[j], stack_a))
			return (free_split(split), false);// if we do "15 aa 16" it will be handle and return false 
		j++;
	}
	free_split(split);
	return (true);
}

bool	parse_args(int argc, char **argv, t_stack *stack_a, t_data *data)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_flag(argv[i], data))
		{
			i++;
			continue ;
		}
		if (!process_arg(argv[i], stack_a))
			return (false);
		i++;
	}
	return (true);
}
