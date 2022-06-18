#include "../incl/cub3d.h"

/*
checks if the color-values are between 0-255
*/
static int	check_colors(t_texture *F, t_texture *C)
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
	char	**tmp_f;
	char	**tmp_c;

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
