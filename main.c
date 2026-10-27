#include "push_swap.h"

static void	free_data(t_data *data)
{
	if (!data)
		return ;
	delete_stack(data->a);
	delete_stack(data->b);
	free(data->bench);
}

static int	init_data(t_data *data)
{
	ft_bzero(data, sizeof(*data));
	data->a = lstnew_stack();
	data->b = lstnew_stack();
	data->bench = ft_calloc(1, sizeof(t_bench));
	data->strategy = ADAPTIVE;
	data->disorder = 0.0;
	data->bench_enabled = false;
	if (!data->a || !data->b || !data->bench)
		return (0);
	return (1);
}

static void	run_sort(t_data *data)
{
	if (!data || !data->a || is_sorted(data->a))
		return ;
	if (data->bench_enabled || data->strategy == ADAPTIVE)
		data->disorder = compute_disorder(data->a);
	if (data->strategy != ADAPTIVE)
	{
		execute_strategy(data);
		return ;
	}
	if (data->a->size == 2)
		op_sa(data);
	else if (data->a->size <= 3)
		sort_three(data);
	else if (data->a->size <= 5)
		sort_five(data);
	else
		execute_strategy(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0);
	if (!init_data(&data))
	{
		free_data(&data);
		return (1);
	}
	if (!parse_args(argc, argv, data.a, &data))
	{
		free_data(&data);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	run_sort(&data);
	print_bench_summary(&data);
	free_data(&data);
	return (0);
}
