/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3drawing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:07:00 by jtomala           #+#    #+#             */
/*   Updated: 2022/09/05 13:12:39 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

static int	door_checker(t_window *window, t_rc *ray);

void	drawing_handler(t_window *window, t_rc *ray, int x)
{
	ft_calc_tex_x(window, ray);
	ft_draw_floor_ceiling(window, ray, x);
	ray->step_tex = 1.0 * M_TEXTURE_HEIGHT / ray->line_height;
	ray->tex_pos = (ray->draw_start - WINDOW_HEIGHT / 2
			+ ray->line_height / 2) * ray->step_tex;
	while (ray->draw_start <= ray->draw_end)
	{
		ray->color = door_checker(window, ray);
		ray->tex.y = (int)ray->tex_pos & (M_TEXTURE_HEIGHT - 1);
		ray->tex_pos += ray->step_tex;
		if (ray->side == 1 && ray->dir->y > 0 && ray->hit == 1)
			ray->color = ft_tcolor_to_int(*(window->map->so_tex
						->matrix[ray->tex.y][ray->tex.x]));
		else if (ray->side == 0 && ray->dir->x > 0 && ray->hit == 1)
			ray->color = ft_tcolor_to_int(*(window->map->ea_tex
						->matrix[ray->tex.y][ray->tex.x]));
		else if (ray->side == 0 && ray->dir->x < 0 && ray->hit == 1)
			ray->color = ft_tcolor_to_int(*(window->map->we_tex
						->matrix[ray->tex.y][ray->tex.x]));
		ft_pixel_put_img(window->img, x, ray->draw_start, ray->color);
		ray->draw_start++;
	}
}

static int	door_checker(t_window *window, t_rc *ray)
{
	int	door_dist_x;
	int	door_dist_y;

	door_dist_x = abs((int)window->player->pos->x / 32 - ray->door_pos.x);
	door_dist_y = abs((int)window->player->pos->y / 32 - ray->door_pos.y);
	if (ray->hit == 2 && window->player->key->e == 1 \
		&& ray->wall_dist_perp < 33 && (curr_time(window)
			- window->time_stamp) / 1000 < 0.2)
			window->map->map[(int)ray->map_pos->y][(int)ray->map_pos->x] = '3';
	else if (ray->door_flag == 1 && window->player->key->e == 1 \
		&& (door_dist_x <= 1 && door_dist_y <= 1) && (curr_time(window)
			- window->time_stamp) / 1000 > 0.2)
		window->map->map[(int)ray->door_pos.y][(int)ray->door_pos.x] = '2';
	if (ray->hit == 2)
		return (ft_tcolor_to_int(*(window->map->wall_c_tex \
			->matrix[ray->tex.y][ray->tex.x])));
	return (ft_tcolor_to_int(*(window->map->no_tex \
			->matrix[ray->tex.y][ray->tex.x])));
}

void	ft_draw_floor_ceiling(t_window *window, t_rc *ray, int x)
{
	int	iterator;
	int	fc;

	iterator = 0;
	fc = ft_tcolor_to_int(*(window->map->c));
	while (iterator < ray->draw_start)
		ft_pixel_put_img(window->img, x, iterator++, fc);
	fc = ft_tcolor_to_int(*(window->map->f));
	iterator = ray->draw_end;
	while (iterator < WINDOW_HEIGHT)
		ft_pixel_put_img(window->img, x, iterator++, fc);
}

void	ft_calc_tex_x(t_window *window, t_rc *ray)
{
	ray->line_height = (WINDOW_HEIGHT / ray->wall_dist_perp) * 32;
	ray->draw_start = -ray->line_height / 2 + WINDOW_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WINDOW_HEIGHT / 2;
	if (ray->draw_end >= WINDOW_HEIGHT)
		ray->draw_end = WINDOW_HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_hit_x = window->player->pos->y
			+ ray->wall_dist_perp * ray->dir->y;
	else
		ray->wall_hit_x = window->player->pos->x
			+ ray->wall_dist_perp * ray->dir->x;
	ray->tex.x = (int)ray->wall_hit_x % (int)M_TEXTURE_WIDTH;
	if (ray->side == 0 && ray->dir->x > 0)
		ray->tex.x = M_TEXTURE_WIDTH - ray->tex.x - 1;
	if (ray->side == 1 && ray->dir->y < 0)
		ray->tex.x = M_TEXTURE_WIDTH - ray->tex.x - 1;
}
