#include "../incl/cub3d.h"

int	ft_key_press(int keycode, t_window *window)
{
	if (keycode == KEY_ESCAPE)
		ft_close(window);
	else if (keycode == ARROW_UP || keycode == ARROW_DOWN
		|| keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D )
		ft_move(keycode, window);
	else if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT)
		ft_turn(keycode, window);
	else
		printf(":c I don't know that key, sorry. :c\n");
	return (0);
}

void ft_move_to_dir(t_window *window, int keycode)
{
	t_vec *vec;
	int faktor_x;
	int faktor_y;

	faktor_x = 1;
	faktor_y = 1;
	if (window->player->dir->x < 0)
		faktor_x = -1;
	if (window->player->dir->y < 0)
		faktor_y = -1;

	vec = window->player->pos;
	if (keycode == KEY_W)
	{
		vec->x += window->player->dir->x;
		vec->y += window->player->dir->y;
	}
	else if (keycode == KEY_S)
	{
		vec->x -= window->player->dir->x;
		vec->y -= window->player->dir->y;
	}
	else if (keycode == KEY_A)
	{
		vec->x += window->player->dir->y;
		vec->y -= window->player->dir->x;
	}
	else if (keycode == KEY_D)
	{
		vec->x -= window->player->dir->y;
		vec->y += window->player->dir->x;
	}
}


void	ft_move(int keycode, t_window *window)
{
	int	mv_dist;

	mv_dist = 8;
	if (keycode == KEY_A && window->player->pos->x > mv_dist)
		ft_move_to_dir(window, KEY_A);
	else if (keycode == KEY_D && WINDOW_WIDTH > window->player->pos->x + mv_dist)
		ft_move_to_dir(window, KEY_D);
	else if ((keycode == ARROW_UP || keycode == KEY_W) && window->player->pos->y >
		mv_dist)
		ft_move_to_dir(window, KEY_W);
	else if ((keycode == ARROW_DOWN || keycode == KEY_S) && WINDOW_HEIGHT >
		window->player->pos->y + mv_dist)
		ft_move_to_dir(window, KEY_S);
}

void	ft_turn(int keycode, t_window *window)
{
	double	old_dir_x;

	old_dir_x = window->player->dir->x;
	if (keycode == ARROW_RIGHT)
	{
		window->player->dir->x = old_dir_x * cos(M_DEGREE_TURN) - window->player->dir->y * sin(M_DEGREE_TURN);
		window->player->dir->y = old_dir_x * sin(M_DEGREE_TURN) + window->player->dir->y * cos(M_DEGREE_TURN);
	}
	else
	{
		window->player->dir->x = old_dir_x * cos(M_DEGREE_TURN) + window->player->dir->y * sin(M_DEGREE_TURN);
		window->player->dir->y = old_dir_x * sin(M_DEGREE_TURN) * -1 + window->player->dir->y * cos(M_DEGREE_TURN);
	}
}