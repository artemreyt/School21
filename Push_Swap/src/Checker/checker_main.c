#include "checker.h"
#include "libft.h"

int main(int argc, char **argv)
{
    int ret_code;

    if (argc == 1)
        return (0);
    if (!check_valid_arguments(argc, argv))
    {
        ft_putendl(ERROR_MSG);
        return (ERROR_CODE);
    }
    ret_code = launch_checker(argc, argv);
    if (ret_code == OK_CODE)
        ft_putendl(OK_MSG);
    else if (ret_code == KO_CODE)
        ft_putendl(KO_MSG);
    else if (ret_code == ERROR_CODE)
        ft_putendl(ERROR_MSG);
    else
        ft_putendl("INKNOWN RETURN CODE");
    return (ret_code);
}