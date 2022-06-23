#include "../incl/cub3d.h"

void drawing_handler(t_window *window)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = WINDOW_WIDTH / 2;
		while (x < WINDOW_WIDTH)
		{
			ft_pixel_put_img(window->img, x, y, 0x00ba03fc);
			x++;
		}
		y++;
	}
}