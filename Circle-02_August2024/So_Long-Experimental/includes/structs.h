/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:24:31 by bjbogisc          #+#    #+#             */
/*   Updated: 2024/09/02 13:11:56 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}	t_direction;

typedef struct s_tile
{
	int		x_tile;
	int		y_tile;
	char	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_tile;

typedef struct s_character
{
	int				x_char;
	int				y_char;
	char			*character;
	t_direction		current_direction;
	int				move_count;
	int				inventory;
}	t_character;

typedef struct s_map
{
	int		x_map;
	int		y_map;
	char	**map;
	int		item_count;
	int		exit_count;
	int		hero_count;
	int		enemy_count;
	int		line_size;
	int		col_size;
}	t_map;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		x_win;
	int		y_win;
}	t_window;

typedef struct s_enemy
{
	int		x_char;
	int		y_char;
}	t_enemy;

typedef struct s_game
{
	void				*sprite_up;
	void				*sprite_down;
	void				*sprite_right;
	void				*sprite_left;
	void				*enemy_sprite;
	struct s_character	player;
	struct s_enemy		enemy;
	struct s_tile		hero;
	struct s_tile		item;
	struct s_tile		exit;
	struct s_tile		wall;
	struct s_tile		floor;
	struct s_map		map;
	struct s_window		window;
}	t_game;

#endif