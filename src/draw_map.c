#include "../incl/cub3d.h"

static void	ft_scale_factor(t_window *window, int map_flag)
{
	int multiplier;

	multiplier = 1;
	if (map_flag == 1)
		multiplier = 3;
	window->scale_factor = (double)
		(WINDOW_WIDTH
			* M_MINIMAP_FACTOR
			/ window->map->columns) * multiplier;
	if (WINDOW_HEIGHT * M_MINIMAP_FACTOR / window->map->rows
		< window->scale_factor)
		window->scale_factor = (double)
			(WINDOW_HEIGHT
				* M_MINIMAP_FACTOR
				/ window->map->rows);
}

static void	draw_something(t_window *window, int x, int y, int color)
{
	t_rect	rect;

	rect.x = x * (int)window->scale_factor;
	rect.y = y * (int)window->scale_factor;
	rect.size_x = (int)window->scale_factor;
	rect.size_y = (int)window->scale_factor;
	rect.color = color;
	ft_draw_rect(window, rect);
}

int static	player_flag(t_window *window, int y, int x)
{
	char	**map;

	map = window->map->map;
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
	ft_scale_factor(window, window->player->key->m);
	while (y < window->map->rows)
	{
		x = 0;
		while (x < window->map->columns)
		{
			if (window->map->map[y][x] == '1')
				draw_something(window, x, y, 0x00303096);
			else if ((y == (int)window->player->pos->y / 32 && x == (int) \
				window->player->pos->x / 32))
				draw_something(window, x, y, 0x0017FC03);
			else if (window->map->map[y][x] == '0' || 
				window->map->map[y][x] == '3' || player_flag(window, y, x))
				draw_something(window, x, y, 0x00353542);
			else if (window->map->map[y][x] == '2')
				draw_something(window, x, y, 0x00686a6e);
			else if (window->map->map[y][x] == '\n')
				break ;
			x++;
		}
		y++;
	}
}
