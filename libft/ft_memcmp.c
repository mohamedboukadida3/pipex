/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:12:43 by mboukadi          #+#    #+#             */
/*   Updated: 2023/03/30 23:49:40 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *dest, const void *srcs, size_t size)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	s1 = (unsigned char *)dest;
	s2 = (unsigned char *)srcs;
	i = 0;
	while (i < size)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
/*int main()
{
	char	str[] = "hello";
	char	str1[] = "hello world";
	int		result;
	
	result = memcmp(str, str1, 8);
	if (result < 0)
	{
		printf("'%s' est plus petit que '%s'\n", str, str1);
	}
	else if (result > 0)
	{
		printf("'%s' est plus grand que '%s'\n", str, str1);
	}
	else
	{
		printf("'%s' est egale a '%s'\n", str, str1);
	}
	return (0);
}*/
/*Cette fonction permet de comparer le contenu 
de deux blocs de mémoire spécifiés par les deux 
premiers paramètres de la fonction. Le troisième 
paramètre, size, permet de spécifier le nombre 
d'octets sur lequel comparer les deux blocs. 
Les octets des deux blocs sont comparés deux à deux. 
Tant que les deux octets comparés sont égaux, 
la fonction passe aux deux suivants. Si les deux 
octets comparés sont différents, alors la fonction 
renvérra lequel des deux blocs est le plus petit en 
termes de contenu.*/