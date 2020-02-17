/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visuals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 02:22:45 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/02/15 17:24:18 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuals.h"

static inline t_visual	get_text_visual(const char *id)
{
	t_visual	visual;

	visual = (t_visual){NONE_VISUAL_ID, NONE_VISUAL_CODE};
	if (is_same(id, BOLD_ID))
		visual = (t_visual){BOLD_ID, BOLD_CODE};
	else if (is_same(id, HALF_BRIGHT_ID))
		visual = (t_visual){HALF_BRIGHT_ID, HALF_BRIGHT_CODE};
	else if (is_same(id, UNDERSCORE_ID))
		visual = (t_visual){NONE_VISUAL_ID, UNDERSCORE_CODE};
	else if (is_same(id, BLINK_ID))
		visual = (t_visual){BLINK_ID, BLINK_CODE};
	else if (is_same(id, REVERSE_VIDEO_ID))
		visual = (t_visual){REVERSE_VIDEO_ID, REVERSE_VIDEO_CODE};
	else if (is_same(id, INVISIBLE_ID))
		visual = (t_visual){INVISIBLE_ID, INVISIBLE_CODE};
	return (visual);
}

static inline t_visual	get_foreground_visual(const char *id)
{
	t_visual	visual;

	visual = (t_visual){NONE_VISUAL_ID, NONE_VISUAL_CODE};
	if (is_same(id, BLACK_F_ID))
		visual = (t_visual){BLACK_F_ID, BLACK_F_CODE};
	else if (is_same(id, RED_F_ID))
		visual = (t_visual){RED_F_ID, RED_F_CODE};
	else if (is_same(id, GREEN_F_ID))
		visual = (t_visual){GREEN_F_ID, GREEN_F_CODE};
	else if (is_same(id, YELLOW_F_ID))
		visual = (t_visual){YELLOW_F_ID, YELLOW_F_CODE};
	else if (is_same(id, BLUE_F_ID))
		visual = (t_visual){BLUE_F_ID, BLUE_F_CODE};
	else if (is_same(id, MAGENTA_F_ID))
		visual = (t_visual){MAGENTA_F_ID, MAGENTA_F_CODE};
	else if (is_same(id, CYAN_F_ID))
		visual = (t_visual){CYAN_F_ID, CYAN_F_CODE};
	else if (is_same(id, WHITE_F_ID))
		visual = (t_visual){WHITE_F_ID, WHITE_F_CODE};
	return (visual);
}

static inline t_visual	get_background_visual(const char *id)
{
	t_visual	visual;

	visual = (t_visual){NONE_VISUAL_ID, NONE_VISUAL_CODE};
	if (is_same(id, BLACK_B_ID))
		visual = (t_visual){BLACK_B_ID, BLACK_B_CODE};
	else if (is_same(id, RED_B_ID))
		visual = (t_visual){RED_B_ID, RED_B_CODE};
	else if (is_same(id, GREEN_B_ID))
		visual = (t_visual){GREEN_B_ID, GREEN_B_CODE};
	else if (is_same(id, YELLOW_B_ID))
		visual = (t_visual){YELLOW_B_ID, YELLOW_B_CODE};
	else if (is_same(id, BLUE_B_ID))
		visual = (t_visual){BLUE_B_ID, BLUE_B_CODE};
	else if (is_same(id, MAGENTA_B_ID))
		visual = (t_visual){MAGENTA_B_ID, MAGENTA_B_CODE};
	else if (is_same(id, CYAN_B_ID))
		visual = (t_visual){CYAN_B_ID, CYAN_B_CODE};
	else if (is_same(id, WHITE_B_ID))
		visual = (t_visual){WHITE_B_ID, WHITE_B_CODE};
	return (visual);
}

int						is_same(const char *id, const char *other_id)
{
	return (id == ft_strstr(id, other_id));
}

t_visual				get_visual(const char *id)
{
	t_visual	visual;

	if (id == NULL)
		return ((t_visual){ERROR_VISUAL_ID, ERROR_VISUAL_CODE});
	if (!is_same(NONE_VISUAL_ID, (visual = get_text_visual(id)).id))
		return (visual);
	if (!is_same(NONE_VISUAL_ID, (visual = get_foreground_visual(id)).id))
		return (visual);
	if (!is_same(NONE_VISUAL_ID, (visual = get_background_visual(id)).id))
		return (visual);
	if (is_same(id, RESET_VISUALS_ID))
		return (((t_visual){RESET_VISUALS_ID, RESET_VISUALS_CODE}));
	if (is_same(id, DEFAULT_VISUALS_ID))
		return ((t_visual){DEFAULT_VISUALS_ID, DEFAULT_VISUALS_CODE});
	if (is_same(id, END_OF_VISUAL_ID))
		return ((t_visual){END_OF_VISUAL_ID, END_OF_VISUAL_CODE});
	return ((t_visual){NONE_VISUAL_ID, NONE_VISUAL_CODE});
}
