/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:08:12 by jtomala           #+#    #+#             */
/*   Updated: 2022/12/15 10:41:12 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

// returns the current time since Epoch in milliseconds
long long	get_time(void)
{
	struct timeval	tp;
	long long		time;

	gettimeofday(&tp, NULL);
	time = (tp.tv_sec * 1000) + (tp.tv_usec / 1000);
	return (time);
}

// Returns the time since program start in milliseconds
long long	curr_time(t_window *window)
{
	return ((get_time() - window->start_time));
}

// print FPS in the top right corner
void	render_time(t_window *window)
{
	char		*temp;
	u_int64_t	time;
	double		frametime;

	time = get_time() - window->start_time;
	frametime = (time - window->old_time) / 1000.0;
	temp = ft_itoa((int)(1 / frametime));
	window->old_time = time;
	int color;
	color = 0x444444;
	if (window->player->key->m == 1)
		color = 0xFFFFFF;
	mlx_string_put(window->mlx, window->win, WINDOW_WIDTH - 50, 25, \
		color, temp);
	mlx_string_put(window->mlx, window->win, WINDOW_WIDTH - 35, 25, \
		color, "FPS");
	mlx_string_put(window->mlx, window->win, 35, WINDOW_HEIGHT - 75, \
		color, "ESCAPE\t - CLOSE GAME");
	mlx_string_put(window->mlx, window->win, 35, WINDOW_HEIGHT - 60, \
		color, "SPACEBAR\t - SPRINT");
	mlx_string_put(window->mlx, window->win, 35, WINDOW_HEIGHT - 45, \
		color, "M\t - MINIMAP");
	mlx_string_put(window->mlx, window->win, 35, WINDOW_HEIGHT - 30, \
		color, "E\t - OPEN/CLOSE DOOR");
	free(temp);
}
