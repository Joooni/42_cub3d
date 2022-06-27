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
	return (0);
}

void	ft_move(t_window *window)
{
	int		mv_dist;
	t_key	*key;

	mv_dist = 8;
	key = window->player->key;
	if (key->a && window->player->pos->x > mv_dist)
		ft_move_left(window);
	if (key->d && WINDOW_WIDTH > window->player->pos->x
		+ mv_dist)
		ft_move_right(window);
	if ((key->a_u || key->w) && window->player->pos->y
		> mv_dist)
		ft_move_up(window);
	if ((key->a_d || key->s) && WINDOW_HEIGHT
		> window->player->pos->y + mv_dist)
		ft_move_down(window);
	if (key->a_l)
		ft_turn_left(window);
	if (key->a_r)
		ft_turn_right(window);
	ft_mouse_tracker(window);
}

void	ft_turn_right(t_window *window)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = window->player->dir->x;
	old_plane_x = window->player->plane.x;
	window->player->dir->x = old_dir_x * cos(M_DEGREE_TURN) \
		- window->player->dir->y * sin(M_DEGREE_TURN);
	window->player->dir->y = old_dir_x * sin(M_DEGREE_TURN) \
		+ window->player->dir->y * cos(M_DEGREE_TURN);
	window->player->plane.x = old_plane_x * cos(M_DEGREE_TURN) \
		- window->player->plane.y * sin(M_DEGREE_TURN);
	window->player->plane.y = old_plane_x * sin(M_DEGREE_TURN) \
		+ window->player->plane.y * cos(M_DEGREE_TURN);
}

void	ft_turn_left(t_window *window)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = window->player->dir->x;
	old_plane_x = window->player->plane.x;
	window->player->dir->x = old_dir_x * cos(M_DEGREE_TURN) \
		+ window->player->dir->y * sin(M_DEGREE_TURN);
	window->player->dir->y = old_dir_x * sin(M_DEGREE_TURN) \
		* -1 + window->player->dir->y * cos(M_DEGREE_TURN);
	window->player->plane.x = old_plane_x * cos(M_DEGREE_TURN) \
		+ window->player->plane.y * sin(M_DEGREE_TURN);
	window->player->plane.y = old_plane_x * sin(M_DEGREE_TURN) \
		* -1 + window->player->plane.y * cos(M_DEGREE_TURN);
}
