/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:00:41 by mboukadi          #+#    #+#             */
/*   Updated: 2023/07/10 00:10:35 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_counta(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_putunbr(unsigned int n)
{
	int	i;

	i = ft_counta(n);
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (n > 9)
	{
		ft_putunbr(n / 10);
		n %= 10;
	}
	ft_putchar(n + '0');
	return (i);
}
