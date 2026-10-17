#include "push_swap.h"

static void	free_data(t_data *data)
{
	if (!data)
		return ;
	delete_stack(data->a);
	delete_stack(data->b);
	free(data->bench);
	free(data);
}

int	main(int argc, char **argv)
{
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
	
}
