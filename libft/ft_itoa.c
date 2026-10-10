/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 08:11:39 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/09/19 23:15:47 by Haitham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	d_count(int n)
{
	int	c;

	c = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*res;
	bool	sign;
	int		digitcount;
	long	num;

	num = n;
	sign = n < 0;
	digitcount = d_count(n);
	res = malloc(digitcount + sign + 1);
	if (!res)
		return (NULL);
	if (sign)
	{
		res[0] = '-';
	}
	if (sign)
		num = -num;
	res [digitcount + sign] = '\0';
	while (digitcount)
	{
		digitcount--;
		res[digitcount + sign] = (num % 10) + '0';
		num = num / 10;
	}
	return (res);
}
