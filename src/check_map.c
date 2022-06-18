#include "../incl/cub3d.h"

static int	check_top_n_bot(t_window *window, int line)
{
	int	i;

	i = 0;
	while (window->map->map[line][i] && window->map->map[line][i] != '\n')
	{
		if (window->map->map[line][i] != '1' && window->map->map[line][i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	line_check(t_window *window, int line)
{
	int	i;

	i = 0;
	if (window->map->map[line][i] != ' ' && window->map->map[line][i] != '1')
		return (0);
	i = 1;
	while (window->map->map[line][i] && window->map->map[line][i] != '\n')
	{
		if (window->map->map[line][i] == ' ' && window->map->map[line][i] != ' ' \
			&& window->map->map[line][i] != '1')
			return (0);
		while (window->map->map[line][i] == ' ')
			i++;
		if (window->map->map[line][i - 1] == ' ' && window->map->map[line][i] != '1')
			return (0);
		if (window->map->map[line][i] == '0' && \
			((window->map->map[line - 1][i] != '1' && window->map->map[line - 1][i] != '0') \
			|| (window->map->map[line + 1][i] != '1' && window->map->map[line + 1][i] != '0')) \
			&& window->map->map[line-1][i] != 'N' && window->map->map[line+1][i] != 'N' \
			&& window->map->map[line-1][i] != 'E' && window->map->map[line+1][i] != 'E' \
			&& window->map->map[line-1][i] != 'S' && window->map->map[line+1][i] != 'S' \
			&& window->map->map[line-1][i] != 'W' && window->map->map[line+1][i] != 'W')
			return (1);
		i++;
	}
	if (window->map->map[line][i - 1] != ' ' && window->map->map[line][i - 1] != '1')
		return (0);
	return (1);
}

static int check_colors(t_texture *F, t_texture *C)
{
	if (F->red < 0 || F->red > 255)
		return (0);
	if (F->green < 0 || F->green > 255)
		return (0);
	if (F->blue < 0 || F->blue > 255)
		return (0);
	if (C->red < 0 || C->red > 255)
		return (0);
	if (C->green < 0 || C->green > 255)
		return (0);
	if (C->blue < 0 || C->blue > 255)
		return (0);
	return (1);
}


static int init_colors(t_window *window)
{
	char **tmp_f;
	char **tmp_c;

	window->map->F = ft_calloc(1, sizeof(t_color));
	window->map->C = ft_calloc(1, sizeof(t_color));
	tmp_f = ft_split(window->map->F_tex, ',');
	window->map->F->red = ft_atoi(tmp_f[0]);
	free(tmp_f[0]);
	window->map->F->green = ft_atoi(tmp_f[1]);
	free(tmp_f[1]);
	window->map->F->blue = ft_atoi(tmp_f[2]);
	free(tmp_f[2]);
	free(tmp_f);
	tmp_c = ft_split(window->map->C_tex, ',');
	window->map->C->red = ft_atoi(tmp_c[0]);
	free(tmp_c[0]);
	window->map->C->green = ft_atoi(tmp_c[1]);
	free(tmp_c[1]);
	window->map->C->blue = ft_atoi(tmp_c[2]);
	free(tmp_c[2]);
	free(tmp_c);
	if (!check_colors(window->map->F, window->map->C))
		ft_end_process("Invalid colors");
	return (1);
}


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
	//window->map->map[(int)window->player->y][(int)window->player->x] = window->map->pdir;
	return (1);
}
