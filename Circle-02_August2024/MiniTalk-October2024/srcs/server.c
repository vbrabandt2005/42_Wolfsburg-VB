/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:49:39 by vbraband          #+#    #+#             */
/*   Updated: 2024/09/27 13:27:57 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MiniTalk.h"

void    handler(int sig)
{
    static unsigned char    current_char;
    static int              current_bit;

    current_char |= (sig == SIGUSR1);
    current_bit++;

    if (current_bit == 8)
    {
        if (current_char == END_TRANSMISSION)
        {
            ft_printf("\n");
        }
        else
            ft_printf("%c", current_char);
        current_char = 0;
        current_bit = 0;
    }
    else
        current_char <<= 1;
}

int main(void)
{
    ft_printf("%d\n", getpid());
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    while (1)
        pause();
    return (0);
}
