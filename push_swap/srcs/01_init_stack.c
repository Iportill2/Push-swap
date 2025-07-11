/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iker <iker@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:25:56 by iportill          #+#    #+#             */
/*   Updated: 2025/07/04 14:21:44 by iker             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incs/push_swap.h"

void	ft_add_to_stack(t_node **stack, int nbr)
{
	t_node	*new;
	t_node	*last;

	if (stack == NULL)
		return ;
	new = malloc(sizeof(t_node));
	if (new == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		last = ft_last_node(*stack);
		last->next = new;
		new->prev = last;
	}
	new->value = nbr;
	new->next = NULL;
}

int	ft_init_stack(t_node **stack, char **argv)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	while (argv[i])
	{
		if (!ft_is_valid_number(argv[i]))
		{
			ft_printf("Error\n");
			if (stack && *stack)
				ft_free_stack(stack);
			return (0);
		}
		nbr = ft_atol(argv[i]);
		if ((nbr < INT_MIN || nbr > INT_MAX) || ft_repeated(*stack, nbr))
		{
			ft_printf("Error\n");
			if (stack && *stack)
				ft_free_stack(stack);
			return (0);
		}
		ft_add_to_stack(stack, nbr);
		i++;
	}
	return (1);
}

void	ft_set_index(t_node *stack)
{
	int	i;
	int	mid;

	mid = ft_stack_len(stack) / 2;
	i = 0;
	while (stack)
	{
		(stack)->index = i;
		if (i > mid)
			(stack)->above_mid = 0;
		else if (i == mid)
		{
			if (mid % 2 == 0)
				(stack)->above_mid = 0;
			else
				(stack)->above_mid = 1;
		}
		else
			(stack)->above_mid = 1;
		i++;
		(stack) = (stack)->next;
	}
	return ;
}
