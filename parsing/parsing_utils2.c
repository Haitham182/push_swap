/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 20:03:16 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/10/27 20:03:23 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	ft_bzero(void *p, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((unsigned char *)p)[i] = 0;
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write (fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write (fd, s, len);
}

void	*ft_calloc(size_t num, size_t size)
{
	void			*p;
	unsigned char	*c;
	size_t			i;
	size_t			total;

	i = 0;
	total = num * size;
	if (size != 0 && total / size != num)
		return (NULL);
	p = malloc(num * size);
	if (!p)
		return (NULL);
	c = (unsigned char *)p;
	while (i < num * size)
	{
		c[i] = 0;
		i++;
	}
	return (p);
}
