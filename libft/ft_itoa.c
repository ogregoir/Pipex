/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:58:52 by ogregoir          #+#    #+#             */
/*   Updated: 2022/11/23 23:02:53 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit(long int n)
{
	int	j;

	j = 0;
	if (n < 0)
		n *= -1;
	if (n < 10)
		return (1);
	while (n)
	{
		n = n / 10;
			j++;
	}
	return (j);
}

static char	*ft_numeric(long int n, char *str)
{
	int		i;

	i = ft_digit(n);
	if (n == 0)
	{
		str[0] = '0';
		str[i] = '\0';
		return (str);
	}
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
		i = i + 1;
	}
	while (n != 0)
	{
		str[i - 1] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			j;
	long int	l;

	l = n;
	j = ft_digit(n);
	if (l >= 0)
	{
		str = malloc(sizeof(char) * (j + 1));
		if (!str)
			return (NULL);
		str[j] = '\0';
	}
	else
	{
		str = malloc(sizeof(char) * (j + 2));
		if (!str)
			return (NULL);
		str[j + 1] = '\0';
	}
	str = ft_numeric(l, str);
	return (str);
}
