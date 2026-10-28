/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmuqasqu <hmuqasqu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 11:54:10 by hmuqasqu          #+#    #+#             */
/*   Updated: 2026/10/28 12:01:41 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	print_disorder(t_data *data)
{
	int	int_part;
	int	dec_part;

	int_part = (int)(data->disorder * 100.0);
	dec_part = (int)((data->disorder * 10000.0) - (int_part * 100));
	if (dec_part < 0)
		dec_part = -dec_part;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(int_part, 2);
	ft_putstr_fd(".", 2);
	if (dec_part < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(dec_part, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_strategy(t_data *data)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (data->strategy == ADAPTIVE)
	{
		ft_putstr_fd("Adaptive / ", 2);
		if (data->disorder < 0.2)
			ft_putstr_fd("O(n^2)\n", 2);
		else if (data->disorder > 0.5)
			ft_putstr_fd("O(n√n)\n", 2);
		else
			ft_putstr_fd("O(n log n)\n", 2);
	}
	else if (data->strategy == MEDIUM)
		ft_putstr_fd("Medium / O(n√n)\n", 2);
	else if (data->strategy == COMPLEX)
		ft_putstr_fd("Complex / O(n log n)\n", 2);
	else
		ft_putstr_fd("Simple / O(n^2)\n", 2);
}

static void	print_bench_ops(t_data *data)
{
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(data->bench->total, 2);
	ft_putstr_fd("\n[bench] sa: ", 2);
	ft_putnbr_fd(data->bench->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(data->bench->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(data->bench->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(data->bench->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(data->bench->pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(data->bench->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(data->bench->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(data->bench->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(data->bench->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(data->bench->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(data->bench->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench_summary(t_data *data)
{
	if (!data || !data->bench_enabled)
		return ;
	print_disorder(data);
	print_strategy(data);
	print_bench_ops(data);
}
