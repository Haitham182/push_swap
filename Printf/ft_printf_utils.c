/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborabi <aborabi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:20:12 by aborabi           #+#    #+#             */
/*   Updated: 2026/09/30 17:22:28 by aborabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_pf(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_pf(char *s)
{
	int	i;

	if (!s)
		return (ft_putstr_pf("(null)"));
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_pf(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr_pf("-2147483648"));
	if (n < 0)
	{
		count += ft_putchar_pf('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr_pf(n / 10);
	count += ft_putchar_pf((n % 10) + '0');
	return (count);
}

int	ft_putuint_pf(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putuint_pf(n / 10);
	count += ft_putchar_pf((n % 10) + '0');
	return (count);
}
