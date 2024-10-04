/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:49:41 by vbraband          #+#    #+#             */
/*   Updated: 2024/10/04 15:48:34 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniTalk.h"

void	send_char(int pid, char c)
{
	int	shift;
	int	i;

	i = 7;
	while (i >= 0)
	{
		shift = 1 << (i);
		if (c & shift)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
}

void	send_message(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, str[i]);
}

int	send(int pid, char *str)
{
	if (kill(pid, 0) == -1)
	{
		ft_printf("Invalid PID\n");
		return (1);
	}
	else
	{
		if (pid == 0)
		{
			ft_printf("Invalid PID\n");
			return (1);
		}
		send_message(pid, str);
		return (0);
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		return (1);
	if (ft_atoi(av[1], &pid) == 0)
	{
		ft_printf("invalid argument");
		return (1);
	}
	else
		return (send(pid, av[2]));
}
