#include "../incl/cub3d.h"

/*
checks the top and the bottom of the map if there is a 1 or whitespace
*/
static int	check_top_n_bot(t_window *window, int line)
{
	int	i;

	i = 0;
	while (window->map->map[line][i] && window->map->map[line][i] != '\n')
	{
		if (window->map->map[line][i] != '1' && window->map->map[line][i]
			!= ' ')
			return (0);
		i++;
	}
	return (1);
}

/*
belongs to the line check and is just looking for the player, so that the check
isn't throwing an error
*/
int static	player_flag(char **map, int line, int i)
{
	if (map[line - 1][i] != 'N' && map[line + 1][i] != 'N' \
		&& map[line - 1][i] != 'E' && map[line + 1][i] != 'E' \
		&& map[line - 1][i] != 'S' && map[line + 1][i] != 'S' \
		&& map[line - 1][i] != 'W' && map[line + 1][i] != 'W')
		return (0);
	return (1);
}

/*
checks each line - exept top and bottom - if there is an 1 or the player
*/
static int	line_check(t_window *window, int line)
{
	int		i;
	char	**map;

	i = 0;
	map = window->map->map;
	if (map[line][i] != ' ' && map[line][i] != '1')
		return (0);
	i = 1;
	while (map[line][i] && map[line][i] != '\n')
	{
		if (map[line][i] == ' ' && map[line][i] != ' ' && map[line][i] != '1')
			return (0);
		while (map[line][i] == ' ')
			i++;
		if (map[line][i - 1] == ' ' && map[line][i] != '1')
			return (0);
		if (map[line][i] == '0' && ((map[line - 1][i] != '1' && map[line -1][i]
		!= '0') || (map[line + 1][i] != '1' && map[line + 1][i] != '0'))
		&& player_flag(map, line, i))
			return (1);
		i++;
	}
	if (map[line][i - 1] != ' ' && map[line][i - 1] != '1')
		return (0);
	return (1);
}

/*
handler function which checks if the map fits to the requirements
*/
int	check_map(t_window *window)
{
	int	i;

	i = 0;
	if (!check_top_n_bot(window, i))
		return (0);
	i = 1;
	while (i < window->map->rows)
	{
		if (!line_check(window, i))
			return (0);
		i++;
	}
	if (!init_colors(window))
		return (0);
	return (1);
}
