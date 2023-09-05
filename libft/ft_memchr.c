/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:43:52 by mboukadi          #+#    #+#             */
/*   Updated: 2023/04/10 15:54:03 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (0);
}
/*Recherche la première occurence d'une valeur typée int, 
mais interprétée en tant que char, dans un bloc de mémoire. 
Comme on traite un bloc de mémoire et non pas une chaîne de 
caractères AZT (à zéro terminal), nous devons aussi spécifier
à la fonction la taille du bloc de mémoire dans lequel réaliser 
la recherche.*/