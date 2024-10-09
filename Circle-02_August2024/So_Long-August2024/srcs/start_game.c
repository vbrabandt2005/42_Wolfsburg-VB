/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:58:22 by vbraband          #+#    #+#             */
/*   Updated: 2024/09/25 16:31:39 by vbrabandt        ###   ########.fr       */
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
	mlx_hook(game->window.win_ptr, 2, KeyPressMask, key_press, game);
	mlx_hook(game->window.win_ptr, ClientMessage, LeaveWindowMask,
		mlx_map_destroyer, game);
	mlx_loop(game->window.mlx_ptr);
}

int	start_game(t_game *game)
{
	printf("\n\t --Execute Operation Capybara freedom!--\n\n");
	game->window.mlx_ptr = mlx_init();
	if (!game->window.mlx_ptr)
	{
		ft_error(game, "Could not start MLX");
		return (0);
	}
	game->window.x_win = game->map.line_size * TILE_SIZE;
	game->window.y_win = game->map.col_size * TILE_SIZE;
	game->window.win_ptr = mlx_new_window(game->window.mlx_ptr,
			game->window.x_win, game->window.y_win, "Free Capybara!");
	if (!game->window.win_ptr)
	{
		mlx_destroy_window(game->window.mlx_ptr, game->window.win_ptr);
		mlx_destroy_display(game->window.mlx_ptr);
		free(game->window.mlx_ptr);
		ft_error(game, "Could not open game window");
		return (0);
	}
	if (xpm_load(game))
		display_game(game);
	return (1);
}

/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣬⠷⣶⡖⠲⡄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣠⠶⠋⠁⠀⠸⣿⡀⠀⡁⠈⠙⠢⠤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢠⠞⠁⠀⠀⠀⠀⠀⠉⠣⠬⢧⠀⠀⠀⠀⠈⠻⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⢀⡴⠃⠀⠀⢠⣴⣿⡿⠀⠀⠀⠐⠋⠀⠀⠀⠀⠀⠀⠘⠿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⢀⡴⠋⠀⠀⠀⠀⠈⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠒⠒⠓⠛⠓⠶⠶⢄⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⢠⠎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠦⣀⠀⠀⠀⠀⠀⠀⠀⠀
⡞⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⢷⡄⠀⠀⠀⠀⠀⠀
⢻⣇⣹⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢦⡀⠀⠀⠀⠀
⠀⠻⣟⠋⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣄⠀⠀⠀
⠀⠀⠀⠉⠓⠒⠊⠉⠉⢸⡙⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠘⣆⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣱⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣿⠀⠀⠀⠀⠀⢻⡄⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠟⣧⡀⠀⠀⢀⡄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡿⠇⠀⠀⠀⠀⠀⠀⢣⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⡧⢿⡀⠚⠿⢻⡆⠀⠀⠀⠀⠀⢠⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠘⡆
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⠀⠀⠈⢹⡀⠀⠀⠀⠀⣾⡆⠀⠀⠀⠀⠀⠀⠀⠀⠾⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠨⢷⣾⠀⠸⡷⠀⠀⠀⠘⡿⠂⠀⠀⠀⢀⡴⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡇
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡄⠳⢼⣧⡀⠀⠀⢶⡼⠦⠀⠀⠀⡞⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠃
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡇⠀⡎⣽⠿⣦⣽⣷⠿⠒⠀⠀⠀⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠁⣴⠃⡿⠀⠀⢠⠆⠢⡀⠀⠀⠀⠈⢧⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠇⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣠⠏⠀⣸⢰⡇⠀⢠⠏⠀⠀⠘⢦⣀⣀⠀⢀⠙⢧⡀⠀⠀⠀⠀⠀⠀⠀⠀⡰⠁⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠾⠿⢯⣤⣆⣤⣯⠼⠀⠀⢸⠀⠀⠀⠀⠀⣉⠭⠿⠛⠛⠚⠟⡇⠀⠀⣀⠀⢀⡤⠊⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠀⢸⣷⣶⣤⣦⡼⠀⠀⠀⣴⣯⠇⡀⣀⣀⠤⠤⠖⠁⠐⠚⠛⠉⠁⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣛⠁⢋⡀⠀⠀⠀⠀⣛⣛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
*/