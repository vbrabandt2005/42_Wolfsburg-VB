/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:33:00 by vbraband          #+#    #+#             */
/*   Updated: 2024/09/06 14:33:09 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_window(t_game *game)
{
	game->window.mlx_ptr = 0;
	game->window.win_ptr = 0;
	game->window.img = "";
	game->window.addr = "";
	game->window.bpp = 0;
	game->window.size_line = 0;
	game->window.endian = 0;
	game->window.x_win = 0;
	game->window.y_win = 0;
	return (1);
}
