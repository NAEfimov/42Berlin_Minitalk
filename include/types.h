/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:46:57 by nefimov           #+#    #+#             */
/*   Updated: 2025/02/14 14:53:03 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <signal.h>

typedef struct s_message
{
	pid_t			c_pid;
	unsigned char	byte;
	int				len;
	char			len_to_read;
	char			*str;
}	t_message;

#endif