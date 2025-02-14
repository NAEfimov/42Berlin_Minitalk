/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:35:35 by nefimov           #+#    #+#             */
/*   Updated: 2024/11/29 16:27:12 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

static int	char_count(unsigned int num)
{
	int	i;

	if (num == 0)
		return (1);
	i = 0;
	while (num > 0)
	{
		i++;
		num = num / 10;
	}
	return (i);
}

static void	add_digits(unsigned int n, char **s)
{
	if (n != 0)
	{
		add_digits(n / 10, s);
		**s = (n % 10) + '0';
		*s = *s + 1;
	}
}

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*str;
	char	*s;

	len = char_count(n) + 1;
	str = malloc(len * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, len);
	s = str;
	if (n == 0)
		*s = '0';
	else
		add_digits(n, &s);
	return (str);
}
