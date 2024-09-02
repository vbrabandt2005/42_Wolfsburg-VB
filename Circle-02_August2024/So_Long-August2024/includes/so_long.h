/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:04:32 by bjbogisc          #+#    #+#             */
/*   Updated: 2024/09/02 13:14:20 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>

/* Custom Liberies */
# include "../lib/MiniLibX/mlx.h"
# include "../lib/MiniLibX/mlx_int.h"
# include "../lib/Libft_Modified-2024/srcs/libft.h"

/* Additional includes */
# include "ansi_colors.h"
# include "structs.h"
# include "linux_keys.h"

# define NUM_ANIMATIONS 4
# define WIN_NAM 		"Capy vs. Pelican"
# define WALL 			'1'
# define FLOOR 			'0'
# define START 			'P'
# define EXIT 			'E'
# define COLLECT 		'C'

# ifndef WIN_W
#  define WIN_W 480
# endif

# ifndef WIN_H
#  define WIN_H 640
# endif

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

/* --- check_map.c --- */
int			check_char(char check, t_game *game);
int			valid_char(t_game *game);
int			valid_walls(t_game *game);
int			valid_shape(t_game *game);
int			check_map(t_game *game);

/* --- check_pos.c --- */
void		player_pos(int i, int j, t_game *game);
void		exit_pos(int i, int j, t_game *game);
t_game		*elem_pos(t_game *game);
int			mission_ready(t_game *game);

/* --- closing.c --- */
void		map_destroyer(t_game *game);
void		mlx_img_destroyer(t_game *game);
void		mlx_destroyer(t_game *game);
int			mlx_map_destroyer(t_game *game);

/* --- end_game.c --- */
void		game_over(void);
void		game_over_vis(void);
void		game_over_victory(void);
void	game_over_enemy(t_game *game);

/* --- error.c --- */
int			ft_nomap(t_game *game, char *err_msg);
int			ft_error(t_game *game, char *err_msg);

/* --- events.c --- */
int			key_press(int keycode, t_game *game);
void		motion(int keycode, t_game *game);
int			closing(t_game *game);

/* --- fill_window.c --- */
void		flooder(t_game *game, t_map size, t_character charpos, char filler);
void		dam(t_game *game, t_map size, t_character charpos);
int			check_collect(t_game *game, int item, int exit);
int			flood_it(t_game *game);

/* --- init_game.c --- */
int			init_window(t_game *game);
int			init_char(t_game *game);
int			init_map(t_game *game);
int			init_tile(t_game *game);
int			init_game_structs(t_game *game);

/* --- init_map.c --- */
void		update_size(t_game *game, int i, int j);
void		coord(char *mappy, t_game *game);
char		**fill_map(char *mappy, t_game *game, char **mapping);
t_game		*map_init(char *mappy, t_game *game);

/* --- init_tiles.c --- */
int			init_player(t_game *game);
int			init_item(t_game *game);
int			init_exit(t_game *game);
int			init_floor(t_game *game);
int			init_wall(t_game *game);

/* --- movement.c --- */
void		move_up(t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_right(t_game *game);
void		move_counter(t_game *game, int steps);

/* --- parse_map.c --- */
int			check_type(char *map);
t_game		*valid_map(char *mappy, t_game *game);

/* --- start_game.c --- */
void		display_map(t_game *game);
void		display_game(t_game *game);
int			start_game(t_game *game);

/* --- tiles.c --- */
void		load_tiles(t_game *game, int x_map, int y_map);
void		load_exit(t_game *game);
void		check_next_tile(t_game *game, int tilechar, char mod);
void		update_display(t_game *game, int next_y, int next_x);

/* --- xpm_assets.c --- */
int			xpm_check(t_game *game);
int			xpm_addr(t_game *game);
t_game		*xpm_load(t_game *game);

#endif