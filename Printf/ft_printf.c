/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborabi <aborabi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 17:14:02 by aborabi           #+#    #+#             */
/*   Updated: 2026/09/30 17:38:53 by aborabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(va_list args, char specifier)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar_pf(va_arg(args, int));
	else if (specifier == 's')
		count += ft_putstr_pf(va_arg(args, char *));
	else if (specifier == 'p')
		count += ft_putptr_pf(va_arg(args, unsigned long long));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr_pf(va_arg(args, int));
	else if (specifier == 'u')
		count += ft_putuint_pf(va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		count += ft_puthex_pf(va_arg(args, unsigned int), specifier);
	else if (specifier == '%')
		count += ft_putchar_pf('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total_length;

	if (!format)
		return (-1);
	i = 0;
	total_length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (va_end(args), -1);
			total_length += ft_check_format(args, format[i]);
		}
		else
			total_length += ft_putchar_pf(format[i]);
		i++;
	}
	va_end(args);
	return (total_length);
}
