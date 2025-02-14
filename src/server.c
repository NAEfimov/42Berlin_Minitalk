/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:59:49 by nefimov           #+#    #+#             */
/*   Updated: 2025/02/14 16:15:09 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "libft.h"
#include "types.h"

t_message	g_msg;

void	sigusr_react(char bit, pid_t pid)
{
	if (g_msg.c_pid != pid)
	{
		msg_clear(&g_msg);
		g_msg.c_pid = pid;
	}
	else if (pid == g_msg.c_pid)
	{
		if (g_msg.len_to_read > 0)
			msg_getlen(&g_msg, bit);
		else if (g_msg.str && (g_msg.len >= 0))
			msg_getstr(&g_msg, bit);
	}
	else
		ft_putstr_fd("Server is busy\n", 1);
}

int	main(void)
{
	struct sigaction	sa1;
	struct sigaction	sa2;

	msg_init(&g_msg);
	print_pid();
	sa1.sa_flags = SA_SIGINFO;
	sa1.sa_sigaction = &sigusr1_handler;
	sigemptyset(&sa1.sa_mask);
	sa2.sa_flags = SA_SIGINFO;
	sa2.sa_sigaction = &sigusr2_handler;
	sigemptyset(&sa2.sa_mask);
	if (sigaction(SIGUSR1, &sa1, NULL) == -1)
		msgclear_exit(&g_msg, "sigerror");
	if (sigaction(SIGUSR2, &sa2, NULL) == -1)
		msgclear_exit(&g_msg, "sigerror");
	while (1)
		pause();
	return (0);
}
