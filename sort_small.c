#include "push_swap.h"

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

void	sort_three(t_stack *a, t_data *data)
{
	int	top;
	int	mid;
	int	bot;

	if (is_sorted(a))
		return ;
	top = a->head->number;
	mid = a->head->next->number;
	bot = a->head->next->next->number;
	if (top > mid && mid < bot && top < bot) // 2 1 3
		op_sa(a, data);
	else if (top > mid && mid > bot)// 3 2 1 مرتبات عكسي 
	{
		op_sa(a, data);
		op_rra(a, data);
	}
	else if (top > mid && mid < bot && top > bot)  // 3 1 2
		op_ra(a, data);
	else if (top < mid && mid > bot && top < bot) // 1 3 2 
	{
		op_sa(a, data);
		op_ra(a, data);
	}
	else if (top < mid && mid > bot && top > bot) // 2 3 1
		op_rra(a, data);
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

void	sort_five(t_stack *a, t_stack *b, t_data *data)
{
	int	pos;

	while (a->size > 3)
	{
		pos = find_min_pos(a);
		if (pos <= a->size / 2)
		{
			while (pos-- > 0)
				op_ra(a, data);
		}
		else
		{
			while (pos++ < a->size)
				op_rra(a, data);
		}
		op_pb(a, b, data);
	}
	sort_three(a, data);
	while (b->size > 0)
		op_pa(a, b, data);
}