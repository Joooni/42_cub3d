#include "../incl/cub3d.h"

/*
checks if the color-values are between 0-255
*/
static int	check_colors(t_color *F, t_color *C)
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

/*
takes the colors of and insert them into an extra struct for them
*/
int	init_colors(t_window *window)
{
	char	**tmp;

	window->map->f = ft_calloc(1, sizeof(t_color));
	window->map->c = ft_calloc(1, sizeof(t_color));
	tmp = ft_split(window->map->f_tex, ',');
	if (!tmp[2])
		ft_end_process(ERR_INV_COLORS);
	window->map->f->red = ft_atoi(tmp[0]);
	free(tmp[0]);
	window->map->f->green = ft_atoi(tmp[1]);
	free(tmp[1]);
	window->map->f->blue = ft_atoi(tmp[2]);
	free(tmp[2]);
	free(tmp);
	tmp = ft_split(window->map->c_tex, ',');
	window->map->c->red = ft_atoi(tmp[0]);
	free(tmp[0]);
	window->map->c->green = ft_atoi(tmp[1]);
	free(tmp[1]);
	window->map->c->blue = ft_atoi(tmp[2]);
	free(tmp[2]);
	free(tmp);
	if (!check_colors(window->map->f, window->map->c))
		ft_end_process(ERR_INV_COLORS);
	return (1);
}
