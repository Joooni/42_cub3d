/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalidchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:35:56 by jsubel            #+#    #+#             */
/*   Updated: 2022/08/10 12:18:16 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	ft_isvalidchar(t_window *window, int pos_x, int pos_y)
{
	if (window->map->map[pos_y][pos_x] && (window->map->map[pos_y][pos_x] == '0' \
		|| window->map->map[pos_y][pos_x] == '3' || ft_strchr(PLAYER_POS, window->map->map[pos_y][pos_x])))
		return (1);
	return (0);
}

int	new_line_check(t_window *window, char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (ft_isdigit(line[i]))
		window->map->new_line = 1;
	if (!ft_strncmp(line, "\n", 1) && window->map->new_line == 1)
		ft_end_process(ERR_INV_MAP);
	i++;
	return (0);
}
