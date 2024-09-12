/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:57:36 by vbraband          #+#    #+#             */
/*   Updated: 2024/09/12 13:02:57 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_tiles(t_game *game, int x_map, int y_map)
{
	char	tile;

	tile = game->map.map[y_map][x_map];
	if (tile == '1')
		mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
			game->wall.img, x_map * TILE_SIZE, y_map * TILE_SIZE);
	else if (tile == '0')
		mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
			game->floor.img, x_map * TILE_SIZE, y_map * TILE_SIZE);
	else if (tile == 'P')
		load_player_tile(game, x_map, y_map);
	else if (tile == 'G')
		mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
			game->enemy_sprite, x_map * TILE_SIZE, y_map * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
			game->exit.img, x_map * TILE_SIZE, y_map * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
			game->item.img, x_map * TILE_SIZE, y_map * TILE_SIZE);
}

void	load_player_tile(t_game *game, int x_map, int y_map)
{
	void	*sprites[4];
	void	*sprite_to_use;

	sprites[0] = game->sprite_up;
	sprites[1] = game->sprite_down;
	sprites[2] = game->sprite_left;
	sprites[3] = game->sprite_right;
	if (game->player.current_direction < 0
		|| game->player.current_direction > 3)
		game->player.current_direction = DOWN;
	sprite_to_use = sprites[game->player.current_direction];
	mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
		sprite_to_use, game->player.x_char * TILE_SIZE,
		game->player.y_char * TILE_SIZE);
	game->map.map[y_map][x_map] = '0';
}

void	load_exit(t_game *game)
{
	if (game->player.inventory == game->map.item_count)
	{
		mlx_destroy_image(game->window.mlx_ptr, game->exit.img);
		game->exit.img = mlx_xpm_file_to_image(game->window.mlx_ptr,
				"assets/E_Exit_open.xpm", &game->exit.bpp,
				&game->exit.size_line);
		game->exit.addr = mlx_get_data_addr(game->exit.img, &game->exit.bpp,
				&game->exit.size_line, &game->exit.endian);
		mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
			game->exit.img, (game->exit.x_tile) * TILE_SIZE, (game->exit.y_tile)
			* TILE_SIZE);
		printf("\n%s%sCapy can smell the freedom now%s\n\n", ITALICS,
			F_D_YELLOW, RESET);
	}
}

void	check_next_tile(t_game *game, int tilechar, char mod)
{
	int	x_offset;
	int	y_offset;

	if (tilechar == 'E' && game->player.inventory == game->map.item_count)
	{
		x_offset = 0;
		y_offset = 0;
		if (mod == 'u')
			y_offset = -1;
		else if (mod == 'd')
			y_offset = 1;
		else if (mod == 'l')
			x_offset = -1;
		else if (mod == 'r')
			x_offset = 1;
		mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
			game->exit.img, (game->player.x_char + x_offset) * TILE_SIZE,
			(game->player.y_char + y_offset) * TILE_SIZE);
		move_counter(game, 1);
		game_over_victory();
		mlx_map_destroyer(game);
	}
}

void	update_display(t_game *game, int next_y, int next_x)
{
	void	*sprites[4];
	void	*sprite_to_use;

	sprites[0] = game->sprite_up;
	sprites[1] = game->sprite_down;
	sprites[2] = game->sprite_left;
	sprites[3] = game->sprite_right;
	mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
		game->floor.img, (game->player.x_char) * TILE_SIZE,
		(game->player.y_char) * TILE_SIZE);
	if (game->map.map[game->player.y_char][game->player.x_char] != 'G')
		game->map.map[game->player.y_char][game->player.x_char] = '0';
	game->player.y_char += next_y;
	game->player.x_char += next_x;
	if (game->player.current_direction < 0
		|| game->player.current_direction > 3)
		game->player.current_direction = DOWN;
	sprite_to_use = sprites[game->player.current_direction];
	mlx_put_image_to_window(game->window.mlx_ptr, game->window.win_ptr,
		sprite_to_use, (game->player.x_char) * TILE_SIZE, (game->player.y_char)
		* TILE_SIZE);
	move_counter(game, 1);
}
