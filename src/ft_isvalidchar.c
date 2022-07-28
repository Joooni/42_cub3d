/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalidchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:35:56 by jsubel            #+#    #+#             */
/*   Updated: 2022/07/28 13:35:20 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int	ft_isvalidchar(int c)
{
	if ((c >= '0' && c <= '3') || c == 'N' || c == 'O' || c == 'S' \
		|| c == 'W' || c == 'E' || c == 'A' || c == 'F' || c == 'C' \
		|| c == 'D' || c == 'O' || c == '\n' || c == '1')
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
