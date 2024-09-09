/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:22:12 by vbraband          #+#    #+#             */
/*   Updated: 2024/09/05 16:52:11 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_counter(t_game *game, int steps)
{
	char	*move_count_str;

	game->player.move_count += steps;
	if (steps == 1)
	{
		mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
			game->wall.img, 0 * TILE_SIZE, 0 * TILE_SIZE);
		mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
			game->wall.img, 1 * TILE_SIZE, 0 * TILE_SIZE);
		ft_printf("Moves: %d\n", game->player.move_count);
		move_count_str = ft_itoa(game->player.move_count);
		mlx_string_put(game->window.mlx_ptr, game->window.win_ptr, 10, 10,
			0xFFFFFF, move_count_str);
		free(move_count_str);
	}
}
