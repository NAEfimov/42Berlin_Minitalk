/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:17:50 by nefimov           #+#    #+#             */
/*   Updated: 2024/11/21 18:15:48 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*cur_lst;
	int		size;

	if (!lst)
		return (0);
	cur_lst = lst;
	size = 1;
	while (cur_lst->next != NULL)
	{
		size++;
		cur_lst = cur_lst->next;
	}
	return (size);
}
