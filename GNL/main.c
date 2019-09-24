#include "get_next_line.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	int		fd_list[argc - 1];
	int		i;
	int		stop;

	i = 1;
	while (i < argc)
	{
		fd_list[i - 1] = open(argv[i], O_RDONLY);
		ft_putendl(argv[i++]);
	}
	stop = 0;
	while (!stop)
	{
		char	*str;
		int		result;

		stop = 1;
		i = 0;
		while (i < argc - 1)
		{
			ft_putendl(argv[i + 1]);
			if ((result = get_next_line(fd_list[i], &str)) == 1)
			{
				stop = 0;
				ft_putendl(str);
				free(str);
			}
			else if (result == 0)
				ft_putendl("COMLETED");
			else
				ft_putendl("ERROR");
			i++;
		}	
	}
	sleep(30);
	return (0);
}
