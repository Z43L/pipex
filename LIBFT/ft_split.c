/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 06:56:39 by davmoren          #+#    #+#             */
/*   Updated: 2024/05/04 07:45:04 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (words);
}

int	ft_wordlen(char const *s, char c)
{
	int	i;
	int	wordslen;

	wordslen = 0;
	i = 0;
	while (s[i] && s[i] != c)
	{
		wordslen++;
		i++;
	}
	return (wordslen);
}

void	free_strings(char **strings, int y)
{
	while (y >= 0)
		free(strings[y--]);
	free(strings);
}

char	**ft_allocate_and_fill(char const *s, char c, char **strings)
{
	int	x;
	int	y;
	int	lencalloc;

	x = 0;
	y = 0;
	while (s[x] != '\0')
	{
		if (s[x] == c)
			x++;
		else
		{
			lencalloc = ft_wordlen(&s[x], c);
			strings[y] = ft_substr(s, x, lencalloc);
			if (!strings[y])
			{
				free_strings(strings, y);
				return (NULL);
			}
			y++;
			x += lencalloc;
		}
	}
	strings[y] = NULL;
	return (strings);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		cowords;

	if (!s)
		return (NULL);
	cowords = ft_count_words(s, c);
	strings = (char **)ft_calloc(cowords + 1, sizeof(char *));
	if (!strings)
		return (NULL);
	return (ft_allocate_and_fill(s, c, strings));
}
