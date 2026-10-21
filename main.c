#include "push_swap.h"

<<<<<<< HEAD
static void	free_data(t_data *data)
{
	if (!data)
		return ;
	delete_stack(data->a);
	delete_stack(data->b);
	free(data->bench);
	free(data);
=======
void	init_data(t_data *data)
{
	if (!data)
		return ;
	data->a = lstnew_stack();
	data->b = lstnew_stack();
	data->strategy = ADAPTIVE;
	data->disorder = 0.0;
	data->bench_mode = false;
	ft_bzero(&data->bench, sizeof(t_bench));
}

static void run_sort(t_data *data)
{
        if(!data || !data->a || is_sorted(data->a))
                return ;
	if(data->bench_enabled || data->strategy == ADAPTIVE)
		data->disorder = compute_disorder(data->a);
	if (data->a->size == 2)
		op_sa(data);
	else if(data->a->size <= 3)
                sort_three(data->a, data);
        else if(data->a->size <= 5)
                sort_five(data->a, data->b, data);
        else
		execute_strategy(data);
>>>>>>> 510ec69 (adding new files)
}

int	main(int argc, char **argv)
{
<<<<<<< HEAD
	t_data	*data;

	if (argc <= 1)
		return (0);
	data = calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	data->a = lstnew_stack();
	data->b = lstnew_stack();
	data->bench = calloc(1, sizeof(t_bench));
	if (!data->a || !data->b || !data->bench)
	{
		free_data(data);
		return (1);
	}
	
=======
	t_data	data;

	if (argc < 2)
		return (0);
	init_data(&data);
	if (!parse_args(argc, argv, &data))
	{
		free_data(&data);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	run_sort(&data);
	print_bench_summary(&data);
	free_data(&data);
	return (0);
>>>>>>> 510ec69 (adding new files)
}
