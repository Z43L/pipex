/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 06:56:49 by davmoren          #+#    #+#             */
/*   Updated: 2024/05/04 07:05:53 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	char	*duplicada;
	size_t	i;
	size_t	len;

	len = ft_strlen(string) + 1;
	duplicada = malloc(len);
	if (duplicada == NULL)
		return (NULL);
	i = 0;
	while (string[i] != '\0')
	{
		duplicada[i] = string[i];
		i++;
	}
	duplicada[i] = '\0';
	return (duplicada);
}
