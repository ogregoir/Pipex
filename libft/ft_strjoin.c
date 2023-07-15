/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:04:54 by ogregoir          #+#    #+#             */
/*   Updated: 2022/11/23 23:21:19 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*tab;
	size_t	dstsize;
	size_t	lens1;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	lens1 = ft_strlen(s1);
	dstsize = lens1 + ft_strlen(s2);
	tab = malloc(sizeof(char) * (dstsize + 1));
	if (!tab)
		return (NULL);
	if (!s1 || !s2)
		return (0);
	ft_strlcpy(tab, s1, lens1 + 1);
	ft_strlcat(tab, s2, dstsize + 1);
	return (tab);
}
