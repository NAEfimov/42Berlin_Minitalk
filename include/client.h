/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:44:32 by nefimov           #+#    #+#             */
/*   Updated: 2025/02/14 15:44:01 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <time.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "types.h"

# define PAUSE	30

void	sigusr1_handler(int signum);
void	send_int(pid_t s_pid, int len);
void	send_char(pid_t s_pid, char c);
void	send_str(pid_t s_pid, int len, char *str);

#endif