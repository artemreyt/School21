/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pair.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creicher <creicher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 01:18:21 by creicher          #+#    #+#             */
/*   Updated: 2020/07/23 01:25:41 by creicher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_PAIR_H
# define STACK_PAIR_H

# include "int_stack.h"

struct			s_stack_pair
{
	t_int_stack	*stack_a;
	t_int_stack	*stack_b;
	int			log_fd;
};
typedef struct	s_stack_pair	t_stack_pair;

enum			e_stack_side
{
	A_STACK,
	B_STACK
};
typedef enum e_stack_side	t_stack_side;

/*
	*
	* if log_fd < 0, then logging not triggered
	*
*/

t_stack_pair	*stack_pair_сreate(int *arr, size_t n, int log_fd);
void			stack_pair_free(t_stack_pair **sp);
void			stack_pair_init(t_stack_pair *sp, int log_fd);
void			stack_pair_log(t_stack_pair *sp, const char *msg);

int				stack_pair_peek(t_stack_pair *sp, t_stack_side side, int *res);
int				stack_pair_peek_few(t_stack_pair *sp, t_stack_side side,
					int *buffer, int n);
int				stack_pair_swap(t_stack_pair *sp, t_stack_side side);
int				stack_pair_check_order(t_stack_pair *sp,
					t_stack_side side, int n);

int				sa_cmd(t_stack_pair *sp);
int				sb_cmd(t_stack_pair *sp);
int				ss_cmd(t_stack_pair *sp);
void			pa_cmd(t_stack_pair *sp);
void			pb_cmd(t_stack_pair *sp);
void			ra_cmd(t_stack_pair *sp);
void			rb_cmd(t_stack_pair *sp);
void			rr_cmd(t_stack_pair *sp);
void			rra_cmd(t_stack_pair *sp);
void			rrb_cmd(t_stack_pair *sp);
void			rrr_cmd(t_stack_pair *sp);

# define SA_MSG "sa"
# define SB_MSG "sb"
# define SS_MSG "ss"
# define PA_MSG "pa"
# define PB_MSG "pb"
# define RA_MSG "ra"
# define RB_MSG "rb"
# define RR_MSG "rr"
# define RRA_MSG "rra"
# define RRB_MSG "rrb"
# define RRR_MSG "rrr"

#endif
