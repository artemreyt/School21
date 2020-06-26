/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_visuals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 02:22:45 by artemstarsh       #+#    #+#             */
/*   Updated: 2020/02/15 19:37:36 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "ft_printf.h"
#include "visuals.h"

static void	reset_eov_handler(t_visual visual, t_extra *extra)
{
	t_list	*to_delete_node;

	if (is_same(RESET_VISUALS_ID, visual.id))
	{
		while (extra->visuals_stack->next != NULL)
		{
			to_delete_node = extra->visuals_stack;
			extra->visuals_stack = extra->visuals_stack->next;
			ft_lstdelone(&to_delete_node, lst_content_simple_free);
		}
	}
	else if (is_same(END_OF_VISUAL_ID, visual.id) &&
			extra->visuals_stack->next != NULL)
	{
		to_delete_node = extra->visuals_stack;
		extra->visuals_stack = extra->visuals_stack->next;
		ft_lstdelone(&to_delete_node, lst_content_simple_free);
	}
}

static void	visual_id_handler(char **format, t_extra *extra)
{
	size_t			id_len;
	t_visual		visual;
	t_state_visual	state;
	t_list			*node;

	visual = get_visual(*format);
	if (is_same(NONE_VISUAL_ID, visual.id))
		return ;
	id_len = ft_strlen(visual.id);
	if (is_same(RESET_VISUALS_ID, visual.id)
		|| is_same(END_OF_VISUAL_ID, visual.id))
	{
		reset_eov_handler(visual, extra);
		*format = *format + id_len;
		return ;
	}
	state = create_state_base_of(visual.code, extra);
	if (!(node = ft_lstnew(&state, sizeof(state))))
		return ;
	if (extra->visuals_stack)
		ft_lstadd(&(extra->visuals_stack), node);
	else
		extra->visuals_stack = node;
	*format = *format + id_len;
}

int			visuals_handler(char **format, va_list args_list,
							t_buffer *buffer, t_extra *extra)
{
	char			*visuals;
	char			*st_str;

	visuals = *format + 1;
	if (*visuals == '*')
	{
		st_str = (char *)va_arg(args_list, void *);
		visual_id_handler(&st_str, extra);
		visuals++;
	}
	else
		visual_id_handler(&visuals, extra);
	if (*visuals != VISUAL_SPEC_CLOSE ||
		!(st_str = create_state_string(extra->visuals_stack)))
	{
		return (0);
	}
	buf_putstr(buffer, VISUAL_START);
	buf_putstr(buffer, st_str);
	buf_putstr(buffer, VISUAL_END);
	ft_memdel((void**)&st_str);
	*format = visuals + 1;
	return (1);
}
