#include "../incl/cub3d.h"

/*
checks if the color-values are between 0-255
*/
static int	check_colors(char **tmp)
{
	if (ft_atoi(tmp[0]) < 0 || ft_atoi(tmp[0]) > 255)
		return (0);
	if (ft_atoi(tmp[1]) < 0 || ft_atoi(tmp[1]) > 255)
		return (0);
	if (ft_atoi(tmp[2]) < 0 || ft_atoi(tmp[2]) > 255)
		return (0);

	return (1);
}

/*
takes the colors of and insert them into an extra struct for them
*/
int	init_colors(t_window *window)
{
	char	**tmp;

	window->map->f = ft_calloc(1, sizeof(t_color));
	window->map->c = ft_calloc(1, sizeof(t_color));
	tmp = ft_split_cub3d(window->map->f_tex, ',');
	if (!check_colors(tmp) || !tmp[2] || tmp[3])
		ft_end_process(ERR_INV_COLORS);
	window->map->f->red = ft_atoi(tmp[0]);
	free(tmp[0]);
	window->map->f->green = ft_atoi(tmp[1]);
	free(tmp[1]);
	window->map->f->blue = ft_atoi(tmp[2]);
	free(tmp[2]);
	free(tmp);
	tmp = ft_split_cub3d(window->map->c_tex, ',');
	if (!check_colors(tmp) || !tmp[2] || tmp[3])
		ft_end_process(ERR_INV_COLORS);
	window->map->c->red = ft_atoi(tmp[0]);
	free(tmp[0]);
	window->map->c->green = ft_atoi(tmp[1]);
	free(tmp[1]);
	window->map->c->blue = ft_atoi(tmp[2]);
	free(tmp[2]);
	free(tmp);
	return (1);
}
