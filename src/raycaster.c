#include "../incl/cub3d.h"

void	ft_cast_ray(t_window *window, t_rc *ray)
{
	ft_init_rc(window, ray);
	ft_calc_step(window, ray);
	ft_calc_hit(*(window->map), ray);
	ft_draw_to_wall(window, ray);
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
	printf("hit at coordinates: (%d/%d)\n", ray->map_pos->x, ray->map_pos->y);
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

//testweise änderung
void	ft_init_rc(t_window *window, t_rc *ray)
{
	ray->map_pos->x = (int)window->player->pos->x / 32;
	ray->map_pos->y = (int)window->player->pos->y / 32;
	ray->dir->x = window->player->dir->x;
	ray->dir->y = window->player->dir->y + window->player->camera.x * 0.66;
	if (ray->dir->x == 0)
		ray->delta_dist->x = INFINITY;
	else
		ray->delta_dist->x = fabs(1 / ray->dir->x);
	if (ray->dir->y == 0)
		ray->delta_dist->x = INFINITY;
	else
		ray->delta_dist->y = fabs(1 / ray->dir->y);
	ray->hit = 0;
}

void	ft_calc_distance(t_rc *ray)
{
	if (ray->side == 0)
		ray->wall_dist_perp = (ray->side_dist->x  - 32 * ray->delta_dist->x);
	else
		ray->wall_dist_perp = (ray->side_dist->y  - 32 * ray->delta_dist->y);
}

void	ft_draw_to_wall(t_window *window, t_rc *ray)
{
	double	vec_x;
	double	vec_y;
	t_vec	*vec;

	vec_x = ray->dir->x;
	vec_y = ray->dir->y;
	ft_calc_distance(ray);
	printf("############################\n");
	printf("side distances: (%f / %f)\n", ray->side_dist->x, ray->side_dist->y);
	printf("delta distances: (%f / %f)\n", ray->delta_dist->x, ray->delta_dist->x);

	printf("ray dir: (%f / %f)\n",ray->dir->x, ray->dir->y);
	printf("player pos: (%f / %f)\n", window->player->pos->x, window->player->pos->y);
	printf("wall_dist_perp: %f\n", ray->wall_dist_perp);
	printf("############################\n");
	while (sqrt((vec_x * vec_x) + (vec_y * vec_y)) <= ray->wall_dist_perp)
	{
		vec_x += ray->dir->x;
		vec_y += ray->dir->y;
	}
	vec = ft_init_vector(vec_x, vec_y);
	ft_draw_vector(window, *vec);

//	printf("map tile: (%d / %d)\n", (int)window->player->pos->x / 32, (int)window->player->pos->y / 32);
}