/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:49:41 by vbraband          #+#    #+#             */
/*   Updated: 2024/09/27 13:11:44 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniTalk.h"

void    send_char(int pid, unsigned char c)
{
    int i;

    i = 0;
    while (i < 8)
    {
        if (c & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        c >>= 1;
        i++;
        usleep(50);
    }
}


int main(void)
{
    int pid;
    char *str;

    pid = ft_atoi(ft_getenv("SERVER_PID"));
    str = ft_getenv("MESSAGE");
    while (*str)
    {
        send_char(pid, *str);
        str++;
    }
    send_char(pid, END_TRANSMISSION);
    return (0);
}