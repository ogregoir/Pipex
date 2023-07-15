/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:36:02 by ogregoir          #+#    #+#             */
/*   Updated: 2022/11/23 22:59:54 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	if (size > 4294967295 || count > 4294967295)
		return (0);
	str = malloc(size * count);
	if (!str)
		return (0);
	while (i != size * count)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
