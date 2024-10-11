/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:49:39 by vbraband          #+#    #+#             */
/*   Updated: 2024/10/09 14:26:52 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniTalk.h"

void	rec(int n, int pid, int *clientpid)
{
	int			shift;
	static int	i = 7;
	static char	c;

	if (i == -1 || pid != *clientpid)
	{
		i = 7;
		c = 0;
		*clientpid = pid;
	}
	shift = 1 << (i);
	if (n != 0)
		c = (c | shift);
	i--;
	if (i == -1)
		write(1, &c, 1);
}

void	server(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Your lovely PID: %d\n", pid);
}

void	sig_handler(int sig, siginfo_t *info, void *ptr)
{
	static int	clientpid = -1;

	(void)ptr;
	if (sig == SIGUSR1)
		rec(1, info->si_pid, &clientpid);
	else
		rec(0, info->si_pid, &clientpid);
}

int	main(void)
{
	struct sigaction	act;

	act.sa_flags = 0;
	act.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	server();
	while (1)
		pause();
	return (0);
}
