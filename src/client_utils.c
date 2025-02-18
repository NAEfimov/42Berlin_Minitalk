/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:22:14 by nefimov           #+#    #+#             */
/*   Updated: 2025/02/17 20:50:13 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "client.h"

// Convert string <str> to integer number <n>
// Return <0> if OK or <1> if error.
// If there is a reading error return <NULL>
int	read_num(char *str, int *n)
{
	long int	num;
	int			sign;

	sign = 1;
	num = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		num = num * 10 + (*str++ - '0');
	num = sign * num;
	if (*str != '\0' || num < INT_MIN || num > INT_MAX)
		return (1);
	*n = (int) num;
	return (0);
}

// Check number of input atributes
void	check_args(int argc, char *argv[], int *s_pid)
{
	if (argc < 2 || argc > 3)
		exit(1);
	else
	{
		if (read_num(argv[1], s_pid) != 0)
			exit(1);
		if (argc == 2)
			exit(0);
	}
}
