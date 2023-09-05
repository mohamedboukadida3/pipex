/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukadi <mboukadi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:58:53 by mboukadi          #+#    #+#             */
/*   Updated: 2023/04/05 17:53:37 by mboukadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(const char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			j++;
			while (str[i] && str[i] != c)
				i++;
			continue ;
		}
		i++;
	}
	return (j);
}

int	len_word(const char *s, char c, int start)
{
	int	i;
	int	count;

	i = start;
	count = 0;
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

char	*ft_copy_word(const char *s, char c, int start)
{
	int		i;
	int		j;
	int		len;
	char	*word;

	i = start;
	j = 0;
	len = len_word(s, c, start);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	while (s[i] && s[i] != c)
	{
		word[j++] = s[i++];
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	split = malloc (sizeof (char *) * (count_word (s, c) + 1));
	if (!split)
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			split[j++] = ft_copy_word(s, c, i);
			i++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	split[j] = 0;
	return (split);
}
