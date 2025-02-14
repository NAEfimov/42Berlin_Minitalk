/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:15:48 by nefimov           #+#    #+#             */
/*   Updated: 2024/11/20 13:12:09 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;

	str = (char *) s;
	while (n > 0)
	{
		if (*str == (char) c)
			return ((void *) str);
		str++;
		n--;
	}
	return (NULL);
}
