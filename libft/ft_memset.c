/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:37:40 by mboukadi          #+#    #+#             */
/*   Updated: 2023/04/06 18:13:59 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;

	str = b;
	while (len)
	{
		*str = (unsigned char)c;
		str++;
		len--;
	}
	return (b);
}
/* DESCRIPTION : La fonction memset() remplit les n premiers octets de la zone
 mémoire pointée par b avec l'octet c.
 VALEUR RENVOYEE : La fonction memset() renvoie un pointeur sur la zone
 mémoire b.

On définit une variable str qui est un pointeur vers un caractère. 
On initialise cette variable à la valeur du pointeur b,
qui représente l'adresse du bloc de mémoire à modifier.

Cela permet de parcourir le bloc de mémoire en tant que
chaîne de caractères.la fonction parcourt le bloc de mémoire 
à modifier, caractère par caractère, en utilisant la variable str.
À chaque itération de la boucle,la fonction met la valeur c
dans la case mémoire pointée par str, en convertissant c en
unsigned char pour éviter les problèmes de signe.

Ensuite, la fonction incrémente str pour passer à la case mémoire 
suivante et décrémente len pour réduire le nombre de cases mémoire 
restantes à modifier.
*/