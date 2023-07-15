/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:39:28 by ogregoir          #+#    #+#             */
/*   Updated: 2022/11/23 23:12:20 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_copys(size_t size, size_t j, char const *s1, char *s)
{
	size_t	i;

	i = 0;
	while (s1[i] && i < size)
	{
		s[i] = s1[j];
		i++;
		j++;
	}
	s[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	j;
	size_t	size;
	size_t	lens1;
	char	*s;

	if (!s1 || !set)
		return ((char *)s1);
	j = 0;
	lens1 = ft_strlen(s1) -1;
	while (ft_strchr(set, s1[j]) && s1[j])
		j++;
	while (ft_strrchr(set, s1[lens1]) && s1[lens1])
	{
		if (lens1 < j)
			break ;
		lens1--;
	}
	size = lens1 - j + 1;
	s = malloc(size + 1);
	if (!s)
		return (0);
	s[0] = '\0';
	ft_copys(size, j, s1, s);
	return (s);
}
