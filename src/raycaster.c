#include "../incl/cub3d.h"

void	ft_cast_ray(t_window *window, t_rc *rc)
{
	ft_init_rc(window, rc);
	ft_calc_step(window, rc);
	ft_calc_hit(*(window->map), window->player);
}

void	ft_calc_hit(t_map map, t_player *player)
{
	int	wall_hit;
	int	wall_side;

	wall_hit = 0;
	while (wall_hit == 0)
	{
		if (player->ray->side_dist->x < player->ray->side_dist->y)
		{
			player->ray->side_dist->x += player->ray->delta_dist->x;
			player->ray->map_pos->x += player->step.x;
			printf("ray cast in x direction!\n");
			wall_side = 0;
		}
		else
		{
			player->ray->side_dist->y += player->ray->delta_dist->y;
			player->ray->map_pos->y += player->step.y;
			printf("ray cast in y direction!\n");
			wall_side = 1;
		}
		if (map.map[(int)player->ray->map_pos->y][(int) player->ray->map_pos->x] == '1')
			wall_hit = 1;
	}
	printf("wall hit!\n");
}

void	ft_calc_step(t_window *window, t_rc *rc)
{
	if (rc->dir->x < 0)
	{
		window->player->step.x = -1;
		rc->side_dist->x = (window->player->pos->x - rc->map_pos->x) * rc->delta_dist->x;
	}
	else
	{
		window->player->step.x = 1;
		rc->side_dist->x = (rc->map_pos->x + 1.0 - window->player->pos->x) * rc->delta_dist->x;
	}
	if (rc->dir->y < 0)
	{
		window->player->step.y = -1;
		rc->side_dist->y = (window->player->pos->y - rc->map_pos->y) * rc->delta_dist->y;
	}
	else
	{
		window->player->step.y = 1;
		rc->side_dist->y = (rc->map_pos->y + 1.0 - window->player->pos->y) * rc->delta_dist->y;
	}
	printf("initial side distances:\nx: %f	y: %f\n", rc->side_dist->x, rc->side_dist->y);
}

void	ft_init_rc(t_window *window, t_rc *rc)
{
	double	camera_x;
	double plane_x = 0;
	double plane_y = 0.66;

	camera_x = 2 * rc->pixel.x / (double)WINDOW_WIDTH - 1;
	rc->map_pos->x = (int)window->player->pos->x / 32;
	rc->map_pos->y = (int)window->player->pos->y / 32;
	rc->dir->x = window->player->dir->x + plane_x * camera_x;
	rc->dir->y = window->player->dir->y + plane_y * camera_x;
	printf("rc dirs:\nx: %f	y: %f\n", rc->dir->x, rc->dir->y);
	if (rc->dir->x == 0)
		rc->delta_dist->x = INFINITY;
	else
		rc->delta_dist->x = ft_abs(1 / rc->dir->x);
	if (rc->delta_dist->x == 0)
		rc->delta_dist->x = INFINITY;
	else
		rc->delta_dist->y = ft_abs(1 / rc->dir->y);
}
