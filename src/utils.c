#include "../incl/cub3d.h"

/** @brief check if image and window are there and if, destroy
 * and then exit the program */
int	ft_close(t_window *window)
{
	ft_free_tex(window);
	ft_free_player(window);
	if (window->img->img != NULL)
	{
		mlx_destroy_image(window->mlx, window->img->img);
	}
	if (window->win != NULL)
	{
		mlx_destroy_window(window->mlx, window->win);
	}
	exit(0);
}

int	ft_tcolor_to_int(t_color color)
{
	return (color.t << 24 | color.red << 16
		| color.green << 8 | color.blue);
}
