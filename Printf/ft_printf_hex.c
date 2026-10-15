/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborabi <aborabi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:22:59 by aborabi           #+#    #+#             */
/*   Updated: 2026/09/30 17:23:44 by aborabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_pf(unsigned int num, char specifier)
{
	int		count;
	char	*hex_digits;

	count = 0;
	if (specifier == 'x')
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	if (num >= 16)
		count += ft_puthex_pf(num / 16, specifier);
	count += ft_putchar_pf(hex_digits[num % 16]);
	return (count);
}

static int	ft_putptr_hex(unsigned long long ptr)
{
	int		count;
	char	*hex_digits;

	count = 0;
	hex_digits = "0123456789abcdef";
	if (ptr >= 16)
		count += ft_putptr_hex(ptr / 16);
	count += ft_putchar_pf(hex_digits[ptr % 16]);
	return (count);
}

int	ft_putptr_pf(unsigned long long ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (ft_putstr_pf("(nil)"));
	count += ft_putstr_pf("0x");
	count += ft_putptr_hex(ptr);
	return (count);
}
