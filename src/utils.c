/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:08:15 by jtomala           #+#    #+#             */
/*   Updated: 2022/09/05 17:26:09 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

/** @brief check if image and window are there and if, destroy
 * and then exit the program */
int	ft_close(t_window *window)
{
	ft_free_tex(window);
	ft_free_player(window);
	ft_free_map(window);
	if (window->img->img != NULL)
	{
		mlx_destroy_image(window->mlx, window->img->img);
	}
	if (window->win != NULL)
	{
		mlx_destroy_window(window->mlx, window->win);
	}
	exit(0);
}

int	ft_tcolor_to_int(t_color color)
{
	return (color.t << 24 | color.red << 16
		| color.green << 8 | color.blue);
}

void check_if_exists(t_window *window)
{
	if (window->map->c_tex == NULL || window->map->f_tex == NULL)
		ft_end_process(ERR_INV_TEX);
}