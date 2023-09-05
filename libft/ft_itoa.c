/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 01:05:16 by mboukadi          #+#    #+#             */
/*   Updated: 2023/07/10 00:09:45 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
	}
	if (!n)
		return (1);
	while (n)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	nbr;

	i = ft_count(n);
	str = malloc(i * sizeof(char) + 1);
	if (!str)
		return (NULL);
	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	str[i--] = '\0';
	if (n == 0)
		str[i] = '0';
	while (nbr)
	{
		str[i] = '0' + nbr % 10;
		nbr /= 10;
		i--;
	}
	return (str);
}
