/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ansi_colors.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:51:36 by acloos            #+#    #+#             */
/*   Updated: 2024/09/02 13:12:10 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANSI_COLORS_H
# define ANSI_COLORS_H

# include<signal.h>
# include<unistd.h>
# include<stdlib.h>
# include<sys/types.h>
# include "../lib/Libft_Modified-2024/srcs/libft.h"

//reset & defaults
# define RESET "\033[0m" //reset
# define F_DEFAULT "\033[39m"//default foreground color (implementation defined)
# define B_DEFAULT "\033[49m"//default background color (implementation defined)
# define FONT_DEFAULT "\033[10m" //default font

//basics
# define BOLD "\033[1m" //bold, increased intensity
# define DIM "\033[2m" //dim, faint, decreased intensity
# define ITALICS "\033[3m" //italics, NWS, sometimes treated as inverse
# define UNDER "\033[4m" //underline

//uncommon
# define UNDER_DOUBLE "\033[21m" //bold off OR double underline, NWS
# define SLOW_BLINK "\033[5m" //less 150 per minute
# define QUICK_BLINK "\033[6m" //150+ per minute, NWS ; not supported @42 ..?
# define STRIKED_SWAP "\033[7m" //strike-through, 
//OR swap foreground/background colors
# define CONCEAL "\033[8m" //conceal, NWS
# define HIDDEN_CROSSED "\033[9m" //crossed 
//OR characters legible but marked for deletion, NWS
# define OVERLINE "\033[53m" //overlined

//settings off
# define OFF_ITAL_FRAKT "\033[23m" //not italic nor fraktur
# define OFF_UNDERS "\033[24m" //underline off and double underline off
# define OFF_BLINKS "\033[25m" //slow blink off and quick blink off
# define OFF_STRIKED_SWAP "\033[27m" //inverse off OR swapping off
# define OFF_CONCEAL "\033[28m" //reveal, conceal off
# define OFF_HIDDEN_CROSSED "\033[29m" //crossed off OR deletion off
# define OFF_OVERLINE "\033[55m" //overlined off

//fonts
# define ALT_FONT01 "\033[11m" //alternate font, NWS
# define ALT_FONT02 "\033[12m" //alternate font, NWS
# define ALT_FONT03 "\033[13m" //alternate font, NWS
# define ALT_FONT04 "\033[14m" //alternate font, NWS
# define ALT_FONT05 "\033[15m" //alternate font, NWS
# define ALT_FONT06 "\033[16m" //alternate font, NWS
# define ALT_FONT07 "\033[17m" //alternate font, NWS
# define ALT_FONT08 "\033[18m" //alternate font, NWS
# define ALT_FONT09 "\033[19m" //alternate font, NWS
# define FRAKTUR "\033[20m" //fraktur font, NWS

//set Foregroung or Background color with 256-bits codes or RGB model
# define F_SETNBR "\033[38m" //set foreground color
# define B_SETNBR "\033[48m" //set background color
//next arguments are 5;n (where n is the color number from 256 colors)
//or 2;r;g;b
//for instance, for orchid color : \033[38;5;170m OR \033[38;2;215;95;215m

//to combine foreground and background colors in one line, do (for instance):
//	\033[31m\033[44m

//foreground darker colors
# define F_D_BLACK "\033[30m" //foreground dark black
# define F_D_RED "\033[31m" //foreground dark red
# define F_D_GREEN "\033[32m" //foreground dark green
# define F_D_YELLOW "\033[33m" //foreground dark yellow/orange
# define F_D_BLUE "\033[34m" //foreground dark blue
# define F_D_MAGENTA "\033[35m" //foreground dark magenta
# define F_D_CYAN "\033[36m" //foreground dark cyan
# define F_D_GREY "\033[37m" //foreground dark grey

//background darker colors
# define B_D_BLACK "\033[40m" //background dark black
# define B_D_RED "\033[41m" //background dark red
# define B_D_GREEN "\033[42m" //background dark green
# define B_D_YELLOW "\033[43m" //background dark yellow/orange
# define B_D_BLUE "\033[44m" //background dark blue
# define B_D_MAGENTA "\033[45m" //background dark magenta
# define B_D_CYAN "\033[46m" //background dark cyan
# define B_D_GREY "\033[47m" //background dark grey

//foreground lighter colors
# define F_L_BLACK "\033[90m" //foreground light black/dark grey
# define F_L_RED "\033[91m" //foreground light red
# define F_L_GREEN "\033[92m" //foreground light green
# define F_L_YELLOW "\033[93m" //foreground light yellow
# define F_L_BLUE "\033[94m" //foreground light blue
# define F_L_MAGENTA "\033[95m" //foreground light magenta
# define F_L_CYAN "\033[96m" //foreground light cyan
# define F_L_GREY "\033[97m" //foreground light grey/white

//background lighter colors
# define B_L_BLACK "\033[100m" //background light black/dark grey
# define B_L_RED "\033[101m" //background light red
# define B_L_GREEN "\033[102m" //background light green
# define B_L_YELLOW "\033[103m" //background light yellow
# define B_L_BLUE "\033[104m" //background light blue
# define B_L_MAGENTA "\033[105m" //background light magenta
# define B_L_CYAN "\033[106m" //background light cyan
# define B_L_GREY "\033[107m" //background light grey/white

#endif
