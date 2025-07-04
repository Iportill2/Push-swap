/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:28:11 by iportill          #+#    #+#             */
/*   Updated: 2025/07/04 12:28:14 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

//Swaps the first two nodes of the stack
static void	ft_swap_stack(t_node **stack)
{
	int	len;

	len = ft_stack_len(*stack);
	if (NULL == *stack || NULL == stack || 1 == len)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_node **a, int mode)
{
	ft_swap_stack(a);
	if (mode == 1)
		ft_printf("sa\n");
}

void	sb(t_node **b, int mode)
{
	ft_swap_stack(b);
	if (mode == 1)
		ft_printf("sb\n");
}

void	ss(t_node **a, t_node **b, int mode)
{
	ft_swap_stack(a);
	ft_swap_stack(b);
	if (mode == 1)
		ft_printf("ss\n");
}
