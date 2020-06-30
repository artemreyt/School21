#include "checker.h"
#include "libft.h"
#include "StackPair.h"
#include "get_next_line.h"

static int  execute_command(StackPair *sp, char *cmd)
{
    if (!ft_strcmp(cmd, SA_MSG))
        sa_cmd(sp);
    else if (!ft_strcmp(cmd, SB_MSG))
        sb_cmd(sp);
    else if (!ft_strcmp(cmd, SS_MSG))
        ss_cmd(sp);
    else if (!ft_strcmp(cmd, PA_MSG))
        pa_cmd(sp);
    else if (!ft_strcmp(cmd, PB_MSG))
        pb_cmd(sp);
    else if (!ft_strcmp(cmd, RA_MSG))
        ra_cmd(sp);
    else if (!ft_strcmp(cmd, RB_MSG))
        rb_cmd(sp);
    else if (!ft_strcmp(cmd, RR_MSG))
        rr_cmd(sp);
    else if (!ft_strcmp(cmd, RRA_MSG))
        rra_cmd(sp);
    else if (!ft_strcmp(cmd, RRB_MSG))
        rrb_cmd(sp);
    else if (!ft_strcmp(cmd, RRR_MSG))
        rrr_cmd(sp);
    else
        return (0);
    return (1);
}


static int  checker(StackPair *sp, int size, int fd)
{
    char *cmd;

    while (get_next_line(STDIN_FILENO, &cmd) > 0)
    {
        if (!execute_command(sp, cmd))
        {
            free(cmd);
            return (ERROR_CODE);
        }
        free(cmd);
    }
    if (!stackPairCheckOrder(sp, A_STACK, size) || sp->stack_b->size)
        return (KO_CODE);
    return (OK_CODE);
}


int         launch_checker(int argc, char **argv)
{
    int         i;
    int         *arr;
    int         retv;
    StackPair   *sp;

    arr = (int *)malloc((argc - 1) * sizeof(int));
    i = 1;
    while (i < argc)
    {
        arr[i - 1] = ft_atoi(argv[i]);
        ++i;
    }
    sp = stackPairCreate(arr, argc - 1, -1);
    retv = checker(sp, argc - 1, STDIN_FILENO);
    stackPairFree(sp);
    free(arr);
    return retv;
}
