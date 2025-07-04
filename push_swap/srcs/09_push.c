/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:27:28 by iportill          #+#    #+#             */
/*   Updated: 2025/07/04 12:27:33 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

//Sends the first node fo src to the first position of dst
static void	ft_push_stack(t_node **src, t_node **dst)
{
	t_node	*first_src;
	t_node	*first_dst;

	if (*src == NULL)
		return ;
	first_src = *src;
	first_dst = *dst;
	*src = first_src->next;
	if (first_src->next)
		first_src->next->prev = NULL;
	first_src->next = first_dst;
	first_src->prev = NULL;
	if (first_dst)
		first_dst->prev = first_src;
	*dst = first_src;
}

void	pa(t_node **a, t_node **b, int mode)
{
	ft_push_stack(b, a);
	if (mode == 1)
		ft_printf("pa\n");
}

void	pb(t_node **a, t_node **b, int mode)
{
	ft_push_stack(a, b);
	if (mode == 1)
		ft_printf("pb\n");
}
