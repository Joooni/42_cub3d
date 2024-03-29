/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:07:18 by jtomala           #+#    #+#             */
/*   Updated: 2022/09/05 13:59:46 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	char_surrounded_my_valid(t_window *window, int i, int j)
{
	if (ft_strchr(VALID_SYMBOLS, window->map->map[i][j - 1]) == NULL
		|| ft_strchr(VALID_SYMBOLS, window->map->map[i][j + 1]) == NULL
		|| ft_strchr(VALID_SYMBOLS, window->map->map[i - 1][j]) == NULL
		|| ft_strchr(VALID_SYMBOLS, window->map->map[i + 1][j]) == NULL)
	{
		ft_end_process(ERR_INV_MAP);
	}
	return (1);
}

int	character_is_surrounded(t_window *window, int i, int j)
{
	if (!square_left_exists(window, i, j)
		|| !square_right_exists(window, i, j)
		|| !square_above_exists(window, i, j)
		|| !square_below_exists(window, i, j))
	{
		ft_end_process(ERR_INV_MAP);
	}
	return (1);
}

int	check_map(t_window *window)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (window->map->map[i] != NULL && i < window->map->rows)
	{
		j = 0;
		while (window->map->map[i][j] && window->map->map[i][j] != '\n' )
		{
			if (window->map->map[i][j] == '0' || window->map->map[i][j] == '2'
				|| ft_strchr(PLAYER_POS, window->map->map[i][j]))
				if (!character_is_surrounded(window, i, j)
					|| !char_surrounded_my_valid(window, i, j))
					return (0);
			j++;
		}
		i++;
	}
	if (!init_colors(window))
		return (0);
	return (1);
}
