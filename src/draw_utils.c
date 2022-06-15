#include "../incl/cub3d.h"

void	ft_pixel_put_img(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

int	ft_render_next_frame(t_window *window)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			ft_pixel_put_img(window->img, x, y, 0x00000000);
			x++;
		}
		y++;
	}
	ft_draw_grid(window);
	ft_grid_highlight(window);
	ft_draw_player(window);
	mlx_put_image_to_window(window->mlx, window->win, window->img->img, 0, 0);
	return (0);
}

void	ft_draw_rect(t_window *window, t_rect rect)
{
	int	counter_x;
	int	counter_y;

	counter_y = 0;
	while (counter_y < rect.size_y)
	{
		counter_x = 0;
		while (counter_x < rect.size_x)
		{
			ft_pixel_put_img(window->img,
				rect.x + counter_x,
				rect.y + counter_y, rect.color);
			counter_x++;
		}
		counter_y++;
	}
}
