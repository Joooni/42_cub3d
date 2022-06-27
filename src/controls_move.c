#include "../incl/cub3d.h"

void	ft_move_up(t_window *window)
{
	int pos_x;
	int pos_y;

	pos_x = (window->player->pos->x + window->player->dir->x) / 32;
	pos_y = (window->player->pos->y + window->player->dir->y) / 32;
	if (window->map->map[pos_y][pos_x] != '1')
	{
		window->player->pos->x += window->player->dir->x;
		window->player->pos->y += window->player->dir->y;
	}
}

void	ft_move_left(t_window *window)
{
	int pos_x;
	int pos_y;

	pos_x = (window->player->pos->x + window->player->dir->y) / 32;
	pos_y = (window->player->pos->y - window->player->dir->x) / 32;
	if (window->map->map[pos_y][pos_x] != '1')
	{
		window->player->pos->x += window->player->dir->y;
		window->player->pos->y -= window->player->dir->x;
	}
}

void	ft_move_right(t_window *window)
{
	int pos_x;
	int pos_y;

	pos_x = (window->player->pos->x - window->player->dir->y) / 32;
	pos_y = (window->player->pos->y + window->player->dir->x) / 32;
	if (window->map->map[pos_y][pos_x] != '1')
	{
		window->player->pos->x -= window->player->dir->y;
		window->player->pos->y += window->player->dir->x;
	}
}

void	ft_move_down(t_window *window)
{
	int pos_x;
	int pos_y;

	pos_x = (window->player->pos->x - window->player->dir->x) / 32;
	pos_y = (window->player->pos->y - window->player->dir->y) / 32;
	if (window->map->map[pos_y][pos_x] != '1')
	{
		window->player->pos->x -= window->player->dir->x;
		window->player->pos->y -= window->player->dir->y;
	}
}
