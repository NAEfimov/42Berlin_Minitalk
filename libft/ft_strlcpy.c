/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:51:07 by nefimov           #+#    #+#             */
/*   Updated: 2024/11/15 15:28:26 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	while (*s)
	{
		if (size > 1)
		{
			*d++ = *s;
			size--;
		}
		s++;
	}
	if (size != 0)
		*d = '\0';
	return (s - src);
}
