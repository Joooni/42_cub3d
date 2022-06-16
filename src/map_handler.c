#include "../incl/cub3d.h"

/*
gets triggert when the first character of the line is a alph
safes all the paths of the directions and the colors of the 
ciling and the floor
*/
int	safe_preoptions(t_window *window, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'N' && line[i + 1] == 'O')
			window->map->NO_path = ft_substr(line, 3, ft_strlen(line) - 3);
		else if (line[i] == 'S' && line[i + 1] == 'O')
			window->map->SO_path = ft_substr(line, 3, ft_strlen(line) - 3);
		else if (line[i] == 'W' && line[i + 1] == 'E')
			window->map->WE_path = ft_substr(line, 3, ft_strlen(line) - 3);
		else if (line[i] == 'E' && line[i + 1] == 'A')
			window->map->EA_path = ft_substr(line, 3, ft_strlen(line) - 3);
		else if (line[i] == 'F')
			window->map->F_tex = ft_substr(line, i + 2, ft_strlen(line) - 2);
		else if (line[i] == 'C')
			window->map->C_tex = ft_substr(line, i + 2, ft_strlen(line) - 2);
		i++;
	}
	return (0);
}

/*
gets triggert when the first character of the line is a number
safes every row of the map in the char** map and counts the size
*/
int count_map(t_window *window, char *line)
{
	int i;
	int columns;

	i = 0;
	columns = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			columns++;
		i++;
	}
	if (window->map->columns < columns)
		window->map->columns = columns;
	return (0);
}

/*
safes the map
*/
// int safe_map(t_window *window, line)
// {
// 	window->map->map = ft_calloc()
// }

/*
reads in the map that got passed and calls different functions to 
handle the input
*/
int	map_handler(t_window *window)
{
	int	fd;
	int	counter;
	char	*line;

	fd = open("maps/map1.cub", O_RDONLY);
	counter = 0;
	if (fd <= 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		while (line[counter] == ' ')
			counter++;
		//printf("\033[33mline:\033[0m %s", line);
		if (ft_isalpha(line[0]))
			safe_preoptions(window, line);
		else if (ft_isdigit(line[counter]))
		{
			count_map(window, line); //umbenennen in count_map
			window->map->rows++;
		}
		free(line);
		line = get_next_line(fd);
	}
	//call save map here because you have to know the amount of rows
	printf("rows: %d\ncolumns: %d\n", window->map->rows, window->map->columns);
	return (0);
}


/*

**map = ft_calloc(row, sizeof(char *))

*/