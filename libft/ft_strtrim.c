/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:41:31 by nefimov           #+#    #+#             */
/*   Updated: 2024/11/20 13:14:13 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	char			*fd;
	size_t			len;

	start = 0;
	len = ft_strlen(s1);
	end = len;
	while (in_set(s1[start], set))
		start++;
	while ((end > 1) && (end > start + 1) && in_set(s1[end - 1], set))
		end--;
	fd = ft_substr(s1, start, (end - start));
	if (fd == NULL)
		return (NULL);
	return (fd);
}
