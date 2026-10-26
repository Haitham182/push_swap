/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborabi <aborabi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 03:16:04 by aborabi           #+#    #+#             */
/*   Updated: 2026/10/21 03:16:31 by aborabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_smaller(t_stack *stack, int number) // بدور على عدد الارقام اللي اصغر من رقم معين يعني برجع كم رقم اصغر منه	
{
	t_node	*curr;
	int		count;

	count = 0;
	if (!stack)
		return (0);
	curr = stack->head;
	while (curr)
	{
		if (curr->number < number)
			count++;
		curr = curr->next;
	}
	return (count);
}

int	get_index(t_data *data, int number) //   معًا. لأن الأرقام تنتقل بين الستاكين، وعد الاثنين يحافظ على رتبة الرقم نفسها بعد نقله a وb  بتعد الأرقام الأصغر من الرقم في الستاكين 
{
	if (!data)
		return (0);
	return (count_smaller(data->a, number)
		+ count_smaller(data->b, number));
}
