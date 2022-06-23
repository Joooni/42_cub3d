#include "../incl/cub3d.h"

void	ft_cast_ray(t_window *window, t_rc *rc)
{
	ft_init_rc(window, rc);
	ft_calc_step(window, rc);
	ft_calc_hit(*(window->map), rc);
}

void	ft_calc_hit(t_map map, t_rc *ray)
{
	int		wall_hit;
	int		wall_side;
	double	wall_distance;

	wall_hit = 0;
	while (wall_hit == 0)
	{
		if (ray->side_dist->x < ray->side_dist->y)
		{
			ray->side_dist->x += ray->delta_dist->x * 32;
			ray->map_pos->x += ray->step.x;
			wall_side = 0;
		}
		else
		{
			ray->side_dist->y += ray->delta_dist->y * 32;
			ray->map_pos->y += ray->step.y;
			wall_side = 1;
		}
		if (map.map[(int)ray->map_pos->y][(int) ray->map_pos->x] == '1')
			wall_hit = 1;
	}
	if (wall_side == 0)
		wall_distance = (ray->side_dist->x - ray->delta_dist->x) * 32;
	else
		wall_distance = (ray->side_dist->y - ray->delta_dist->y) * 32;
}

void	ft_calc_step(t_window *window, t_rc *rc)
{
	if (rc->dir->x < 0)
	{
		rc->step.x = -1;
		rc->side_dist->x = (window->player->pos->x
				- rc->map_pos->x * 32) * rc->delta_dist->x;
	}
	else
	{
		rc->step.x = 1;
		rc->side_dist->x = (32 * (rc->map_pos->x + 1.0)
				- window->player->pos->x) * rc->delta_dist->x;
	}
	if (rc->dir->y < 0)
	{
		rc->step.y = -1;
		rc->side_dist->y = (window->player->pos->y
				- rc->map_pos->y * 32) * rc->delta_dist->y;
	}
	else
	{
		rc->step.y = 1;
		rc->side_dist->y = (32 * (rc->map_pos->y + 1.0)
				- window->player->pos->y) * rc->delta_dist->y;
	}
}

void	ft_init_rc(t_window *window, t_rc *rc)
{
	rc->map_pos->x = (int)window->player->pos->x / 32;
	rc->map_pos->y = (int)window->player->pos->y / 32;
	rc->dir->x = window->player->dir->x;
	rc->dir->y = window->player->dir->y + window->player->camera.x * 0.66;
	if (rc->dir->x == 0)
		rc->delta_dist->x = INFINITY;
	else
		rc->delta_dist->x = fabs(1 / rc->dir->x);
	if (rc->dir->y == 0)
		rc->delta_dist->x = INFINITY;
	else
		rc->delta_dist->y = fabs(1 / rc->dir->y);
}
