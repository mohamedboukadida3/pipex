/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:36:21 by mboukadi          #+#    #+#             */
/*   Updated: 2023/04/08 15:16:32 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*lst_nvelle;
	t_list	*tmp;

	if (!f || !lst)
		return (0);
	lst_nvelle = 0;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (!tmp)
		{
			ft_lstclear(&tmp, (*del));
			return (0);
		}
		ft_lstadd_back(&lst_nvelle, tmp);
		lst = lst->next;
	}
	return (lst_nvelle);
}
/*La fonction ft_lstmap crée une nouvelle liste chaînée en
appliquant la fonction f à chaque élément de la liste chaînée
d'entrée lst. Si une allocation de mémoire échoue,
la fonction libère la mémoire allouée précédemment et
renvoie 0. Sinon, la fonction renvoie un pointeur vers
la nouvelle liste chaînée.*/