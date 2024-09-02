/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:57:27 by vbraband          #+#    #+#             */
/*   Updated: 2024/09/02 14:15:47 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	xpm_check(t_game *game)
{
	if (!game->item.img || !game->exit.img || !game->floor.img
		|| !game->wall.img || !game->sprite_up || !game->sprite_down
		|| !game->sprite_left || !game->sprite_right)
	{
		mlx_img_destroyer(game);
		mlx_destroy_window(game->window.mlx_ptr, game->window.win_ptr);
		mlx_destroy_display(game->window.mlx_ptr);
		free(game->window.mlx_ptr);
		ft_error(game, "Could not load XPM files");
		return (0);
	}
	return (1);
}

int	xpm_addr(t_game *game)
{
	game->item.addr = mlx_get_data_addr(game->item.img, &game->item.bpp,
			&game->item.size_line, &game->item.endian);
	game->exit.addr = mlx_get_data_addr(game->exit.img, &game->exit.bpp,
			&game->exit.size_line, &game->exit.endian);
	game->floor.addr = mlx_get_data_addr(game->floor.img, &game->floor.bpp,
			&game->floor.size_line, &game->floor.endian);
	game->wall.addr = mlx_get_data_addr(game->wall.img, &game->wall.bpp,
			&game->wall.size_line, &game->wall.endian);
	return (1);
}

t_game	*xpm_load(t_game *game)
{
	game->item.img = mlx_xpm_file_to_image(game->window.mlx_ptr,
			"assets/C_Collectible.xpm", &game->item.bpp, &game->item.size_line);
	game->exit.img = mlx_xpm_file_to_image(game->window.mlx_ptr,
			"assets/E_Exit_closed.xpm", &game->exit.bpp, &game->exit.size_line);
	game->floor.img = mlx_xpm_file_to_image(game->window.mlx_ptr,
			"assets/0_Grass_Tiles.xpm", &game->floor.bpp,
			&game->floor.size_line);
	game->wall.img = mlx_xpm_file_to_image(game->window.mlx_ptr,
			"assets/1_Wall.xpm", &game->wall.bpp, &game->wall.size_line);
	game->sprite_down = mlx_xpm_file_to_image(game->window.mlx_ptr,
			"assets/P_Player_down.xpm", &game->hero.bpp, &game->hero.size_line);
	game->sprite_up = mlx_xpm_file_to_image(game->window.mlx_ptr,
			"assets/P_Player_up.xpm", &game->hero.bpp, &game->hero.size_line);
	game->sprite_left = mlx_xpm_file_to_image(game->window.mlx_ptr,
			"assets/P_Player_left.xpm", &game->hero.bpp, &game->hero.size_line);
	game->sprite_right = mlx_xpm_file_to_image(game->window.mlx_ptr,
			"assets/P_Player_rigt.xpm", &game->hero.bpp, &game->hero.size_line);
	game->enemy_sprite = mlx_xpm_file_to_image(game->window.mlx_ptr,
			"assets/G_Guardian.xpm", &game->hero.bpp, &game->hero.size_line);
	if (!xpm_check(game))
		return (0);
	if (!xpm_addr(game))
	{
		ft_error(game, "Could not find XPM adress");
		return (0);
	}
	return (game);
}
