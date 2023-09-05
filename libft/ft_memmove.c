/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:52:53 by mboukadi          #+#    #+#             */
/*   Updated: 2023/04/06 18:08:22 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;

	if (!dst && !src)
		return (0);
	if (dst > src)
	{
		while (len > 0)
		{
			((char *)dst)[len - 1] = ((char *)src)[len - 1];
			len--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}
/*int	main(int ac, char **av)
{
    char	str[] = "Start stop";
    ft_memmove(str, str + 2, 3 * sizeof(char));
    printf("%s\n", str);
    return (0);
}*/

/*Si l'adresse de destination dst est supérieure à l'adresse source src,
 cela signifie que les données se chevauchent et qu'il faut copier les 
 données de droite à gauche pour éviter les conflits. 
 La fonction parcourt donc les données à copier de droite 
 à gauche et les copie dans l'ordre inverse.*/

/*Si les adresses dst et src ne se chevauchent pas, les données 
 peuvent être copiées normalement de gauche à droite. 
 La fonction parcourt les données à copier de gauche à droite 
 et les copie dans l'ordre.*/
