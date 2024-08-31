/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:51:48 by acloos            #+#    #+#             */
/*   Updated: 2024/08/26 11:53:39 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
This function checks whether the file ends with the correct extension
It's fine if the name contains ALSO the extension within its name
But it HAS TO end with the correct extension

*/

int	check_xt(char *map)
{
	char	*name_end;
	char	*ext;

	ext = ".ber";
	name_end = ft_substr(map, (ft_strlen(map) - 4), 4);
	if (ft_strncmp(name_end, ext, ft_strlen(name_end)) != 0)
	{
		free(name_end);
		return (0);
	}
	free(name_end);
	return (1);
}

t_game	*valid_map(char *mappy, t_game *game)
{
	if (!check_xt(mappy))
	{
		ft_nomap(game, "Please provide a map with a valid extension");
		return (0);
	}
	if (!map_init(mappy, game))
	{
		ft_nomap(game, "The map is a lie !\nPlease provide a map.");
		return (0);
	}
	if (!check_map(game))
		return (0);
	if (!flood_it(game))
		return (0);
	if (game->map.map)
		map_destroyer(game);
	map_init(mappy, game);
	return (game);
}
