/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:04:24 by nefimov           #+#    #+#             */
/*   Updated: 2024/11/20 13:47:17 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;
	int		i;

	if ((src == NULL && dest == NULL) && n != 0)
		return (NULL);
	s = (char *)src;
	d = (char *)dest;
	if (s < d)
	{
		i = (int)n;
		while (--i >= 0)
			d[i] = s[i];
	}
	else
	{
		i = -1;
		while (++i < (int)n)
			d[i] = s[i];
	}
	i = 0;
	return (dest);
}
