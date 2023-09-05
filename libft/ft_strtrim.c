/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 00:47:05 by mboukadi          #+#    #+#             */
/*   Updated: 2023/04/11 15:01:03 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	if (start == ft_strlen(s1))
	{
		str = ft_strdup("");
		return (str);
	}
	while (ft_strchr(set, s1[end - 1]) && end > start)
		end--;
	str = ft_substr(s1, start, end - start);
	return (str);
}

/*int main()
{
	char *str = "...HELLO WORLD...";
	char *set1 = "...";
	char *trim_str = ft_strtrim(str, set1);

	printf("Original string: \"%s\"\n", str);
	printf("Set of characters to remove: \"%s\"\n", set1);
	printf("Trim string: \"%s\"\n", trim_str);
	free(trim_str);
	return (0);
}*/
