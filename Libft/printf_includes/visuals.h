/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visuals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 02:22:45 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/02/12 21:03:01 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALS_H
# define VISUALS_H

# include "libft.h"
# include "specifier_handlers.h"
# include "extra.h"

struct			s_visual
{
	const char	*id;
	int			code;
};
typedef struct s_visual	t_visual;

struct			s_state_visual
{
	int	text_type;
	int	fgnd;
	int	bgnd;
};

typedef struct s_state_visual	t_state_visual;

# define VISUAL_SPEC_OPEN '{'
# define VISUAL_SPEC_CLOSE '}'
# define VISUAL_SPEC_SEPARATOR ','

# define VISUAL_START "\x1b["
# define VISUAL_END "m"
# define VISUAL_SEPARATOR ";"

# define ERROR_VISUAL_ID NULL
# define ERROR_VISUAL_CODE -3
# define NONE_VISUAL_ID ""
# define NONE_VISUAL_CODE -2
# define RESET_VISUALS_ID "reset"
# define RESET_VISUALS_CODE 0
# define DEFAULT_VISUALS_ID "default"
# define DEFAULT_VISUALS_CODE 0
# define END_OF_VISUAL_ID "eov"
# define END_OF_VISUAL_CODE -1

# define BOLD_ID "bold"
# define BOLD_CODE 1
# define HALF_BRIGHT_ID "half_bright"
# define HALF_BRIGHT_CODE 2
# define UNDERSCORE_ID "underscore"
# define UNDERSCORE_CODE 4
# define BLINK_ID "blink"
# define BLINK_CODE 5
# define REVERSE_VIDEO_ID "reverse_video"
# define REVERSE_VIDEO_CODE 7
# define INVISIBLE_ID "invisible"
# define INVISIBLE_CODE 8

# define BLACK_F_ID "black_f"
# define BLACK_F_CODE 30
# define RED_F_ID "red_f"
# define RED_F_CODE 31
# define GREEN_F_ID "green_f"
# define GREEN_F_CODE 32
# define YELLOW_F_ID "yellow_f"
# define YELLOW_F_CODE 33
# define BLUE_F_ID "blue_f"
# define BLUE_F_CODE 34
# define MAGENTA_F_ID "magenta_f"
# define MAGENTA_F_CODE 35
# define CYAN_F_ID "cyan_f"
# define CYAN_F_CODE 36
# define WHITE_F_ID "white_f"
# define WHITE_F_CODE 37

# define BLACK_B_ID "black_b"
# define BLACK_B_CODE 40
# define RED_B_ID "red_b"
# define RED_B_CODE 41
# define GREEN_B_ID "green_b"
# define GREEN_B_CODE 42
# define YELLOW_B_ID "yellow_b"
# define YELLOW_B_CODE 43
# define BLUE_B_ID "blue_b"
# define BLUE_B_CODE 42
# define MAGENTA_B_ID "magenta_b"
# define MAGENTA_B_CODE 45
# define CYAN_B_ID "cyan_b"
# define CYAN_B_CODE 46
# define WHITE_B_ID "white_b"
# define WHITE_B_CODE 47

int				is_same(const char *id, const char *other_id);

int				is_text_type_visual(int code);
int				is_fgnd_visual(int code);
int				is_bgnd_visual(int code);

t_state_visual	create_state_base_of(int new_code, t_extra *base);
char			*create_state_string(t_list *lst_state_node);

t_visual		get_visual(const char *id);

int				visuals_handler(char **format, va_list args_list,
									t_buffer *buffer, t_extra *extra);

#endif
