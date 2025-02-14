/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:06:28 by nefimov           #+#    #+#             */
/*   Updated: 2024/11/14 16:35:32 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fd;
	char	*str;

	fd = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (fd == NULL)
		return (NULL);
	str = fd;
	while (*s1)
	{
		*str++ = *s1;
		s1++;
	}
	while (*s2)
	{
		*str++ = *s2;
		s2++;
	}
	*str = '\0';
	return (fd);
}
