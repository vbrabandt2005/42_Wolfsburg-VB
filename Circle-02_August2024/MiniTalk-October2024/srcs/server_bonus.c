/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:13:15 by vbrabandt         #+#    #+#             */
/*   Updated: 2024/09/27 14:18:48 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniTalk.h"
#include <signal.h>
#include <unistd.h>

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	current_char;
	static int				bit_index;

	(void)context;
	current_char |= (signal == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char == END_TRANSMISSION)
			ft_printf("\n");
		else
			ft_printf("%c", current_char);
		bit_index = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;
	if (signal == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (signal == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

/**
 * @brief    Prints its program's PID and calls the signal handlers.
 */
int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	printf("%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}