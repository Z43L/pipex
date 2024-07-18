/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 06:56:22 by davmoren          #+#    #+#             */
/*   Updated: 2024/05/04 07:27:37 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		i;
	char	sallinea;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		s++;
	}
	sallinea = '\n';
	write(fd, &sallinea, 1);
}
