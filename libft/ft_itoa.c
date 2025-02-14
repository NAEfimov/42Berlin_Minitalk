/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:35:35 by nefimov           #+#    #+#             */
/*   Updated: 2024/11/20 13:11:55 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

static int	char_count(int num)
{
	int	i;

	if (num == 0)
		return (1);
	i = 0;
	if (num < 0)
		i = 1;
	while (num != 0)
	{
		i++;
		num = num / 10;
	}
	return (i);
}

static void	add_digits(int n, char **s, int sign)
{
	if (n != 0)
	{
		add_digits(n / 10, s, sign);
		**s = sign * (n % 10) + '0';
		*s = *s + 1;
	}
}

char	*ft_itoa(int n)
{
	int		sign;
	int		len;
	char	*str;
	char	*s;

	len = char_count(n) + 1;
	str = malloc(len * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, len);
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
	return (str);
}
