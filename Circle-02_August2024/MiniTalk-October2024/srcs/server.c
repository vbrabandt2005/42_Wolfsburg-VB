/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:49:39 by vbraband          #+#    #+#             */
/*   Updated: 2024/10/02 13:46:49 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniTalk.h"

void	handle_signal(int signum)
{
	static int				bit_count = 0;
	static unsigned char	current_char = 0;

	current_char <<= 1;
	if (signum == SIGUSR2)
		current_char |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (current_char == '\0')
		{
			write(1, "\n", 1);
		}
		else
			write(1, &current_char, 1);
		bit_count = 0;
		current_char = 0;
	}
}

int	main(void)
{
	struct sigaction	sa_msg;

	ft_printf("\033[0;32m** MiniTalk Server **\033[0m\n");
	ft_printf("PID: %d\n", getpid());
	sa_msg.sa_handler = handle_signal;
	sa_msg.sa_flags = 0;
	sigaction(SIGUSR1, &sa_msg, NULL);
	sigaction(SIGUSR2, &sa_msg, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}