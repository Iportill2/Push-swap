/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iker <iker@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:24:11 by iportill          #+#    #+#             */
/*   Updated: 2025/07/04 14:22:45 by iker             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/ft_printf/ft_printf.h"
# include "../libs/Libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node
{
	int					value;
	struct s_node		*next;
	struct s_node		*prev;
	int					index;
	int					cost;
	int					cheapest;
	struct s_node		*target;
	int					above_mid;
}				t_node;

//main
void		print_stack(t_node *stack, char *name);

//init_stack
void		ft_add_to_stack(t_node **stack, int nbr);
int			ft_init_stack(t_node **stack, char **argv);
void		ft_set_index(t_node *stack);

//utils_stack
t_node		*ft_last_node(t_node *stack);
int			ft_stack_len(t_node *stack);
int			ft_stack_sorted(t_node *stack);
t_node		*ft_find_min(t_node *stack, long min_value);
t_node		*ft_find_max(t_node *stack, long max_value);

//error
void		ft_free_stack(t_node **stack);
int			ft_repeated(t_node *stack, int nbr);
int			ft_is_valid_number(const char *str);

//sort_stack
void		ft_sort_stack(t_node **a, t_node **b);
static void	ft_check_top(t_node **a);

//short3
void		ft_sort_three(t_node **stack);

//swap
static void	ft_swap_stack(t_node **stack);
void		sa(t_node **a, int mode);
void		sb(t_node **b, int mode);
void		ss(t_node **a, t_node **b, int mode);

//rotate
static void	ft_rotate_stack(t_node **stack);
void		ra(t_node **a, int mode);
void		rb(t_node **b, int mode);
void		rr(t_node **a, t_node **b, int mode);

//reverse rotate
static void	ft_reverse_rotate_stack(t_node **stack);
void		rra(t_node **a, int mode);
void		rrb(t_node **b, int mode);
void		rrr(t_node **a, t_node **b, int mode);

//push a node from a stack to another
static void	ft_push_stack(t_node **src, t_node **dst);
void		pa(t_node **a, t_node **b, int mode);
void		pb(t_node **a, t_node **b, int mode);

//init the stack a
static void	ft_set_target_a(t_node *a, t_node *b);
static void	ft_get_cost_a(t_node *a, t_node *b);
static void	ft_set_cheapest_a(t_node *a);
void		ft_init_stack_a(t_node *a, t_node *b);

//move stack a
static void	ft_rotate_both(t_node **a, t_node **b, t_node *cheap);
static void	ft_rev_rotate_both(t_node **a, t_node **b, t_node *cheap);
static void	ft_check_push(t_node **stack, t_node *push_node, int stack_name);
void		ft_move_stack_a(t_node **a, t_node **b);

//init the stack b
static void	ft_set_target_b(t_node *a, t_node *b);
void		ft_init_stack_b(t_node *a, t_node *b);

//move stack b
static void	ft_check_push(t_node **stack, t_node *push_node, int stack_name);
void		ft_move_stack_b(t_node **a, t_node **b);
#endif