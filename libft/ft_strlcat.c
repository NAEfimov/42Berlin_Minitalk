/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:08:11 by nefimov           #+#    #+#             */
/*   Updated: 2024/11/19 19:03:27 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dlen;
	char		*d;
	const char	*s;

	s = src;
	d = dst;
	while (size != 0 && *d)
	{
		d++;
		size--;
	}
	dlen = d - dst;
	if (size == 0)
		return (dlen + ft_strlen(src));
	while (*s)
	{
		if (size != 1)
		{
			*d++ = *s;
			size--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
