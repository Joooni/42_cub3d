#include "../incl/cub3d.h"

void	ft_draw_player(t_window *window)
{
	t_rect player;

	player.x = window->player->pos->x / 32;
//	player.y = (window->player->pos->y * window->map->rows / 100) - window->player->size / 2;
	player.y = window->player->pos->y / 32;
	player.size_x = window->player->size;
	player.size_y = player.size_x;
	player.color = window->player->color;
	ft_draw_rect(window, player);
}

void	ft_draw_grid(t_window *window)
{
	int	counter_x;
	int	counter_y;
	int	color;

	color = 0x008C8C8C;
	counter_y = 0;
	while (counter_y < (int)window->scale_factor * window->map->rows)
	{
		counter_x = 0;
		while (counter_x < (int)window->scale_factor * window->map->columns)
		{
			if (counter_x % (int)(window->scale_factor) == 0 || counter_y % (int)(window->scale_factor) == 0)
				ft_pixel_put_img(window->img, counter_x, counter_y, color);
			counter_x++;
		}
		counter_y++;
	}
}

void	ft_grid_highlight(t_window *window)
{
	t_rect	square;
	int		square_x;
	int		square_y;

	square_x = window->player->pos->x / 32;
	square_y = window->player->pos->y / 32;
	square.x = square_x * 32;
	square.y = square_y * 32;
	square.size_x = 32;
	square.size_y = 32;
	square.color = 0x006C6C6C;
	ft_draw_rect(window, square);
}