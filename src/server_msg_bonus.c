/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_msg_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:21:25 by nefimov           #+#    #+#             */
/*   Updated: 2025/02/18 00:10:15 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft.h"

void	msg_init(t_message *msg)
{
	msg->byte = 0;
	msg->c_pid = 0;
	msg->len_to_read = sizeof(int) * 8;
	msg->len = 0;
	msg->str = NULL;
}

void	msg_clear(t_message *msg)
{
	free(msg->str);
	msg_init(msg);
}

void	msg_malloc(t_message *msg)
{
	msg->str = malloc(msg->len + 1);
	if (msg->str == NULL)
		msgclear_exit(msg, "mallocerror");
	msg->len = (msg->len + 1) * 8 - 1;
}

void	msg_getlen(t_message *msg, char bit)
{
	msg->len = msg->len << 1;
	msg->len += bit;
	msg->len_to_read--;
	if (msg->str == NULL && msg->len_to_read == 0)
		msg_malloc(msg);
	kill(msg->c_pid, SIGUSR1);
}

void	msg_getstr(t_message *msg, char bit)
{
	msg->str[msg->len / 8] <<= 1;
	msg->str[msg->len / 8] += bit;
	msg->len--;
	kill(msg->c_pid, SIGUSR1);
	if (msg->len < 0)
	{
		write(1, msg->str, ft_strlen(msg->str));
		write (1, "\n", 1);
		kill(msg->c_pid, SIGUSR2);
		msg_clear(msg);
	}
}
