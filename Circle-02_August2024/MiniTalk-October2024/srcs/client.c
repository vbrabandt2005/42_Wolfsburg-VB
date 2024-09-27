/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:49:41 by vbraband          #+#    #+#             */
/*   Updated: 2024/09/27 13:19:10 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniTalk.h"

void    send_char(int pid, unsigned char c)
{
    int i;
    unsigned char temp;

    i = 8;
    while (i > 0)
    {
        i--;
        temp = c >> i;
        if (temp & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
    }
}


int main(int argc, char *argv[])
{
    pid_t server_pid;
    const char *message;
    int i;

   if (argc != 3)
    {
        ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
        return (1);
    }
    server_pid = ft_atoi(argv[1]);
    message = argv[2];
    i = 0;
    while (message[i])
    {
        send_char(server_pid, message[i]);
        i++;
    }
    send_char(server_pid, END_TRANSMISSION);
    return (0);
}