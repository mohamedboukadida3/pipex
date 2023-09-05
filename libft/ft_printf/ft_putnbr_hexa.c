/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:01:54 by mboukadi          #+#    #+#             */
/*   Updated: 2023/04/14 17:03:34 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_base_1(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || i < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_hexa(unsigned int nbr, char *base)
{
	int	error;
	int	i;

	i = 0;
	error = ft_check_base_1(base);
	if (error == 0)
	{
		if (nbr >= 16)
		{
			i = ft_putnbr_hexa(nbr / 16, base);
			ft_putnbr_hexa(nbr % 16, base);
		}
		else
			ft_putchar(base[nbr % 16]);
	}
	return (i + 1);
}
