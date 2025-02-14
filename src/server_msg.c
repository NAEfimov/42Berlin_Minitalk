/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:21:25 by nefimov           #+#    #+#             */
/*   Updated: 2025/02/14 13:28:51 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	msg_init(t_message *msg)
{
	msg->byte = 0;
	msg->c_pid = 0;
	msg->len_to_read = 32;
	msg->len = 0;
	msg->str = NULL;
}

void	msg_clear(t_message *msg)
{
	free(msg->str);
	msg_init(msg);
}