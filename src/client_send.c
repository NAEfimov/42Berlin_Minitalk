/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_send.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:22:42 by nefimov           #+#    #+#             */
/*   Updated: 2025/02/18 00:08:39 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "client.h"

void	send_int(pid_t s_pid, int num)
{
	int				i;
	unsigned int	mask;

	mask = UINT_MAX;
	i = -1;
	while (++i < 32)
	{
		usleep(PAUSE);
		if (((num & mask) >> 31) == 0)
			kill(s_pid, SIGUSR1);
		else
			kill(s_pid, SIGUSR2);
		num = num << 1;
	}
}

void	send_char(pid_t s_pid, char c)
{
	int				i;
	unsigned int	mask;

	mask = UCHAR_MAX;
	i = -1;
	while (++i < 8)
	{
		usleep(PAUSE);
		if (((c & mask) >> 7) == 0)
			kill(s_pid, SIGUSR1);
		else
			kill(s_pid, SIGUSR2);
		c <<= 1;
	}
}

void	send_str(pid_t s_pid, char *str, int len)
{
	while (len >= 0)
	{
		send_char(s_pid, str[len]);
		len--;
	}
}
