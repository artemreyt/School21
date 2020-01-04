#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

# define BUF_SIZE 5

int main()
{
	ssize_t	read_res;
	int		fd;
	char	buffer[BUF_SIZE + 1];

	fd = open("input.txt", O_RDONLY);
	while ((read_res = read(fd, buffer, BUF_SIZE)) > 0)
	{
		buffer[read_res] = '\0';
		printf("%zd:%s\n", read_res, buffer);
	}

	printf("%zd\n", read(fd, buffer, BUF_SIZE));
	printf("%zd\n", read(fd, buffer, BUF_SIZE));

}