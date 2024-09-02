/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:54:18 by vbraband          #+#    #+#             */
/*   Updated: 2024/09/02 13:54:19 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_char(char check, t_game *game)
{
	char	*valid;

	valid = "01EPCG";
	if (check == 'P')
		game->map.hero_count++;
	if (check == 'E')
		game->map.exit_count++;
	if (check == 'C')
		game->map.item_count++;
	if (check == 'G')
		game->map.enemy_count++;
	if (!ft_strchr(valid, check))
	{
		ft_error(game, "This map contains invalid character(s)!\n\
		Valid characters are: 0 1 P E C G\n\
		Please provide a valid map.\n");
		return (0);
	}
	if (game->map.hero_count > 1 || game->map.exit_count > 1)
	{
		if (game->map.hero_count > 1)
			ft_error(game, "Its only Cali's Adventure!");
		else if (game->map.exit_count > 1)
			ft_error(game, "There can only be one Way!");
		return (0);
	}
	return (1);
}

int	valid_char(t_game *game)
{
	int		i;
	int		j;

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

int	valid_walls(t_game *game)
{
	int		i;
	int		j;

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

int	valid_shape(t_game *game)
{
	int		i;
	int		check;

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

int	check_map(t_game *game)
{
	if (!valid_shape(game))
	{
		ft_error(game, "Please provide a rectangular shaped map!");
		return (0);
	}
	if (!valid_walls(game))
	{
		ft_error(game, "Please provide a Consealed map!");
		return (0);
	}
	if (!valid_char(game))
		return (0);
	return (1);
}

// int valid_shape(t_map_line *map_head)
// {
//     t_map_line *current;
//     size_t line_length;
//     int first_line = 1;

//     if (!map_head || !map_head->line)
//         return (0);

//     line_length = strlen(map_head->line);
//     current = map_head;

//     while (current)
//     {
//         if (!current->line || current->line[0] == '\0')
//             return (0);

//         if (strlen(current->line) != line_length)
//             return (0);

//         if (first_line || !current->next)
//         {
//             for (size_t i = 0; i < line_length; i++)
//             {
//                 if (current->line[i] != '1')
//                     return (0);
//             }
//         }
//         else
//         {
//             if (current->line[0] != '1' || current->line[line_length - 1] != '1')
//                 return (0);
//         }

//         first_line = 0;
//         current = current->next;
//     }

//     return (1);
// }