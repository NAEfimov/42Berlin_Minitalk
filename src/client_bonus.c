/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:55:12 by nefimov           #+#    #+#             */
/*   Updated: 2025/02/18 14:41:48 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "client.h"

void	sigusr1_handler(int signum)
{
	(void)signum;
}

void	sigusr2_handler(int signum)
{
	(void)signum;
	ft_putstr_fd("String received\n", 1);
}

int	main(int argc, char *argv[])
{
	pid_t				s_pid;
	int					len;

	check_args(argc, argv, &s_pid);
	if (signal(SIGUSR1, sigusr1_handler) == SIG_ERR)
		return (1);
	if (signal(SIGUSR2, sigusr2_handler) == SIG_ERR)
		return (1);
	len = ft_strlen(argv[2]);
	kill(s_pid, SIGUSR1);
	send_int(s_pid, len);
	send_str(s_pid, argv[2], len);
	pause();
	usleep(PAUSE);
	return (0);
}
