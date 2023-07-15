/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 02:21:57 by ogregoir          #+#    #+#             */
/*   Updated: 2022/11/23 23:09:43 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	unsigned int	lens;

	i = 0;
	lens = ft_strlen(s);
	str = malloc(sizeof(char) * lens + 1);
	if (!str)
		return (NULL);
	while (s[i] && i < lens)
	{	
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
