#include "../incl/cub3d.h"

// static void  calc_linehight(t_window *window)
// {
// 	//calc_linehight
// 	int line_height = (int) WINDOW_HEIGHT / window->player->ray->wall_dist_perp;
// 	printf("1\n");
// 	//calc lowest and highest
// 	int draw_start = -line_height / 2 + WINDOW_HEIGHT / 2;
// 	printf("2\n");
// 	if (draw_start < 0)
// 		draw_start = 0;
// 	printf("3\n");
// 	int draw_end = line_height / 2 + WINDOW_HEIGHT / 2;
// 	if (draw_end >= WINDOW_HEIGHT)
// 		draw_end = WINDOW_HEIGHT - 1;
// 	printf("start: %d\nend: %d\n", draw_start, draw_end);
// }

// void ft_paint_black(t_window *window)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < WINDOW_HEIGHT)
// 	{
// 		x = WINDOW_WIDTH / 2;
// 		while (x < WINDOW_WIDTH)
// 		{
// 			ft_pixel_put_img(window->img, x, y, 0x00000000);
// 			x++;
// 		}
// 		y++;
// 	}
// }

void drawing_handler(t_window *window, t_rc *ray, int x)
{
	double line_height;
	double draw_start;
	double draw_end;
	int color;

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
	if (ray->side == 1)
		color = 0xd19041;
	else
		color = 0xeb9834;
	while (draw_start <= draw_end)
	{
		ft_pixel_put_img(window->img, x, draw_start, color);
		draw_start++;
	}
}

