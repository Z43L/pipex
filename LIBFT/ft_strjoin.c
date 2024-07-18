/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 06:56:58 by davmoren          #+#    #+#             */
/*   Updated: 2024/05/04 07:06:01 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	int		z;
	char	*ptr;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ptr = malloc(len1 + len2 + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	z = 0;
	while (s1[i])
		ptr[z++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		ptr[z] = s2[i];
		z++;
		i++;
	}
	ptr[z] = '\0';
	return (ptr);
}
