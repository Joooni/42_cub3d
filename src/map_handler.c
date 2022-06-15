#include "../incl/cub3d.h"

int map_handler(t_window *window)
{
	int fd;
	int counter;
	char *line;
	printf("%p\n", window);

	fd = open("maps/map1.cub", O_RDONLY);
	counter = 0;
	if (fd <= 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		printf("\033[33mline:\033[0m %s", line);
		if (ft_isalpha(line[0]))
		{
			//function that saves the paths and the values for F C
			printf("\033[90mFound an alph character\033[0m\n");
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}