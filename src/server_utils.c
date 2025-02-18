/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:21:48 by nefimov           #+#    #+#             */
/*   Updated: 2025/02/18 00:08:21 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft.h"

void	msgclear_exit(t_message *msg, char *errmsg)
{
	if (msg->str != NULL)
		free(msg->str);
	ft_putstr_fd(errmsg, 1);
	ft_putchar_fd('\n', 1);
	exit(1);
}

void	print_pid(void)
{
	char	*str;

	str = ft_itoa(getpid());
	if (str == NULL)
		exit(1);
	ft_putstr_fd("Server PID: ", 1);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	free(str);
}
