/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 06:57:52 by davmoren          #+#    #+#             */
/*   Updated: 2024/05/04 07:11:40 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*allocate_empty_string(void)
{
	char	*nuecadena;

	nuecadena = malloc(sizeof(char));
	if (nuecadena == NULL)
		return (NULL);
	nuecadena[0] = '\0';
	return (nuecadena);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sub_len;
	size_t	i;
	char	*nuecadena;
	size_t	sizzee;

	sizzee = ft_strlen(s);
	if (start >= sizzee)
		return (allocate_empty_string());
	sub_len = 0;
	i = start;
	while (s[i] != '\0' && sub_len < len)
	{
		sub_len++;
		i++;
	}
	nuecadena = malloc((sub_len + 1) * sizeof(char));
	if (nuecadena == NULL)
		return (NULL);
	sub_len = 0;
	i = start;
	while (s[i] != '\0' && sub_len < len)
		nuecadena[sub_len++] = s[i++];
	nuecadena[sub_len] = '\0';
	return (nuecadena);
}
