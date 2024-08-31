/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:40:19 by vbraband          #+#    #+#             */
/*   Updated: 2024/08/29 11:54:05 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_counter(t_game *game, int steps)
{
	char	mvmt[20];

	game->player.move_count += steps;
	if (steps == 1)
	{
		mlx_put_image_to_window(game->show.mlx_ptr, game->show.win_ptr,
			game->wall.img, 0 * TILE_SIZE, 0 * TILE_SIZE);
		mlx_put_image_to_window(game->show.mlx_ptr, game->show.win_ptr,
			game->wall.img, 1 * TILE_SIZE, 0 * TILE_SIZE);
		snprintf(mvmt, sizeof(mvmt), "Capy moves: %d", game->player.move_count);
		mlx_string_put(game->show.mlx_ptr, game->show.win_ptr,
			10, 20, 0x00FFFF, mvmt);
		ft_printf("Capy ran %i steps so far\n", game->player.move_count);
	}
}
