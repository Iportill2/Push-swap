/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iker <iker@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:25:46 by iportill          #+#    #+#             */
/*   Updated: 2025/07/04 14:21:44 by iker             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../incs/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		len;

	a = NULL;
	b = NULL;
	if (1 == argc || (2 == argc && !argv[1][0]))
		return (0);
	else if (2 == argc)
	{
		if (!ft_init_stack(&a, ft_split(argv[1], ' ')))
			return (1);
	}
	else
	{
		if (!ft_init_stack(&a, argv + 1))
			return (1);
	}
	len = ft_stack_len(a);
	if (ft_stack_sorted(a) == 0)
	{
		if (len <= 3)
			ft_sort_three(&a);
		else
			ft_sort_stack(&a, &b);
	}
	ft_free_stack(&a);
}
