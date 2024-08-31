/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:51:26 by acloos            #+#    #+#             */
/*   Updated: 2024/08/26 10:28:57 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
This function records the length and size of the map in the struct
*/

void	update_size(t_game *game, int i, int j)
{
	game->map.line_size = i - 1;
	game->map.col_size = j - 1;
}

/*
This function finds the length and height of the map
*/

void	get_coord(char *mappy, t_game *game)
{
	char	*mapper;
	int		i;
	int		fd;
	int		j;

	i = 0;
	j = 0;
	mapper = "";
	fd = open(mappy, O_RDONLY);
	if (fd <= 0)
		return ;
	else
	{
		while (mappy != NULL && mapper != NULL && ++j)
		{
			mapper = get_next_line(fd);
			if (mapper && !i)
				i = ft_strlen(mapper);
			free(mapper);
		}
	}
	update_size(game, i, j);
	close(fd);
}

/*
This function fills the 'map' element of the "map" struct 
	with the map from the .ber file
*/

char	**fill_map(char *mappy, t_game *game, char **mapping)
{
	int		i;
	int		fd;
	char	*liner;

	i = 0;
	liner = "";
	fd = open(mappy, O_RDONLY);
	if (fd <= 0)
		return (0);
	else
	{
		while (mappy != NULL && liner != NULL)
		{
			while (i <= game->map.col_size)
			{
				liner = get_next_line(fd);
				if (liner)
					mapping[i] = ft_strdup(liner);
				free(liner);
				i++;
			}
		}
	}
	close(fd);
	return (mapping);
}

/*
This function is a hub to initialize the map
*/

t_game	*map_init(char *mappy, t_game *game)
{
	get_coord(mappy, game);
	if (game->map.line_size >= 3 && game->map.col_size >= 3)
	{
		game->map.map = malloc(sizeof(char) * (game->map.line_size + 1) * \
			(game->map.col_size + 1) + 1);
		if (!game->map.map)
			return (0);
		else
			game->map.map = fill_map(mappy, game, game->map.map);
	}
	else
		return (0);
	return (game);
}
