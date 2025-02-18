/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:55:12 by nefimov           #+#    #+#             */
/*   Updated: 2025/02/18 00:03:00 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "client.h"

void	sigusr1_handler(int signum)
{
	(void)signum;
}

int	main(int argc, char *argv[])
{
	pid_t				s_pid;
	int					len;

	check_args(argc, argv, &s_pid);
	if (signal(SIGUSR1, sigusr1_handler) == SIG_ERR)
		return (1);
	len = ft_strlen(argv[2]);
	kill(s_pid, SIGUSR1);
	send_int(s_pid, len);
	send_str(s_pid, argv[2], len);
	usleep(PAUSE * 3);
	return (0);
}
