/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iportill <iportill@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:30:00 by iportill          #+#    #+#             */
/*   Updated: 2025/07/04 13:12:42 by iportill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stddef.h>

void	ft_printchar(int c, int *length)
{
	if (*length == -1)
		return ;
	if (write(1, &c, 1) == -1)
	{
		*length = -1;
		return ;
	}
	*length += 1;
}

void	ft_printstring(char *str, int *length)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_printstring("(null)", length);
		return ;
	}
	while (str[i])
	{
		ft_printchar(str[i], length);
		i++;
	}
}

void	ft_printu(unsigned int nb, int *len)
{
	if (nb >= 10)
	{
		ft_printu(nb / 10, len);
		ft_printu(nb % 10, len);
	}
	else
		ft_printchar(nb + 48, len);
}

void	ft_printnbr(int nb, int *len)
{
	if (nb == -2147483648)
		ft_printstring("-2147483648", len);
	else if (nb < 0)
	{
		ft_printchar('-', len);
		ft_printnbr(-nb, len);
	}
	else if (nb >= 10)
	{
		ft_printnbr(nb / 10, len);
		ft_printnbr(nb % 10, len);
	}
	else
		ft_printchar(nb + 48, len);
}
