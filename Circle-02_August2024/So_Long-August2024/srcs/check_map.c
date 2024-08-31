/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:51:55 by acloos            #+#    #+#             */
/*   Updated: 2024/08/22 16:18:41 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
This function records the numbers of special characters: player, items and exits
If this number is not valid, it displays the appropriate warning
*/

int	check_char(char iji, t_game *game)
{
	char	*char_ok;

	char_ok = "01EPC";
	if (iji == 'P')
		game->map.hero_count++;
	if (iji == 'E')
		game->map.exit_count++;
	if (iji == 'C')
		game->map.item_count++;
	if (!ft_strchr(char_ok, iji))
	{
		ft_error(game, "This map contains invalid character(s)!\n\
		Valid characters are : 0 1 P E C\n\
		Please provide a valid map.\n");
		return (0);
	}
	if (game->map.hero_count > 1 || game->map.exit_count > 1)
	{
		if (game->map.hero_count > 1)
			ft_error(game, "This is not a multi-player game !");
		else if (game->map.exit_count > 1)
			ft_error(game, "Swiss cheese is not a valid map !");
		return (0);
	}
	return (1);
}
/*
This function goes through the map and verifies every character 
with check_char()
*/

int	valid_char(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (i < game->map.col_size - 1)
	{
		j = 0;
		while (game->map.map[i][j] != '\n')
		{
			if (!check_char(game->map.map[i][j], game))
				return (0);
			j++;
		}
		i++;
	}
	if (!mission_ready(game))
		return (0);
	return (1);
}

/*
This function checks whether the map is fully enclosed with walls
	- checks all of 1st and last line
	- checks first and last character of all intermediate lines
*/

int	closed_up(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map.col_size && j < game->map.line_size)
	{
		while (j < game->map.line_size)
		{
			if (game->map.map[i][0] != '1' ||
				game->map.map[i][game->map.line_size - 1] != '1' ||
				game->map.map[0][j] != '1' ||
				game->map.map[game->map.col_size - 1][j] != '1')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

/*
This function checks the shape of the map (has to be rectangular)
It does so by checking that all lines have the same length as the first
That's why you can't have any empty line
*/

int	shape(t_game *game)
{
	int	i;
	int	check;

	i = 0;
	check = game->map.line_size;
	while (++i < game->map.col_size - 1)
	{
		if (game->map.map[i][0] == '\n')
			return (0);
		if (!(game->map.map[i][check - 1] && game->map.map[i][check] == '\n'))
			return (0);
	}
	if (game->map.map[i][check] != 0)
	{
		if (game->map.map[i][check] == 'n' && game->map.map[i][check + 1] != 0)
			return (0);
	}
	return (1);
}

/*
This function is a hub to check everything else
*/

int	check_map(t_game *game)
{
	if (!shape(game))
	{
		ft_error(game, "Please provide a rectangular map");
		return (0);
	}
	if (!closed_up(game))
	{
		ft_error(game, "please provide closed map");
		return (0);
	}
	if (!valid_char(game))
		return (0);
	return (1);
}
