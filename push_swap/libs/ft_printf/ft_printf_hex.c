/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:30:00 by iportill          #+#    #+#             */
/*   Updated: 2025/07/04 13:12:42 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_to_base(int num, char *base, int *length)
{
	int	len;

	if (num < 0)
	{
		num = -num;
		ft_printchar('-', length);
	}
	len = ft_len(base);
	if (num >= len)
	{
		ft_to_base(num / len, base, length);
		ft_to_base(num % len, base, length);
	}
	else
		ft_printchar(base[num], length);
}
