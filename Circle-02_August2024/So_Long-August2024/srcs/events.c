/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:54:58 by vbraband          #+#    #+#             */
/*   Updated: 2024/09/02 13:54:59 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == K_ESC)
		mlx_map_destroyer(game);
	else
		motion(keycode, game);
	return (0);
}

void	motion(int keycode, t_game *game)
{
	if (keycode == K_W || keycode == K_ARRUP)
		move_up(game);
	else if (keycode == K_S || keycode == K_ARRDWN)
		move_down(game);
	else if (keycode == K_A || keycode == K_ARRLFT)
		move_left(game);
	else if (keycode == K_D || keycode == K_ARRRGT)
		move_right(game);
}

int	closing(t_game *game)
{
	mlx_map_destroyer(game);
	return (0);
}
