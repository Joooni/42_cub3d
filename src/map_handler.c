#include "../incl/cub3d.h"

/*
gets triggert when the first character of the line is a alph
safes all the paths of the directions and the colors of the
ciling and the floor
*/
int	safe_preoptions(t_map *map, char *line, int counter)
{
	if (line[counter] == 'N' && line[counter + 1] == 'O' && !map->no_path)
		map->no_path = ft_substr(line, counter + 3, ft_strlen(line) \
			- counter - 4);
	else if (line[counter] == 'S' && line[counter + 1] == 'O' && !map->so_path)
		map->so_path = ft_substr(line, counter + 3, ft_strlen(line) \
			- counter - 4);
	else if (line[counter] == 'W' && line[counter + 1] == 'E' && !map->we_path)
		map->we_path = ft_substr(line, counter + 3, ft_strlen(line) \
			- counter - 4);
	else if (line[counter] == 'E' && line[counter + 1] == 'A' && !map->ea_path)
		map->ea_path = ft_substr(line, counter + 3, ft_strlen(line) \
			- counter - 4);
	else if (line[counter] == 'F' && !map->f_tex)
		map->f_tex = ft_substr(line, counter + 2, ft_strlen(line) \
			- counter - 2);
	else if (line[counter] == 'C' && !map->c_tex)
		map->c_tex = ft_substr(line, counter + 2, ft_strlen(line) \
			- counter - 2);
	else
		ft_end_process(ERR_INV_IDEN);
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
			window->player->pos->x = i * 32;
			window->player->pos->y = window->map->rows * 32;
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

	window->map->map = (char **)ft_calloc(rows, sizeof(char *));
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
			&& i < rows)
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
	player_flag = 0;
	if (fd <= 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		counter = 0;
		while (line[counter] == ' ')
			counter++;
		if (ft_isalpha(line[counter]))
			safe_preoptions(window->map, line, counter);
		else if (ft_isdigit(line[counter]))
			player_flag += count_map(window, line);
		free(line);
		line = get_next_line(fd);
	}
	safe_map(window, window->map->rows);
	if (player_flag == 0 || player_flag > 1 || !check_map(window))
		ft_end_process(ERR_INV_MAP);
	return (0);
}
