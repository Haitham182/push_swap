/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborabi <aborabi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 22:51:21 by aborabi           #+#    #+#             */
/*   Updated: 2026/10/28 12:39:00 by hmuqasqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>

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
	int				index; // ** why? **
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		size;
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
	t_strategy	strategy;
	t_stack		*a;
	t_stack		*b;
	t_bench		*bench;
	double		disorder;
	bool		bench_enabled;

}	t_data;

int			is_flag(char *arg, t_data *data);
bool		parse_args(int argc, char **argv, t_stack *stack_a, t_data *data);
void		free_split(char **p);
bool		has_duplicate(t_node *node, int num);
long		ft_atoi_ps(const char *str, int *error);
size_t		stack_size(t_stack *stk);
int			ft_strcmp(const char *str1, const char *str2);
bool		add_node_back(t_stack *stack, int num);
t_node		*lstnew_node(int number);
t_stack		*lstnew_stack(void);
void		delete_stack(t_stack *stk);
void		push(t_stack *dest, t_stack *source);
void		swap(t_stack *stk);
void		rotate(t_stack *stk);
void		reverse_rot(t_stack *stk);
long long	count_inversions(t_stack *stack);
double		compute_disorder(t_stack *stack);
void		execute_strategy(t_data *data);
void		sort_simple(t_data *data);
void		sort_medium(t_data *data);
void		sort_complex(t_data *data);
int			get_index(t_data *data, int number);
int			find_max_index(t_stack *stack);
void		bring_to_top_b(t_data *data, int target_idx);
int			get_chunk_size(int size);
void		print_bench_summary(t_data *data);
void		op_sa(t_data *data);
void		op_sb(t_data *data);
void		op_ss(t_data *data);
void		op_pa(t_data *data);
void		op_pb(t_data *data);
void		op_ra(t_data *data);
void		op_rb(t_data *data);
void		op_rr(t_data *data);
void		op_rra(t_data *data);
void		op_rrb(t_data *data);
void		op_rrr(t_data *data);
bool		is_sorted(t_stack *stack);
void		sort_three(t_data *data);
void		sort_five(t_data *data);
void		ft_bzero(void *p, size_t size);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
void		*ft_calloc(size_t num, size_t size);
char		**ft_split(char const *s, char c);
size_t		ft_strlen(const char *arr);

#endif
