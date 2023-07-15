/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:13:58 by ogregoir          #+#    #+#             */
/*   Updated: 2022/11/23 23:06:45 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_puttint_fd(int b, int fd)
{
	b += 48;
	write(fd, &b, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{	
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_puttint_fd(n % 10, fd);
	}
	else
		ft_puttint_fd(n, fd);
}
