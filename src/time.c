/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:08:12 by jtomala           #+#    #+#             */
/*   Updated: 2022/12/14 17:00:11 by jsubel           ###   ########.fr       */
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
	mlx_string_put(window->mlx, window->win, WINDOW_WIDTH - 50, 25, \
		0x444444, temp);
	mlx_string_put(window->mlx, window->win, WINDOW_WIDTH - 35, 25, \
		0x444444, "FPS");
	mlx_string_put(window->mlx, window->win, 35, WINDOW_HEIGHT - 75, \
		0x444444, "ESCAPE\t - CLOSE GAME");
	mlx_string_put(window->mlx, window->win, 35, WINDOW_HEIGHT - 60, \
		0x444444, "SPACEBAR\t - SPRINT");
	mlx_string_put(window->mlx, window->win, 35, WINDOW_HEIGHT - 45, \
		0x444444, "M\t - MINIMAP");
	mlx_string_put(window->mlx, window->win, 35, WINDOW_HEIGHT - 30, \
		0x444444, "E\t - OPEN/CLOSE DOOR");
	free(temp);
}
