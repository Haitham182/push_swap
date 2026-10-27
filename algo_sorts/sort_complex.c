#include "../push_swap.h"

void	sort_complex(t_data *data)
{
	int		size;
	int		max_bits;
	int		i;
	int		j;

	if (!data || !data->a)
		return ;
	size = stack_size(data->a);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if ((data->a->head->index >> i) & 1)
				op_ra(data);
			else
				op_pb(data);
		}
		while (data->b && data->b->size > 0)
			op_pa(data);
	}
}