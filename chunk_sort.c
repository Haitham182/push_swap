/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborabi <aborabi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 03:13:56 by aborabi           #+#    #+#             */
/*   Updated: 2026/10/21 03:15:38 by aborabi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunks_to_b(t_data *data, int chunk_size) // بوخد الداتا وعدد الشنكات
{
	int	i;
	int	index;

	i = 0; // i: اللي هو كم رقم نقلنا لستاك ب
	while (data->a->size > 0)
	{
		index = get_index(data, data->a->head->number); // بخزن كم رقم اصغر من الرقم هاض
		if (index <= i) //B وبندور B الى A يعني الرقم ترتيبه ضمن الأرقام اللي وصل دورها بالفعل. وقتها بتنقله من
		{
			op_pb(data->a, data->b, data);
			op_rb(data->b, data);
			i++;
		}
		else if (index <= i + chunk_size) // بدون ما تدور بi لكنه لسا داخل حدود الشنك الحالي يعني بتنقله من أ الى ب وبتزيد الi يعني الرقم اكبر من
		{
			op_pb(data->a, data->b, data);
			i++;
		}
		else //**** اذا كان خارج حدود الشنك هون انا بدور* أ *عشان افحص اللي بعده*****
			op_ra(data->a, data);
	}
}

static void	push_back_to_a(t_data *data)
{
	int	max_idx;

	while (data->b->size > 0)
	{
		max_idx = find_max_index(data->b);
		bring_to_top_b(data, max_idx);
		op_pa(data->a, data->b, data);
	}
}

void	sort_chunk(t_data *data)
{
	int	chunk_size;

	if (!data || !data->a)
		return ;
	chunk_size = get_chunk_size(data->a->size);
	push_chunks_to_b(data, chunk_size);
	push_back_to_a(data);
}
