/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:12:17 by nefimov           #+#    #+#             */
/*   Updated: 2025/02/18 00:08:23 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <time.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

# define PAUSE			500
# define SIGUSR1_BIT	0
# define SIGUSR2_BIT	1

typedef struct s_message
{
	pid_t			c_pid;
	unsigned char	byte;
	int				len;
	char			len_to_read;
	char			*str;
}	t_message;

void	msg_init(t_message *msg);
void	msg_clear(t_message *msg);
void	msg_malloc(t_message *msg);
void	msg_getlen(t_message *msg, char bit);
void	msg_getstr(t_message *msg, char bit);
void	msgclear_exit(t_message *msg, char *errmsg);

void	sigusr1_handler(int signum, siginfo_t *info, void *context);
void	sigusr2_handler(int signum, siginfo_t *info, void *context);
void	sigusr_react(char bit, pid_t pid);

void	print_pid(void);

#endif