/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:07:22 by jtomala           #+#    #+#             */
/*   Updated: 2022/09/05 13:12:49 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

//universal but with the others it is easier to read
int	square_exists(t_window *window, int i, int j)
{
	if ((i > 0 && i < window->map->rows - 1)
		&& (j > 0 && j < (int)ft_strlen(window->map->map[i])))
		return (1);
	return (0);
}

int	square_below_exists(t_window *window, int i, int j)
{
	if ((i + 1 > 0 && i + 1 <= window->map->rows - 1)
		&& (j > 0 && j < (int)ft_strlen(window->map->map[i + 1])))
		return (1);
	return (0);
}

int	square_above_exists(t_window *window, int i, int j)
{
	if ((i - 1 >= 0 && i - 1 <= window->map->rows - 1)
		&& (j < (int)ft_strlen(window->map->map[i - 1])))
		return (1);
	return (0);
}

int	square_left_exists(t_window *window, int i, int j)
{
	if ((i > 0 && i < window->map->rows - 1)
		&& (j - 1 >= 0 && j - 1 <= (int)ft_strlen(window->map->map[i - 1]) - 1))
		return (1);
	return (0);
}

int	square_right_exists(t_window *window, int i, int j)
{
	if ((i > 0 && i < window->map->rows - 1)
		&& (j + 1 > 0 && j + 1 < (int)ft_strlen(window->map->map[i - 1])))
		return (1);
	return (0);
}
