/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:54:34 by vbraband          #+#    #+#             */
/*   Updated: 2024/09/02 14:10:46 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_destroyer(t_game *game)
{
    int	i;

    i = 0;
    while (i < game->map.col_size)
    {
        free(game->map.map[i]);
        i++;
    }
    free(game->map.map);
}

void	mlx_img_destroyer(t_game *game)
{
    if (game->sprite_down)
        mlx_destroy_image(game->window.mlx_ptr, game->sprite_down);
    if (game->item.img)
        mlx_destroy_image(game->window.mlx_ptr, game->item.img);
    if (game->exit.img)
        mlx_destroy_image(game->window.mlx_ptr, game->exit.img);
    if (game->floor.img)
        mlx_destroy_image(game->window.mlx_ptr, game->floor.img);
    if (game->wall.img)
        mlx_destroy_image(game->window.mlx_ptr, game->wall.img);
}

void	mlx_destroyer(t_game *game)
{
    mlx_img_destroyer(game);
    mlx_destroy_window(game->window.mlx_ptr, game->window.win_ptr);
    mlx_destroy_display(game->window.mlx_ptr);
    free(game->window.mlx_ptr);
}

int	mlx_map_destroyer(t_game *game)
{
    mlx_img_destroyer(game);
    mlx_destroy_window(game->window.mlx_ptr, game->window.win_ptr);
    mlx_destroy_display(game->window.mlx_ptr);
    free(game->window.mlx_ptr);
    map_destroyer(game);
    free(game);
    exit(EXIT_SUCCESS);
}
