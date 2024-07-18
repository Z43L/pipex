/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmoren <davmoren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 06:55:52 by davmoren          #+#    #+#             */
/*   Updated: 2024/05/04 07:46:54 by davmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_initialize(int a, int len)
{
	char	*result;
	int		isnegative;

	isnegative = 0;
	if (a < 0)
		isnegative = 1;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	if (a == 0)
	{
		result[0] = '0';
		return (result);
	}
	if (a == 1)
	{
		result[0] = '1';
		return (result);
	}
	if (isnegative)
		result[0] = '-';
	return (result);
}

void	ft_fill(char *resultado, int a, int len)
{
	int	posicion;
	int	isnegative;

	isnegative = 0;
	if (a < 0)
		isnegative = 1;
	while (a)
	{
		posicion = a % 10;
		if (isnegative)
			posicion = -posicion;
		resultado[--len] = '0' + posicion;
		a /= 10;
	}
}

char	*ft_itoa(int a)
{
	int		lenn;
	char	*resultado;

	lenn = ft_intlen(a);
	resultado = ft_initialize(a, lenn);
	if (resultado == NULL || resultado[0] == '0')
		return (resultado);
	ft_fill(resultado, a, lenn);
	return (resultado);
}
