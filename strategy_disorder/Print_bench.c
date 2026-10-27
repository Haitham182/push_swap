#include "../push_swap.h"

static void	print_disorder(double disorder)
{
	int	int_part;
	int	dec_part;

	int_part = (int)(disorder * 100.0);
	dec_part = (int)((disorder * 10000.0) - (int_part * 100));
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

static void	print_strategy(t_strategy strategy)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (strategy == ADAPTIVE)
		ft_putstr_fd("Adaptive / O(n√n)\n", 2); // **** ARE you sure with adaptive you will print o(n)√n *******
	else if (strategy == MEDIUM)
		ft_putstr_fd("Medium / O(n√n)\n", 2);
	else if (strategy == COMPLEX) //changed radix to complex
		ft_putstr_fd("Complex / O(n log n)\n", 2);
	else
		ft_putstr_fd("Simple / O(n^2)\n", 2);
}

static void	print_bench_ops(t_bench bench)
{
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(bench.total, 2);
	ft_putstr_fd("\n[bench] sa: ", 2);
	ft_putnbr_fd(bench.sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(bench.sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(bench.ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(bench.pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(bench.pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(bench.ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(bench.rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(bench.rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(bench.rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(bench.rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(bench.rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench_summary(t_data *data)
{
	if (!data || !data->bench_enabled)
		return ;
	print_disorder(data->disorder);
	print_strategy(data->strategy);
	print_bench_ops(*data->bench);
}
