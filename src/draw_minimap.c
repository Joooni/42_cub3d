#include "../incl/cub3d.h"

void	ft_draw_player(t_window *window)
{
	int	counter_x;
	int	counter_y;

	counter_y = 0;
	while (counter_y < window->player->size)
	{
		counter_x = 0;
		while (counter_x < window->player->size)
		{
			ft_pixel_put_img(window->img,
				window->player->x + counter_x,
				window->player->y + counter_y, 0x00FF0000);
			counter_x++;
		}
		counter_y++;
	}
}