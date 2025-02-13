/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:55:12 by nefimov           #+#    #+#             */
/*   Updated: 2025/02/13 21:46:12 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>

#define	PAUSE 30

void	sigusr1_handler(int signum, siginfo_t *info, void *context)
{
	(void)signum;
	(void)context;
	(void)info;
	// write(1, "SU1\n", 4);
}

int	main(int argc, char *argv[])
{
	pid_t				s_pid;
	// pid_t			c_pid;
	struct sigaction	sa1;
	int					send;
	unsigned int		mask;
	int					i;
	
	sa1.sa_flags = SA_SIGINFO;			// No special flags 
	sa1.sa_sigaction = &sigusr1_handler;	// Set the handler function 
    sigemptyset(&sa1.sa_mask);			// No signals to block during handler

	if (sigaction(SIGUSR1, &sa1, NULL) == -1)
	{
		printf("Sigerror\n");
		exit(1);
	}

	
	// c_pid = getpid();
	// printf("Client PID: %d\n", c_pid);
	// send = c_pid;
	send = strlen(argv[2]);
	// printf("Send: %d\n", send);
	if (argc != 3)
		return (1);
	
	s_pid = atoi(argv[1]);
	kill(s_pid, SIGUSR1);
	usleep(PAUSE);
	// mask = 0b10000000;
	
	mask = UINT_MAX;
	i = -1;
	while (++i < 32)
	{
		usleep(PAUSE);
		if (((send & mask) >> 31) == 0)
			kill(s_pid, SIGUSR1);
		else
			kill(s_pid, SIGUSR2);
		send = send << 1;
		pause();
	} 
	
	// usleep(PAUSE);
	mask = UCHAR_MAX;
	send = strlen(argv[2]);
	usleep(PAUSE);
	while (send >= 0)
	{
		i = -1;
		while (++i < 8)
		{
			usleep(PAUSE);
			if (((argv[2][send] & mask) >> 7) == 0)
				kill(s_pid, SIGUSR1);
			else
				kill(s_pid, SIGUSR2);
			argv[2][send] <<= 1;
			// printf("send: %d\n", send);
			pause();
		}
		send--;
		// printf("send: %d\n", send);
		// usleep(PAUSE); 
	}
	

	return (0);
}