#include "../incl/cub3d.h"

void	drawing_handler(t_window *window, t_rc *ray, int x)
{
	double	line_height;
	double	draw_start;
	double	draw_end;
	int		color;

	line_height = (WINDOW_HEIGHT / ray->wall_dist_perp) * 32;
	draw_start = -line_height / 2 + WINDOW_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + WINDOW_HEIGHT / 2;
	if (draw_end >= WINDOW_HEIGHT)
		draw_end = WINDOW_HEIGHT - 1;
	//printf("line_height: %d\n", line_height);
	//printf("start: %d\nend: %d\n", draw_start, draw_end);
	//printf("side: %d\n", ray->side);
	//north and south
	if (ray->side == 1)
	{
		color = 0xd19041;
		if (ray->dir->y < 0)
			color = 0xa85032;
	}
	else
	{
		color = 0xeb9834;
		if (ray->dir->x < 0)
			color = 0xd94d1e;
	}
	double tex_x = x;
	if (tex_x > window->map->no_tex->line_len - 1)
		tex_x = window->map->no_tex->line_len - 1;
	while (draw_start <= draw_end)
	{
		if (ray->side == 1 && ray->dir->y < 0)
		{
			//I need to know which part of the north tex got hit
			double tex_y = window->map->no_tex->line_len * (window->map->no_tex->line_len / line_height);
			if (tex_y > window->map->no_tex->line_len - 1)
				tex_y = window->map->no_tex->line_len - 1;
			ft_pixel_put_img(window->img, x, draw_start, (int)window->map->no_tex->matrix[(int)tex_y][(int)(tex_x)]);
		}
		else
			ft_pixel_put_img(window->img, x, draw_start, color);
		draw_start++;
	}
}
