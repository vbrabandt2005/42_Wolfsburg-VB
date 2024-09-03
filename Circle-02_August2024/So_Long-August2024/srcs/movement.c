/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:58:40 by vbraband          #+#    #+#             */
/*   Updated: 2024/09/03 14:27:54 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_up(t_game *game)
{
	int next_y = game->player.y_char - 1;
	int next_x = game->player.x_char;

	check_next_tile(game, game->map.map[next_y][next_x], 'u');
	game->player.current_direction = UP;
	mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
		game->sprite_up, game->player.x_char * TILE_SIZE, game->player.y_char * TILE_SIZE);
	if (game->map.map[next_y][next_x] == 'G')
	{
		game_over_enemy(game);
		return;
	}
	else if (game->map.map[next_y][next_x] == '0')
	{
		update_display(game, -1, 0);
	}
	else if (game->map.map[next_y][next_x] == 'C')
	{
		game->map.map[next_y][next_x] = '0';
		update_display(game, -1, 0);
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
				game->floor.img, game->player.x_char * TILE_SIZE, game->player.y_char * TILE_SIZE);
			game->player.y_char = next_y;
			move_counter(game, 1);
		}
	}
}

void move_down(t_game *game)
{
	int next_y = game->player.y_char + 1;
	int next_x = game->player.x_char;

	check_next_tile(game, game->map.map[next_y][next_x], 'd');
	game->player.current_direction = DOWN;
	mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
		game->sprite_down, game->player.x_char * TILE_SIZE, game->player.y_char * TILE_SIZE);
	if (game->map.map[next_y][next_x] == 'G')
	{
		game_over_enemy(game);
		return;
	}
	else if (game->map.map[next_y][next_x] == '0')
	{
		update_display(game, +1, 0);
	}
	else if (game->map.map[next_y][next_x] == 'C')
	{
		game->map.map[next_y][next_x] = '0';
		update_display(game, +1, 0);
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
				game->floor.img, game->player.x_char * TILE_SIZE, game->player.y_char * TILE_SIZE);
			game->player.y_char = next_y;
			move_counter(game, 1);
		}
	}
}

void move_left(t_game *game)
{
	int next_y = game->player.y_char;
	int next_x = game->player.x_char - 1;

	check_next_tile(game, game->map.map[next_y][next_x], 'l');
	game->player.current_direction = LEFT;
	mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
		game->sprite_left, game->player.x_char * TILE_SIZE, game->player.y_char * TILE_SIZE);
	if (game->map.map[next_y][next_x] == 'G')
	{
		game_over_enemy(game);
		return;
	}
	else if (game->map.map[next_y][next_x] == '0')
	{
		update_display(game, 0, -1);
	}
	else if (game->map.map[next_y][next_x] == 'C')
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
				game->floor.img, game->player.x_char * TILE_SIZE, game->player.y_char * TILE_SIZE);
			game->player.y_char = next_y;
			move_counter(game, 1);
		}
	}
}

void move_right(t_game *game)
{
	int next_y = game->player.y_char;
	int next_x = game->player.x_char + 1;

	check_next_tile(game, game->map.map[next_y][next_x], 'r');
	game->player.current_direction = RIGHT;
	mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
		game->sprite_right, game->player.x_char * TILE_SIZE, game->player.y_char * TILE_SIZE);
	if (game->map.map[next_y][next_x] == 'G')
	{
		game_over_enemy(game);
		return;
	}
	else if (game->map.map[next_y][next_x] == '0')
	{
		update_display(game, 0, +1);
	}
	else if (game->map.map[next_y][next_x] == 'C')
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
				game->floor.img, game->player.x_char * TILE_SIZE, game->player.y_char * TILE_SIZE);
			game->player.y_char = next_y;
			move_counter(game, 1);
		}
	}
}
