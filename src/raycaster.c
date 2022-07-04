#include "../incl/cub3d.h"

void	ft_cast_ray(t_window *window)
{
	int		i;
	t_rc	*ray;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		window->player->camera.x = 2 * i / (double)WINDOW_WIDTH - 1;
		ray = ft_init_ray();
		ft_init_rc(window, ray);
		ft_calc_step(window, ray);
		ray->hit = 0;
		ft_calc_hit(*(window->map), ray);
		if (ray->side == 0)
			ray->wall_dist_perp = (ray->side_dist->x - 32 * ray->delta_dist->x);
		else
			ray->wall_dist_perp = (ray->side_dist->y - 32 * ray->delta_dist->y);
		drawing_handler(window, ray, i);
		ft_free_ray(ray);
		i++;
	}
}

void	ft_init_rc(t_window *window, t_rc *ray)
{
	ray->map_pos->x = (int)window->player->pos->x / 32;
	ray->map_pos->y = (int)window->player->pos->y / 32;
	ray->dir->x = window->player->dir->x
		+ window->player->camera.x * window->player->plane.x;
	ray->dir->y = window->player->dir->y
		+ window->player->camera.x * window->player->plane.y;
	if (ray->dir->x == 0)
		ray->delta_dist->x = INFINITY;
	else
		ray->delta_dist->x = fabs(1 / ray->dir->x);
	if (ray->dir->y == 0)
		ray->delta_dist->x = INFINITY;
	else
		ray->delta_dist->y = fabs(1 / ray->dir->y);
}

void	ft_calc_hit(t_map map, t_rc *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist->x < ray->side_dist->y)
		{
			ray->side_dist->x += ray->delta_dist->x * 32;
			ray->map_pos->x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist->y += ray->delta_dist->y * 32;
			ray->map_pos->y += ray->step.y;
			ray->side = 1;
		}
		if (map.map[(int)ray->map_pos->y][(int) ray->map_pos->x] == '1')
			ray->hit = 1;
	}
}

void	ft_calc_step(t_window *window, t_rc *ray)
{
	if (ray->dir->x < 0)
	{
		ray->step.x = -1;
		ray->side_dist->x = (window->player->pos->x
				- ray->map_pos->x * 32) * ray->delta_dist->x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist->x = (32 * (ray->map_pos->x + 1.0)
				- window->player->pos->x) * ray->delta_dist->x;
	}
	if (ray->dir->y < 0)
	{
		ray->step.y = -1;
		ray->side_dist->y = (window->player->pos->y
				- ray->map_pos->y * 32) * ray->delta_dist->y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist->y = (32 * (ray->map_pos->y + 1.0)
				- window->player->pos->y) * ray->delta_dist->y;
	}
}

// void	ft_draw_to_wall(t_rc *ray)
// {
// 	// double	vec_x;
// 	// double	vec_y;
// 	// t_vec	*vec;

// 	// vec_x = ray->dir->x;
// 	// vec_y = ray->dir->y;
// 	if (ray->side == 0)
// 		ray->wall_dist_perp = (ray->side_dist->x - 32 * ray->delta_dist->x);
// 	else
// 		ray->wall_dist_perp = (ray->side_dist->y - 32 * ray->delta_dist->y);
// 	// while (sqrt((vec_x * vec_x) + (vec_y * vec_y)) <= ray->wall_dist_perp)
// 	// {
// 	// 	vec_x += ray->dir->x;
// 	// 	vec_y += ray->dir->y;
// 	// }
// 	// vec = ft_init_vector(vec_x, vec_y);
// 	// ft_draw_vector(window, *vec);
// }
