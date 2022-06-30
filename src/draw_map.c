#include "../incl/cub3d.h"

static void	ft_scale_factor(t_window *window)
{
	window->scale_factor = WINDOW_WIDTH * 0.7 / window->map->columns;
	if (WINDOW_HEIGHT * 0.7 / window->map->rows < window->scale_factor)
		window->scale_factor = WINDOW_HEIGHT * 0.7 / window->map->rows;
}
static void	draw_something(t_window *window, int x, int y, int color)
{
	t_rect	rect;

	rect.x = x * window->scale_factor;
	rect.y = y * window->scale_factor;
	rect.size_x = window->scale_factor;
	rect.size_y = window->scale_factor;
	rect.color = color;
	ft_draw_rect(window, rect);
}

int static	player_flag(char **map, int y, int x)
{
	if (map[y][x] != 'N' && map[y][x] != 'N' \
		&& map[y][x] != 'E' && map[y][x] != 'E' \
		&& map[y][x] != 'S' && map[y][x] != 'S' \
		&& map[y][x] != 'W' && map[y][x] != 'W')
		return (0);
	return (1);
}

void	draw_map(t_window *window)
{
	int	x;
	int	y;

	y = 0;
	ft_scale_factor(window);
	while (y < window->map->rows)
	{
		x = 0;
		while (x < window->map->columns)
		{
			if (window->map->map[y][x] == '1')
				draw_something(window, x, y, 0x00303096);
			else if (window->map->map[y][x] == '0')
				draw_something(window, x, y, 0x00353542);
			else if (player_flag(window->map->map, y, x))
				draw_something(window, x, y, 0x005858ad);
			else if (window->map->map[y][x] == '\n')
				break ;
			x++;
		}
		y++;
	}
}
