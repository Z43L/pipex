/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 06:57:23 by davmoren          #+#    #+#             */
/*   Updated: 2024/05/04 07:06:10 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	ret;
	size_t	i;
	char	*cpy;
	char	*nocpy;

	ret = ft_strlen(src);
	if (dstsize == 0)
		return (ret);
	cpy = dst;
	nocpy = (char *)src;
	i = 0;
	while (i < dstsize - 1 && nocpy[i] != '\0')
	{
		cpy[i] = nocpy[i];
		i++;
	}
	cpy[i] = '\0';
	return (ret);
}
