/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:55:12 by nefimov           #+#    #+#             */
/*   Updated: 2025/02/12 22:03:36 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	pid_t			s_pid;
	// pid_t			c_pid;
	int				send;
	unsigned int	mask;
	int				i;
	
	// c_pid = getpid();
	// printf("Client PID: %d\n", c_pid);
	// send = c_pid;
	send = strlen(argv[2]);
	// printf("Send: %d\n", send);
	if (argc != 3)
		return (1);
	
	s_pid = atoi(argv[1]);
	kill(s_pid, SIGUSR1);
	usleep(100);
	// mask = 0b10000000;
	
	mask = UINT_MAX;
	i = -1;
	while (++i < 32)
	{
		if (((send & mask) >> 31) == 0)
			kill(s_pid, SIGUSR1);
		else
			kill(s_pid, SIGUSR2);
		send = send << 1;
		usleep(100);
	} 
	
	usleep(200);
	mask = UCHAR_MAX;
	send = strlen(argv[2]);
	usleep(200);
	while (send >= 0)
	{
		i = -1;
		while (++i < 8)
		{
			if (((argv[2][send] & mask) >> 7) == 0)
				kill(s_pid, SIGUSR1);
			else
				kill(s_pid, SIGUSR2);
			argv[2][send] <<= 1;
			// printf("i: %d\n", i);
			usleep(100);
		}
		send--; 
	}
	

	return (0);
}