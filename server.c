/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:59:49 by nefimov           #+#    #+#             */
/*   Updated: 2025/02/12 21:56:08 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_message	msg;

void	msg_init(void)
{
	msg.byte = 0;
	msg.c_pid = 0;
	msg.len_to_read = 32;
	msg.len = 0;
	msg.str = NULL;
}

void	msg_clear(void)
{
	free(msg.str);
	msg_init();
}

void	sigusr1_handler(int signum, siginfo_t *info, void *context)
{
	(void)signum;
	(void)context;
	sigusr_react(0, info->si_pid);
}

void	sigusr2_handler(int signum, siginfo_t *info, void *context)
{
	(void)signum;
	(void)context;
	sigusr_react(1, info->si_pid);
}

// void	msg_getlen(void)
// {
// 	int	i;
	
// }

void	sigusr_react(char bit, pid_t pid)
{
	int	i;
	
	if (msg.c_pid == 0)
	{
		msg.c_pid = pid;
		// printf("Set PID: %d\n", msg.c_pid);
		// msg_malloc();
		// msg_getstr();
		// msg_print();
		// msg_clear();		
	}
	else if (pid == msg.c_pid)
	{
		if (msg.len_to_read > 0)						// Get string length
		{
			// printf("Read bit: %d\n", bit);
			// printf("Len_to_read: %d\n", msg.len_to_read);
			msg.len = msg.len << 1;
			msg.len += bit;
			msg.len_to_read--;
			if (msg.str == NULL && msg.len_to_read == 0)		// Allocate memory for string
			{
				// printf("Len: %d\n", msg.len);
				// msg_init();
				msg.str = malloc(msg.len + 1);
				// msg.str[msg.len] = '\0';
				msg.len = (msg.len + 1) * 8 - 1;					// Multiply len in bytes by 8 and remove 1 
				
			}
		}
		else if (msg.str && (msg.len >= 0))				// Get string
		{
			// printf("Get str\n");
			msg.str[msg.len / 8] <<= 1;
			msg.str[msg.len / 8] += bit;
			printf("len: %d\n", msg.len);
			msg.len--;
			if (msg.len < 0)							// Print string
			{
				// printf("%s\n", msg.str);
				i = 0;
				while (msg.str[i])
					write(1, &msg.str[i++], 1);
				write (1, "\n", 1);
				msg_clear();
				write(1,"clear\n", 6);
			}
		}
	}
	else
		printf("Server is busy\n");
}

// void	receive_int

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa1;
	struct sigaction	sa2;


	msg_init();
	pid = getpid();
	printf("Server PID: %d\n", pid);

    sa1.sa_flags = SA_SIGINFO;			// No special flags 
	sa1.sa_sigaction = &sigusr1_handler;	// Set the handler function 
    sigemptyset(&sa1.sa_mask);			// No signals to block during handler

	if (sigaction(SIGUSR1, &sa1, NULL) == -1)
	{
		printf("Sigerror\n");
		exit(1);
	}

    sa2.sa_flags = SA_SIGINFO;			// No special flags 
	sa2.sa_sigaction = &sigusr2_handler;	// Set the handler function 
    sigemptyset(&sa2.sa_mask);			// No signals to block during handler
	if (sigaction(SIGUSR2, &sa2, NULL) == -1)
	{
		printf("Sigerror\n");
		exit(1);
	}
	
	while (1)
	{
		pause();
		// printf("%s\n", msg.str);
	}
	
	return (0);
}