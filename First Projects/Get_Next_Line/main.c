#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int i;

	i = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		printf("%d\n", fd);
		while (get_next_line(fd, &line) > 0)
		{
			printf("line (%d) : %s\n", i + 1,line);
			i++;
			ft_strdel(&line);
		}
	}
	if (argc == 2)
		close(fd);
	return (0);
}
