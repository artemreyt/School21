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

enum    e_StackSide
{
    A_STACK,
    B_STACK
};
typedef enum e_StackSide    e_StackSide;

/*
 *
 * if log_fd < 0, then logging not triggered
 *
 */
StackPair   *stackPairCreate(int *arr, size_t n, int log_fd);
void        stackPairFree(StackPair **sp);
void        stackPairInit(StackPair *sp, int log_fd);
void        stackPairLog(StackPair *sp, const char *msg);

int         stackPairPeek(StackPair *sp, e_StackSide side, int *res);
int         stackPairPeekFew(StackPair *sp, e_StackSide side, int *buffer, int n);
int         stackPairSwap(StackPair *sp, e_StackSide side);
int         stackPairCheckOrder(StackPair *sp, e_StackSide side, int n);

int     sa_cmd(StackPair *sp);
int     sb_cmd(StackPair *sp);
int     ss_cmd(StackPair *sp);
void    pa_cmd(StackPair *sp);
void    pb_cmd(StackPair *sp);
void    ra_cmd(StackPair *sp);
void    rb_cmd(StackPair *sp);
void    rr_cmd(StackPair *sp);
void    rra_cmd(StackPair *sp);
void    rrb_cmd(StackPair *sp);
void    rrr_cmd(StackPair *sp);

#define SA_MSG "sa"
#define SB_MSG "sb"
#define SS_MSG "ss"
#define PA_MSG "pa"
#define PB_MSG "pb"
#define RA_MSG "ra"
#define RB_MSG "rb"
#define RR_MSG "rr"
#define RRA_MSG "rra"
#define RRB_MSG "rrb"
#define RRR_MSG "rrr"

#endif
