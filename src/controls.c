/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:07:27 by jtomala           #+#    #+#             */
/*   Updated: 2022/09/05 13:20:10 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	ft_key_press(int keycode, t_window *window)
{
	ft_key_press2(keycode, window);
	if (keycode == KEY_SPACEBAR)
		window->player->speed = M_SPRINT_SPEED;
	if (keycode == KEY_M)
		window->player->key->m = 1;
	if (keycode == KEY_E && window->player->key->e == 0)
	{
		window->time_stamp = curr_time(window);
		window->player->key->e = 1;
	}
	return (0);
}

int	ft_key_release(int keycode, t_window *window)
{
	ft_key_release2(keycode, window);
	if (keycode == KEY_P && window->player->mouse_hide == 0)
		window->player->mouse_hide = 1;
	else if (keycode == KEY_P && window->player->mouse_hide == 1)
		window->player->mouse_hide = 0;
	if (keycode == KEY_SPACEBAR)
		window->player->speed = M_BASE_SPEED;
	if (keycode == KEY_M)
		window->player->key->m = 0;
	if (keycode == KEY_E && window->player->key->e == 1)
	{
		window->time_stamp = curr_time(window);
		window->player->key->e = 0;
	}
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
