/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:22:12 by vbraband          #+#    #+#             */
/*   Updated: 2024/09/02 13:22:30 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_counter(t_game *game, int steps)
{
	char	mvmt[20];

	game->player.move_count += steps;
	if (steps == 1)
	{
		mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
			game->wall.img, 0 * TILE_SIZE, 0 * TILE_SIZE);
		mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
			game->wall.img, 1 * TILE_SIZE, 0 * TILE_SIZE);
		snprintf(mvmt, sizeof(mvmt), "Moves: %d", game->player.move_count);
		mlx_string_put(game->window.mlx_ptr, game->window.win_ptr, 10, 20,
			0x00FFFF, mvmt);
		ft_printf("you have taken %i steps so far\n", game->player.move_count);
	}
}
