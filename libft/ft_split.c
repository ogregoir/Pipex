/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:11:46 by ogregoir          #+#    #+#             */
/*   Updated: 2022/11/25 00:52:50 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_number(char const *s, char c)
{
	int	i;
	int	word;

	word = 0;
	i = 0;
	if (!s || !s[0])
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (word);
}

static char	*ft_strdupcpy(const char *src, char c)
{
	char	*tab;
	int		i;

	i = 0;
	while (src[i] != c && src[i])
		i++;
	if (!src)
		return (0);
	tab = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (src[i] && src[i] != c)
	{
		tab[i] = src[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		n;
	int		j;

	i = 0;
	j = 0;
	n = ft_number(s, c);
	tab = malloc(sizeof(char *) * (n + 1));
	if (!tab)
		return (0);
	while (s[i] && j < n)
	{
		if (s[i] != c)
		{
			tab[j] = ft_strdupcpy(s + i, c);
			j++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	tab[j] = 0;
	return (tab);
}
