#include "../incl/cub3d.h"

int	ft_key_press(int keycode, t_window *window)
{
	if (keycode == KEY_ESCAPE)
		ft_close(window);
	if (keycode == KEY_W)
		window->player->key->w = 1;
	if (keycode == KEY_A)
		window->player->key->a = 1;
	if (keycode == KEY_S)
		window->player->key->s = 1;
	if (keycode == KEY_D)
		window->player->key->d = 1;
	if (keycode == ARROW_UP)
		window->player->key->a_u = 1;
	if (keycode == ARROW_DOWN)
		window->player->key->a_d = 1;
	if (keycode == ARROW_LEFT)
		window->player->key->a_l = 1;
	if (keycode == ARROW_RIGHT)
		window->player->key->a_r = 1;
	if (keycode == KEY_SPACEBAR)
		window->player->speed = M_SPRINT_SPEED;
	return (0);
}

int	ft_key_release(int keycode, t_window *window)
{
	if (keycode == KEY_W)
		window->player->key->w = 0;
	if (keycode == KEY_A)
		window->player->key->a = 0;
	if (keycode == KEY_S)
		window->player->key->s = 0;
	if (keycode == KEY_D)
		window->player->key->d = 0;
	if (keycode == ARROW_UP)
		window->player->key->a_u = 0;
	if (keycode == ARROW_DOWN)
		window->player->key->a_d = 0;
	if (keycode == ARROW_LEFT)
		window->player->key->a_l = 0;
	if (keycode == ARROW_RIGHT)
		window->player->key->a_r = 0;
	if (keycode == KEY_P && window->player->mouse_hide == 0)
		window->player->mouse_hide = 1;
	else if (keycode == KEY_P && window->player->mouse_hide == 1)
		window->player->mouse_hide = 0;
	if (keycode == KEY_SPACEBAR)
		window->player->speed = M_BASE_SPEED;
	return (0);
}

void	ft_move(t_window *window)
{
	int		mv_dist;
	t_key	*key;

	mv_dist = M_BASE_SPEED;
	if (window->player->key->spacebar == 1)
		mv_dist = M_SPRINT_SPEED;
	key = window->player->key;
	if (key->a && window->player->pos->x > mv_dist)
		ft_move_left(window);
	if (key->d && window->map->columns * 32 > window->player->pos->x
		+ mv_dist)
		ft_move_right(window);
	if ((key->a_u || key->w) && window->player->pos->y
		> mv_dist)
		ft_move_up(window);
	if ((key->a_d || key->s) && window->map->rows * 32
		> window->player->pos->y + mv_dist)
		ft_move_down(window);
	if (key->a_l)
		ft_turn_left(window, M_TURN_FACTOR);
	if (key->a_r)
		ft_turn_right(window, M_TURN_FACTOR);
	ft_mouse_tracker(window);
}

void	ft_turn_right(t_window *window, int diff_x)
{
	double	old_dir_x;
	double	old_plane_x;
	double	turn_speed;

	old_dir_x = window->player->dir->x;
	old_plane_x = window->player->plane.x;
	turn_speed = M_DEGREE_TURN * diff_x / M_TURN_FACTOR;
	window->player->dir->x = old_dir_x * cos(turn_speed) \
		- window->player->dir->y * sin(turn_speed);
	window->player->dir->y = old_dir_x * sin(turn_speed) \
		+ window->player->dir->y * cos(turn_speed);
	window->player->plane.x = old_plane_x * cos(turn_speed) \
		- window->player->plane.y * sin(turn_speed);
	window->player->plane.y = old_plane_x * sin(turn_speed) \
		+ window->player->plane.y * cos(turn_speed);
}

void	ft_turn_left(t_window *window, int diff_x)
{
	double	old_dir_x;
	double	old_plane_x;
	double	turn_speed;

	old_dir_x = window->player->dir->x;
	old_plane_x = window->player->plane.x;
	turn_speed = M_DEGREE_TURN * diff_x / M_TURN_FACTOR;
	window->player->dir->x = old_dir_x * cos(-turn_speed) \
		- window->player->dir->y * sin(-turn_speed);
	window->player->dir->y = old_dir_x * sin(-turn_speed) \
		+ window->player->dir->y * cos(-turn_speed);
	window->player->plane.x = old_plane_x * cos(-turn_speed) \
		- window->player->plane.y * sin(-turn_speed);
	window->player->plane.y = old_plane_x * sin(-turn_speed) \
		+ window->player->plane.y * cos(-turn_speed);
}
