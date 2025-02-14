/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:58:00 by nefimov           #+#    #+#             */
/*   Updated: 2024/11/19 19:02:16 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	str = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (str != NULL)
	{
		i = 0;
		while (s[i])
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
