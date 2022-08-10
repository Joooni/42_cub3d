#include "../incl/cub3d.h"

void	ft_move_up(t_window *window)
{
	int	pos_x;
	int	pos_y;

	pos_x = (window->player->pos->x
			+ window->player->dir->x * window->player->speed) / 32;
	pos_y = (window->player->pos->y
			+ window->player->dir->y * window->player->speed) / 32;
	if (ft_isvalidchar(window, pos_x, pos_y))
	{
		window->player->pos->x += window->player->dir->x
			* window->player->speed;
		window->player->pos->y += window->player->dir->y
			* window->player->speed;
	}
}

void	ft_move_left(t_window *window)
{
	int	pos_x;
	int	pos_y;

	pos_x = (window->player->pos->x
			+ window->player->dir->y * window->player->speed) / 32;
	pos_y = (window->player->pos->y
			- window->player->dir->x * window->player->speed) / 32;
	if (ft_isvalidchar(window, pos_x, pos_y))
	{
		window->player->pos->x -= window->player->plane.x
			* window->player->speed;
		window->player->pos->y -= window->player->plane.y
			* window->player->speed;
	}
}

void	ft_move_right(t_window *window)
{
	int	pos_x;
	int	pos_y;

	pos_x = (window->player->pos->x
			+ window->player->plane.x * window->player->speed) / 32;
	pos_y = (window->player->pos->y
			+ window->player->plane.y * window->player->speed) / 32;
	if (ft_isvalidchar(window, pos_x, pos_y))
	{
		window->player->pos->x += window->player->plane.x
			* window->player->speed;
		window->player->pos->y += window->player->plane.y
			* window->player->speed;
	}
}

void	ft_move_down(t_window *window)
{
	int	pos_x;
	int	pos_y;

	pos_x = (window->player->pos->x
			- window->player->dir->x * window->player->speed) / 32;
	pos_y = (window->player->pos->y
			- window->player->dir->y * window->player->speed) / 32;
	if (ft_isvalidchar(window, pos_x, pos_y))
	{
		window->player->pos->x -= window->player->dir->x
			* window->player->speed;
		window->player->pos->y -= window->player->dir->y
			* window->player->speed;
	}
}

void	ft_mouse_tracker(t_window *window)
{
	int	x;
	int	y;

	if (window->player->mouse_hide)
		mlx_mouse_show(window->mlx, window->win);
	if (!window->player->mouse_hide)
	{
		mlx_mouse_hide(window->mlx, window->win);
		mlx_mouse_get_pos(window->win, &x, &y);
		if (x > WINDOW_WIDTH / 2)
			ft_turn_right(window, x - WINDOW_WIDTH / 2);
		if (x < WINDOW_WIDTH / 2)
			ft_turn_left(window, WINDOW_WIDTH / 2 - x);
		mlx_mouse_move(window->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		window->player->mouse_x = x;
		return ;
	}
}
