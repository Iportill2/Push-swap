/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:22:16 by iportill          #+#    #+#             */
/*   Updated: 2025/07/04 13:31:28 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHECKER_H
# define CHECKER_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>
# include "../libs/get_next_line/get_next_line.h"
# include "../../push_swap/libs/ft_printf/ft_printf.h"
# include "../../push_swap/libs/Libft/libft.h"

// Declaración de get_next_line en caso de que no se incluya correctamente
char	*get_next_line(int fd);
// Declaración de ft_printf
int		ft_printf(const char *format, ...);

# define INT_MAX 2147483647
# define INT_MIN -2147483647

typedef struct s_node
{
	int					value;
	struct s_node		*next;
	struct s_node		*prev;
	int					index;
	int					cost;
	int					cheapest;
	int					above_mid;
	struct s_node		*target_node;
}	t_node;

// Funciones del push_swap que necesita el checker
void	ft_init_stack(t_node **a, char **argv);
void	ft_free_stack(t_node **stack);
int		ft_stack_len(t_node *stack);
int		ft_stack_sorted(t_node *stack);
void	sa(t_node **a, int print);
void	sb(t_node **b, int print);
void	ss(t_node **a, t_node **b, int print);
void	pa(t_node **a, t_node **b, int print);
void	pb(t_node **a, t_node **b, int print);
void	ra(t_node **a, int print);
void	rb(t_node **b, int print);
void	rr(t_node **a, t_node **b, int print);
void	rra(t_node **a, int print);
void	rrb(t_node **b, int print);
void	rrr(t_node **a, t_node **b, int print);

// Función específica del checker
int		ft_check_digit(char **argv);

#endif
