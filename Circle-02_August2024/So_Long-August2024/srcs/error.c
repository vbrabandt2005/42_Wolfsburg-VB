/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:51:18 by acloos            #+#    #+#             */
/*   Updated: 2024/08/28 14:16:00 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
to print errno:
include string.h errno.h
char buf[256]  (or whatever size)
strerror_s(buf, 256, errno);
printf("%s", buf);

*/

#include "so_long.h"

int	ft_nomap(t_game *game, char *err_msg)
{
	ft_printf("\n%s%s%sError%s\n\n", BOLD, F_L_YELLOW, B_D_RED, RST);
	ft_printf("%s%s%s\n%s", ITALICS, F_D_YELLOW, err_msg, RST);
	ft_printf("%s%s%s\n\n\t\t\tSo long...%s\n\n"\
	, RST, ITALICS, F_L_GREY, RST);
	free(game);
	return (0);
}

int	ft_error(t_game *game, char *err_msg)
{
	ft_printf("\n%s%s%sError!%s\n\n", BOLD, F_L_YELLOW, B_D_RED, RST);
	ft_printf("%s%s%s\n%s", ITALICS, F_D_YELLOW, err_msg, RST);
	ft_printf("%s%s%s\n\n\t\t\tSo long...%s\n\n"\
	, RST, ITALICS, F_L_GREY, RST);
	map_destroyer(game);
	free(game);
	return (0);
}
