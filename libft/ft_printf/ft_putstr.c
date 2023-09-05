/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 17:43:17 by mboukadi          #+#    #+#             */
/*   Updated: 2023/04/13 18:18:52 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s != NULL)
		while (s[i])
			write(1, &s[i++], 1);
	else
	{
		ft_putstr("(null)");
		return (6);
	}
	return (i);
}
