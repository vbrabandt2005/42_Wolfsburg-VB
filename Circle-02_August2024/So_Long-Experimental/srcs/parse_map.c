/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:58:32 by vbraband          #+#    #+#             */
/*   Updated: 2024/09/02 14:09:12 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_type(char *map)
{
	char	*type;
	char	*ext;

	ext = ".ber";
	type = ft_substr(map, (ft_strlen(map) - 4), 4);
	if (ft_strncmp(type, ext, ft_strlen(type)) != 0)
	{
		free(type);
		return (0);
	}
	free (type);
	return (1);
}

t_game	*valid_map(char *mappy, t_game *game)
{
    if (!check_type(mappy))
    {
        ft_nomap(game, "Please provide a map with a valid extension");
        return (0);
    }
    if (!map_init(mappy, game))
    {
        ft_nomap(game, "This map is invalid! Please provide a valid map");
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