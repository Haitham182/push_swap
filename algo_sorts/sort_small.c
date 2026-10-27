#include "../push_swap.h"

bool	is_sorted(t_stack *stack)
{
	t_node	*curr;

	if (!stack || !stack->head)
		return (true);
	curr = stack->head;
	while (curr && curr->next)
	{
		if (curr->number > curr->next->number)
			return (false);
		curr = curr->next;
	}
	return (true);
}

void	sort_three(t_data *data)
{
	int	top;
	int	mid;
	int	bot;

	if (is_sorted(data->a))
		return ;
	top = data->a->head->number;
	mid = data->a->head->next->number;
	bot = data->a->head->next->next->number;
	if (top > mid && mid < bot && top < bot) // 2 1 3
		op_sa(data);
	else if (top > mid && mid > bot)// 3 2 1 مرتبات عكسي 
	{
		op_sa(data);
		op_rra(data);
	}
	else if (top > mid && mid < bot && top > bot)  // 3 1 2
		op_ra(data);
	else if (top < mid && mid > bot && top < bot) // 1 3 2 
	{
		op_sa(data);
		op_ra(data);
	}
	else if (top < mid && mid > bot && top > bot) // 2 3 1
		op_rra(data);
}

static int	find_min_pos(t_stack *a)
{
	t_node	*curr;
	int		min_val;
	int		min_pos;
	int		i;

	curr = a->head;
	min_val = curr->number;
	min_pos = 0;
	i = 0;
	while (curr)
	{
		if (curr->number < min_val)
		{
			min_val = curr->number;
			min_pos = i;
		}
		curr = curr->next;
		i++;
	}
	return (min_pos);
}

void	sort_five(t_data *data)
{
	int	pos;

	while (data->a->size > 3)
	{
		pos = find_min_pos(data->a);
		if (pos <= data->a->size / 2)
		{
			while (pos-- > 0)
				op_ra(data);
		}
		else
		{
			while (pos++ < data->a->size)
				op_rra(data);
		}
		op_pb(data);
	}
	sort_three(data);
	while (data->b->size > 0)
		op_pa(data);
}