/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborabi <aborabi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 22:51:21 by aborabi           #+#    #+#             */
/*   Updated: 2026/10/15 14:18:59 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include "libft.h"

typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;

typedef struct s_node
{
	int				number;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		size;//whyyyyyyyyy?????
	t_node	*head;
	t_node	*last;
}	t_stack;

typedef struct s_bench
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	rb;
	int	ra;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;

	int	total;
}	t_bench;

typedef struct s_data
{
	e_strategy strategy;
	t_stack *a;
	t_stack *b;
	t_bench *bench;
	double	disorder;
	bool bench;
	
}	t_data;




#endif
