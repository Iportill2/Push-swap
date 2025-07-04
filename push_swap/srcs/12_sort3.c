/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:28:04 by iportill          #+#    #+#             */
/*   Updated: 2025/07/04 12:28:06 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_sort_three(t_node **stack)
{
	t_node	*max_node;

	max_node = ft_find_max(*stack, INT_MAX);
	if (max_node == *stack)
		ra(stack, 1);
	else if ((*stack)->next == max_node)
		rra(stack, 1);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, 1);
}
