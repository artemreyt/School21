/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_visual.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 16:49:36 by creicher          #+#    #+#             */
/*   Updated: 2020/02/15 16:51:25 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visuals.h"

static int		set_code(int new_code, t_state_visual *state)
{
	if (is_text_type_visual(new_code))
		state->text_type = new_code;
	else if (is_fgnd_visual(new_code))
		state->fgnd = new_code;
	else if (is_bgnd_visual(new_code))
		state->bgnd = new_code;
	else
		return (0);
	return (1);
}

static int		add_code(int code, char **str)
{
	char	*buf_str;
	char	*num_str;

	if (code != 0)
	{
		num_str = ft_itoa(code);
		if (!num_str)
			return (0);
		buf_str = ft_strjoin(*str, num_str);
		ft_memdel((void**)&num_str);
		if (!buf_str)
			return (0);
		ft_memdel((void**)str);
		*str = buf_str;
		buf_str = ft_strjoin(*str, VISUAL_SEPARATOR);
		if (!buf_str)
			return (0);
		ft_memdel((void**)str);
		*str = buf_str;
	}
	return (1);
}

t_state_visual	create_state_base_of(int new_code, t_extra *base)
{
	t_state_visual	new;

	new.text_type = 0;
	new.fgnd = 0;
	new.bgnd = 0;
	if (base)
	{
		if (!base->visuals_stack)
			set_code(new_code, &new);
		else if (base->visuals_stack->content)
		{
			ft_memcpy(&new, base->visuals_stack->content,
						sizeof(t_state_visual));
			if (!set_code(new_code, &new))
			{
				new.text_type = 0;
				new.fgnd = 0;
				new.bgnd = 0;
			}
		}
	}
	return (new);
}

char			*create_state_string(t_list *lst_state_node)
{
	t_state_visual	*state;
	char			*str;

	if (lst_state_node == NULL)
		return (NULL);
	state = lst_state_node->content;
	str = ft_strdup("0;");
	if (!str)
		return (NULL);
	if (state &&
		(state->text_type != 0 || state->bgnd != 0 || state->fgnd != 0))
	{
		if (!add_code(state->text_type, &str) ||
			!add_code(state->fgnd, &str) ||
			!add_code(state->bgnd, &str))
		{
			ft_memdel((void**)&str);
			return (NULL);
		}
	}
	str[ft_strlen(str) - 1] = '\0';
	return (str);
}
