/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 08:50:42 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/09/09 17:43:33 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *arr)
{
	int	i;
	int	n;
	int	sign;

	sign = 1;
	n = 0;
	i = 0;
	while (arr[i] == ' ' || (arr[i] >= 9 && arr[i] <= 13))
		i++;
	if (arr[i] == '-' || arr[i] == '+')
	{
		if (arr[i] == '-')
			sign = -1;
		i++;
	}
	while (arr[i] >= '0' && arr[i] <= '9')
	{
		n = n * 10 + (arr[i] - '0');
		i++;
	}
	return (n * sign);
}
