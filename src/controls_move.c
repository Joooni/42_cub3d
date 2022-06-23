#include "../incl/cub3d.h"

void	ft_move_up(t_window *window)
{
	window->player->pos->x += window->player->dir->x;
	window->player->pos->y += window->player->dir->y;
}

void	ft_move_left(t_window *window)
{
	window->player->pos->x += window->player->dir->y;
	window->player->pos->y -= window->player->dir->x;
}

void	ft_move_right(t_window *window)
{
	window->player->pos->x -= window->player->dir->y;
	window->player->pos->y += window->player->dir->x;
}

void	ft_move_down(t_window *window)
{
	window->player->pos->x -= window->player->dir->x;
	window->player->pos->y -= window->player->dir->y;
}
