/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:12:17 by nefimov           #+#    #+#             */
/*   Updated: 2025/02/12 21:53:06 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_message
{
	pid_t			c_pid;
	unsigned char	byte;
	int				len;
	char			len_to_read;
	char			*str;
}	t_message;

void	sigusr1_handler(int signum, siginfo_t *info, void *context);
void	sigusr2_handler(int signum, siginfo_t *info, void *context);
void	msg_init(void);
void	sigusr_react(char bit, pid_t pid);