#include "../incl/cub3d.h"

/** @brief check if image and window are there and if, destroy
 * and then exit the program */
int	ft_close(t_window *window)
{
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