/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:55:12 by nefimov           #+#    #+#             */
/*   Updated: 2025/02/14 15:41:48 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "types.h"
#include "client.h"

void	sigusr1_handler(int signum)
{
	(void)signum;
}

void	send_int(pid_t s_pid, int len)
{
	int				i;
	unsigned int	mask;

	mask = UINT_MAX;
	i = -1;
	while (++i < 32)
	{
		usleep(PAUSE);
		if (((len & mask) >> 31) == 0)
			kill(s_pid, SIGUSR1);
		else
			kill(s_pid, SIGUSR2);
		len = len << 1;
		pause();
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
		pause();
	}
}

void	send_str(pid_t s_pid, int len, char *str)
{
	while (len >= 0)
	{
		send_char(s_pid, str[len]);
		len--;
	}
}

int	main(int argc, char *argv[])
{
	pid_t				s_pid;
	int					len;

	if (argc != 3)
		return (1);
	if (signal(SIGUSR1, sigusr1_handler) == SIG_ERR)
		return (1);
	s_pid = ft_atoi(argv[1]);
	kill(s_pid, SIGUSR1);
	usleep(PAUSE);
	len = ft_strlen(argv[2]);
	send_int(s_pid, len);
	usleep(PAUSE);
	send_str(s_pid, len, argv[2]);
	return (0);
}
