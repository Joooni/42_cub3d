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
int	count_map(t_window *window, char *line)
{
	int	i;
	int	flag;
	int	columns;

	i = 0;
	flag = 0;
	columns = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			columns++;
		if (line[i] == 'N' || line[i] == 'E' || line[i] == 'S'
			|| line[i] == 'W')
		{
			window->map->direction = line[i];
			window->player->x = i * 32;
			window->player->y = window->map->rows * 32;
			flag++;
		}
		i++;
	}
	window->map->rows++;
	if (window->map->columns < columns)
		window->map->columns = columns;
	return (flag);
}

/*
safes the map
*/
int	safe_map(t_window *window, int rows)
{
	int		i;
	int		fd;
	int		counter;
	char	*line;

	window->map->map = ft_calloc(rows, sizeof(char **));
	i = 0;
	fd = open(window->map->path, O_RDONLY);
	counter = 0;
	if (fd <= 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		while (line[counter] == ' ')
			counter++;
		if (ft_isdigit(line[counter]) && line[0] != 'F' && line[0] != 'C' \
			&& i <= rows)
			window->map->map[i++] = ft_substr(line, 0, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

/*
reads in the map that got passed and calls different functions to 
handle the input
*/
int	map_handler(t_window *window)
{
	int		fd;
	int		counter;
	int		player_flag;
	char	*line;

	fd = open(window->map->path, O_RDONLY);
	counter = 0;
	player_flag = 0;
	if (fd <= 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		while (line[counter] == ' ')
			counter++;
		if (ft_isalpha(line[0]))
			safe_preoptions(window, line);
		else if (ft_isdigit(line[counter]))
			player_flag += count_map(window, line);
		free(line);
		line = get_next_line(fd);
	}
	safe_map(window, window->map->rows);
	if (player_flag == 0 || player_flag > 1 || !check_map(window))
		ft_end_process("Invalid map\n");
	return (0);
}
