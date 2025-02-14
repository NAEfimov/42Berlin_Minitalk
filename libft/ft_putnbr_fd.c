/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:03:53 by nefimov           #+#    #+#             */
/*   Updated: 2024/11/20 13:12:32 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static void	add_digits(int n, char **s, int sign)
{
	if (n != 0)
	{
		add_digits(n / 10, s, sign);
		**s = sign * (n % 10) + '0';
		*s = *s + 1;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		sign;
	char	str[12];
	char	*s;

	ft_bzero(str, 12);
	s = str;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		*s++ = '-';
	}
	if (n == 0)
		*s = '0';
	else
		add_digits(n, &s, sign);
	write(fd, &str, ft_strlen(str));
	return ;
}
