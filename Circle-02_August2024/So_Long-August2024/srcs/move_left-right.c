/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left-right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 14:12:55 by vbraband          #+#    #+#             */
/*   Updated: 2024/09/06 14:13:50 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_game *game)
{
	int	next_y;
	int	next_x;

	next_y = game->player.y_char;
	next_x = game->player.x_char - 1;
	check_next_tile(game, game->map.map[next_y][next_x], 'l');
	game->player.current_direction = LEFT;
	mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
		game->sprite_left, game->player.x_char * TILE_SIZE, game->player.y_char
		* TILE_SIZE);
	if (game->map.map[next_y][next_x] == 'G')
	{
		game_over_enemy(game);
		return ;
	}
	else if (game->map.map[next_y][next_x] == '0')
		update_display(game, 0, -1);
	move_left2(game, next_y, next_x);
}

void	move_left2(t_game *game, int next_y, int next_x)
{
	if (game->map.map[next_y][next_x] == 'C')
	{
		game->map.map[next_y][next_x] = '0';
		update_display(game, 0, -1);
		game->player.inventory++;
		if (game->player.inventory == game->map.item_count)
			load_exit(game);
	}
	else if (game->map.map[next_y][next_x] == 'E')
	{
		if (game->player.inventory == game->map.item_count)
		{
			mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
				game->sprite_up, next_x * TILE_SIZE, next_y * TILE_SIZE);
			mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
				game->floor.img, game->player.x_char * TILE_SIZE,
				game->player.y_char * TILE_SIZE);
			game->player.y_char = next_y;
			move_counter(game, 1);
		}
	}
}

void	move_right(t_game *game)
{
	int	next_y;
	int	next_x;

	next_y = game->player.y_char;
	next_x = game->player.x_char + 1;
	check_next_tile(game, game->map.map[next_y][next_x], 'r');
	game->player.current_direction = RIGHT;
	mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
		game->sprite_right, game->player.x_char * TILE_SIZE, game->player.y_char
		* TILE_SIZE);
	if (game->map.map[next_y][next_x] == 'G')
	{
		game_over_enemy(game);
		return ;
	}
	else if (game->map.map[next_y][next_x] == '0')
		update_display(game, 0, +1);
	move_right2(game, next_y, next_x);
}

void	move_right2(t_game *game, int next_y, int next_x)
{
	if (game->map.map[next_y][next_x] == 'C')
	{
		game->map.map[next_y][next_x] = '0';
		update_display(game, 0, +1);
		game->player.inventory++;
		if (game->player.inventory == game->map.item_count)
			load_exit(game);
	}
	else if (game->map.map[next_y][next_x] == 'E')
	{
		if (game->player.inventory == game->map.item_count)
		{
			mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
				game->sprite_up, next_x * TILE_SIZE, next_y * TILE_SIZE);
			mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
				game->floor.img, game->player.x_char * TILE_SIZE,
				game->player.y_char * TILE_SIZE);
			game->player.y_char = next_y;
			move_counter(game, 1);
		}
	}
}
