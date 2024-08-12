/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc <hzakharc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 17:07:20 by hzakharc          #+#    #+#             */
/*   Updated: 2024/02/11 16:53:54 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H
# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	print_error(void);
int		checkarg(char *str);
int		*char_to_nums(char *str);
void	set_zero(int **array);
int		**create_map(void);
void	free_map(int **array);
void	free_nums(int *nums);
void	set_arg(int **map, int *array);

#endif