/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:08:44 by ogregoir          #+#    #+#             */
/*   Updated: 2022/11/29 00:34:06 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int s)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)s)
			return ((char *)(str + i));
		i++;
	}
	if ((char)s == 0)
		return ((char *)(str + ft_strlen(str)));
	return (0);
}
