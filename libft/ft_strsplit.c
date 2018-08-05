/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arusso <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:51:43 by arusso            #+#    #+#             */
/*   Updated: 2018/05/29 18:12:44 by arusso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *str, char c)
{
	int i;
	int words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i - 1] == c || i == 0))
		{
			words++;
			i++;
		}
		else
			i++;
	}
	return (words);
}

static size_t	ft_word_len(const char *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i])
	{
		i++;
		len++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s || !c)
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(*tab) *
					(ft_count_words(s, c)) + 1)))
		return (NULL);
	i = -1;
	k = 0;
	while (++i < ft_count_words(s, c))
	{
		j = 0;
		if (!(tab[i] = ft_strnew(ft_word_len((char*)&s[k], c))))
			return (NULL);
		while (s[k] == c)
			k++;
		while (s[k] != c && s[k])
			tab[i][j++] = s[k++];
		tab[i][j] = '\0';
	}
	tab[i] = NULL;
	return (tab);
}
