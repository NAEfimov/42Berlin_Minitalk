/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:42:48 by nefimov           #+#    #+#             */
/*   Updated: 2024/11/20 13:13:44 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strncmp_in(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && *s2)
	{
		if ((unsigned char) *s1 != (unsigned char) *s2)
			return ((unsigned char) *s1 - (unsigned char) *s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lit_len;

	lit_len = ft_strlen(little);
	if (lit_len == 0)
		return ((char *) big);
	if (len == 0)
		return (NULL);
	while (*big && len > 0 && len >= lit_len)
	{
		if (ft_strncmp_in(big, little, len) == 0)
			return ((char *) big);
		big++;
		len--;
	}
	return (NULL);
}
