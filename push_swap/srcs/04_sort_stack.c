/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:26:25 by iportill          #+#    #+#             */
/*   Updated: 2025/07/04 12:26:28 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incs/push_swap.h"

static void	ft_check_top(t_node **a)
{
	t_node	*min;

	min = ft_find_min(*a, INT_MIN);
	while ((*a)->value != min->value)
	{
		if (min->above_mid == 1)
			ra(a, 1);
		else
			rra(a, 1);
	}
}

void	ft_sort_stack(t_node **a, t_node **b)
{
	int	len;

	len = ft_stack_len(*a);
	if (len-- > 3 && !ft_stack_sorted(*a))
		pb(a, b, 1);
	if (len > 4 && !ft_stack_sorted(*a))
	{
		pb(a, b, 1);
		pb(a, b, 1);
	}
	len = ft_stack_len(*a);
	while (len > 3 && !ft_stack_sorted(*a))
	{
		ft_init_stack_a(*a, *b);
		ft_move_stack_a(a, b);
		len = ft_stack_len(*a);
	}
	ft_sort_three(a);
	while (*b)
	{
		ft_init_stack_b(*a, *b);
		ft_move_stack_b(a, b);
	}
	ft_set_index(*a);
	ft_check_top(a);
}
