/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:54:51 by vbraband          #+#    #+#             */
/*   Updated: 2024/09/11 13:23:54 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_nomap(t_game *game, char *err_msg)
{
	ft_printf("\n%s%s%sError%s\n\n", BOLD, F_D_RED, B_D_CYAN, RESET);
	ft_printf("%s%s%s%s\n\n%s", ITALICS, B_D_CYAN, err_msg, RESET);
	free(game);
	return (0);
}

int	ft_error(t_game *game, char *err_msg)
{
	ft_printf("\n%s%s%sError!%s\n\n", BOLD, F_D_RED, B_D_CYAN, RESET);
	ft_printf("%s%s%s%s\n\n%s", ITALICS, B_D_CYAN, err_msg, RESET);
	map_destroyer(game);
	free(game);
	return (0);
}
