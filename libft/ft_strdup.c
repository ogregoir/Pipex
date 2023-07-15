/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:11:11 by ogregoir          #+#    #+#             */
/*   Updated: 2022/11/23 23:08:11 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*tab;
	int		sizesrc;
	int		i;

	i = 0;
	sizesrc = ft_strlen((char *)src);
	tab = malloc(sizeof(char) * (sizesrc + 1));
	if (tab == NULL)
		return (NULL);
	while (src[i])
	{
		tab[i] = src[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
