/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:23:55 by ogregoir          #+#    #+#             */
/*   Updated: 2022/11/23 23:05:17 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	if ((size_t)dst - (size_t)src < size)
	{
		i = size;
		while (i != 0)
		{
			i--;
			((((unsigned char *)dst)[i]) = (((unsigned char *)src)[i]));
		}
	}
	else
	{
		while (i < size)
		{	
			(((unsigned char *)dst)[i]) = (((unsigned char *)src)[i]);
			i++;
		}
	}
	return (dst);
}
