#ifndef STACKPAIR_H
# define STACKPAIR_H

#include "IntStack.h"

struct  s_StackPair
{
   IntStack     *stack_a;
   IntStack     *stack_b;
   int          log_fd;
};

typedef struct s_StackPair  StackPair;


/*
 *
 * if log_fd < 0, then logging not triggered
 *
 */
void        stackPairInit(StackPair *sp, int log_fd);
StackPair   *stackPairCreate(int *arr, size_t n, int log_fd);
void        stackPairLog(StackPair *sp, const char *msg);

int         stackPairPeek_a(StackPair *sp, int *res);
int         stackPairPeek_b(StackPair *sp, int *res);

void    sa_cmd(StackPair *sp);
void    sb_cmd(StackPair *sp);
void    ss_cmd(StackPair *sp);
void    pa_cmd(StackPair *sp);
void    pb_cmd(StackPair *sp);
void    ra_cmd(StackPair *sp);
void    rb_cmd(StackPair *sp);
void    rr_cmd(StackPair *sp);
void    rra_cmd(StackPair *sp);
void    rrb_cmd(StackPair *sp);
void    rrr_cmd(StackPair *sp);

const char *SA_MSG = "sa";
const char *SB_MSG = "sb";
const char *SS_MSG = "ss";
const char *PA_MSG = "pa";
const char *PB_MSG = "pb";
const char *RA_MSG = "ra";
const char *RB_MSG = "rb";
const char *RR_MSG = "rr";
const char *RRA_MSG = "rra";
const char *RRB_MSG = "rrb";
const char *RRR_MSG = "rrr";

#endif
