/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:07:41 by jtomala           #+#    #+#             */
/*   Updated: 2022/12/14 16:29:00 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	ft_free_player(t_window *window)
{
	free(window->player->key);
	free(window->player->pos);
	free(window->player->dir);
	free(window->check);
	free(window->player);
}

void	ft_free_ray(t_rc *ray)
{
	free(ray->delta_dist);
	free(ray->map_pos);
	free(ray->side_dist);
	free(ray->dir);
	free(ray);
}

void	ft_free_tex(t_window *window)
{
	ft_free_matrix(window->map->no_tex->matrix);
	free(window->map->no_tex);
	ft_free_matrix(window->map->ea_tex->matrix);
	free(window->map->ea_tex);
	ft_free_matrix(window->map->so_tex->matrix);
	free(window->map->so_tex);
	ft_free_matrix(window->map->we_tex->matrix);
	free(window->map->we_tex);
	free(window->map->wall_o_tex);
	ft_free_matrix(window->map->wall_c_tex->matrix);
	free(window->map->wall_c_tex);
	ft_free_matrix(window->map->gui_tex->matrix);
	free(window->map->gui_tex);

}

void	ft_free_matrix(t_color ***matrix)
{
	int	i;

	i = -1;
	while (++i < M_TEXTURE_HEIGHT)
		free(matrix[i]);
	free(matrix);
}

void	ft_free_map(t_window *window)
{
	int	i;

	i = 0;
	while (i < window->map->rows)
	{
		free(window->map->map[i]);
		i++;
	}
	free(window->map->map);
}
