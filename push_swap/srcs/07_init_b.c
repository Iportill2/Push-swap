/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_init_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:27:05 by iportill          #+#    #+#             */
/*   Updated: 2025/07/04 12:27:08 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incs/push_swap.h"

static void	ft_set_target_b(t_node *a, t_node *b)
{
	while (b)
	{
		b->target = ft_find_min(a, b->value);
		if (b->target == NULL)
			b->target = ft_find_min(a, INT_MIN);
		b = b->next;
	}
}

void	ft_init_stack_b(t_node *a, t_node *b)
{
	ft_set_index(a);
	ft_set_index(b);
	ft_set_target_b(a, b);
}
