/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:17:11 by jtomala           #+#    #+#             */
/*   Updated: 2022/09/05 13:21:31 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	ft_key_press2(int keycode, t_window *window)
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
}

void	ft_key_release2(int keycode, t_window *window)
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
}