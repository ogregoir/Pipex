/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:42:17 by ogregoir          #+#    #+#             */
/*   Updated: 2022/11/29 00:33:55 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!n[0])
		return ((char *)hs);
	while (hs[i] != '\0' && (i + j < len))
	{
		if (hs[i] != '\0' && hs[i] == n[0])
		{
			j = 0;
			while (n[j] && hs[i + j] == n[j] && (i + j < len))
				j++;
			if (n[j] == '\0')
				return ((char *)hs + i);
		}
		i++;
	}
	return (NULL);
}
