/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:59:52 by acloos            #+#    #+#             */
/*   Updated: 2024/08/28 12:11:08 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.line_size)
	{
		y = 0;
		while (y < game->map.col_size)
		{
			load_tiles(game, x, y);
			y++;
		}
		x++;
	}
}

void	display_game(t_game *game)
{
	display_map(game);
	mlx_hook(game->show.win_ptr, 2, KeyPressMask, kb_input, game);
	mlx_hook(game->show.win_ptr, ClientMessage, LeaveWindowMask, \
		mlx_map_destroyer, game);
	mlx_loop(game->show.mlx_ptr);
}

int	start_game(t_game *game)
{
	ft_printf("\n\tHelp Capy go home!!!\n\n");
	game->show.mlx_ptr = mlx_init();
	if (!game->show.mlx_ptr)
	{
		ft_error(game, "Could not start mlx");
		return (0);
	}
	game->show.x_win = game->map.line_size * TILE_SIZE;
	game->show.y_win = game->map.col_size * TILE_SIZE;
	game->show.win_ptr = mlx_new_window(game->show.mlx_ptr, game->show.x_win, \
		game->show.y_win, "So_long");
	if (!game->show.win_ptr)
	{
		mlx_destroy_display(game->show.mlx_ptr);
		free(game->show.mlx_ptr);
		ft_error(game, "Could not open game window");
		return (0);
	}
	if (xpm_load(game))
		display_game(game);
	return (1);
}
