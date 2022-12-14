/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:07:30 by jtomala           #+#    #+#             */
/*   Updated: 2022/12/14 16:57:09 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

static void	ft_scale_factor(t_window *window, int map_flag)
{
	int	multiplier;

	multiplier = 1;
	if (map_flag == 1)
		multiplier = 3;
	if (
		(WINDOW_WIDTH * MINIMAP_FACTOR / window->map->columns)
		> (WINDOW_HEIGHT * MINIMAP_FACTOR / window->map->rows))
		window->scale_factor = (double)
			(WINDOW_HEIGHT * MINIMAP_FACTOR / window->map->rows) * multiplier;
	else
		window->scale_factor = (double)
			(WINDOW_WIDTH * MINIMAP_FACTOR / window->map->columns) * multiplier;
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

static int	ft_draw_map_helper(t_window *window, int x, int y)
{
	if (window->map->map[y][x] == MAP_WALL || window->map->map[y][x] == SECRET_GUI)
		draw_something(window, x, y, 0x00303096);
	else if ((y == (int)window->player->pos->y / 32 && x == (int) \
		window->player->pos->x / 32))
		draw_something(window, x, y, 0x00C7565F);
	else if (window->map->map[y][x] == MAP_EMPTY_SPACE
		|| window->map->map[y][x] == MAP_DOOR_OPEN
		|| ft_strchr(PLAYER_POS, window->map->map[y][x]))
		draw_something(window, x, y, 0x00353542);
	else if (window->map->map[y][x] == MAP_DOOR_CLOSED)
		draw_something(window, x, y, 0x00686A6E);
	else if (window->map->map[y][x] == '\n')
		return (1);
	return (0);
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
			if (window->map->map[y][x]
				&& ft_draw_map_helper(window, x, y))
				break ;
			x++;
		}
		y++;
	}
}
