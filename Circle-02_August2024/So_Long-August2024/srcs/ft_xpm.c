/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xpm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:36:55 by vbraband          #+#    #+#             */
/*   Updated: 2024/08/28 17:36:59 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	xpm_check(t_game *game)
{
	if (!game->hero.img || !game->item.img || !game->exit.img || \
		!game->floor.img || !game->wall.img)
	{
		mlx_img_destroyer(game);
		mlx_destroy_window(game->show.mlx_ptr, game->show.win_ptr);
		mlx_destroy_display(game->show.mlx_ptr);
		free(game->show.mlx_ptr);
		ft_error(game, "Could not load xpm files");
		return (0);
	}
	return (1);
}

int	xpm_addr(t_game *game)
{
	game->hero.addr = mlx_get_data_addr(game->hero.img, \
		&game->hero.bits_per_pixel, &game->hero.size_line, &game->hero.endian);
	game->item.addr = mlx_get_data_addr(game->item.img, \
		&game->item.bits_per_pixel, &game->item.size_line, &game->item.endian);
	game->exit.addr = mlx_get_data_addr(game->exit.img, \
		&game->exit.bits_per_pixel, &game->exit.size_line, &game->exit.endian);
	game->floor.addr = mlx_get_data_addr(game->floor.img, \
		&game->floor.bits_per_pixel, &game->floor.size_line, \
		&game->floor.endian);
	game->wall.addr = mlx_get_data_addr(game->wall.img, \
		&game->wall.bits_per_pixel, &game->wall.size_line, &game->wall.endian);
	return (1);
}

t_game	*xpm_load(t_game *game)
{
	game->hero.img = mlx_xpm_file_to_image(game->show.mlx_ptr, \
		"assets/P_hero.xpm", &game->hero.bits_per_pixel, &game->hero.size_line);
	game->item.img = mlx_xpm_file_to_image(game->show.mlx_ptr, \
		"assets/C_item.xpm", &game->item.bits_per_pixel, &game->item.size_line);
	game->exit.img = mlx_xpm_file_to_image(game->show.mlx_ptr, \
		"assets/E_exit_closed.xpm", &game->exit.bits_per_pixel, \
		&game->exit.size_line);
	game->floor.img = mlx_xpm_file_to_image(game->show.mlx_ptr, \
		"assets/0_floor.xpm", &game->floor.bits_per_pixel, \
		&game->floor.size_line);
	game->wall.img = mlx_xpm_file_to_image(game->show.mlx_ptr, \
		"assets/1_wall.xpm", &game->wall.bits_per_pixel, &game->wall.size_line);
	if (!xpm_check(game))
		return (0);
	if (!xpm_addr(game))
	{
		ft_error(game, "Could not find xpm address");
		return (0);
	}
	return (game);
}
