/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:49:41 by vbraband          #+#    #+#             */
/*   Updated: 2024/10/02 13:46:23 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniTalk.h"

void	send_null_terminator(int server_id, int result)
{
	int	i;

	i = 8;
	while (i > 0)
	{
		if (((unsigned char)('\0' >> (i - 1)) & 1))
			result = kill(server_id, SIGUSR2);
		else
			result = kill(server_id, SIGUSR1);
		if (result == -1)
		{
			ft_printf("Error sending signal (PID might be incorrect)\n");
			return ;
		}
		usleep(300); // Increased sleep duration
		i--;
	}
}

void	send_message(int server_id, char *message)
{
	int	letter;
	int	i;
	int	result;

	letter = 0;
	while (message[letter])
	{
		i = 8;
		while (i > 0)
		{
			if (((unsigned char)(message[letter] >> (i - 1)) & 1))
				result = kill(server_id, SIGUSR2);
			else
				result = kill(server_id, SIGUSR1);
			if (result == -1)
			{
				ft_printf("Error sending signal (PID might be incorrect)\n");
				return ;
			}
			usleep(300); // Increased sleep duration
			i--;
		}
		letter++;
	}
	send_null_terminator(server_id, result);
}

int	main(int ac, char **av)
{
	int		server_id;
	char	*message;

	if (ac == 3)
	{
		server_id = ft_atoi(av[1]);
		if (!server_id)
			ft_printf("Error: Wrong server id.\n");
		message = av[2];
		if (message[0] == 0)
		{
			ft_printf("Error: No message given...Please offer message!\n");
			return (0);
		}
		send_message(server_id, message);
	}
	else
		ft_printf("Error: Incorect number of arguments!\n");
	return (0);
}