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
	double	wall_distance;

	wall_hit = 0;
	while (wall_hit == 0)
	{
		if (player->ray->side_dist->x < player->ray->side_dist->y)
		{
			player->ray->side_dist->x += player->ray->delta_dist->x * 32;
			player->ray->map_pos->x += player->ray->step.x;
			printf("ray cast in x direction!\n");
			wall_side = 0;
		}
		else
		{
			player->ray->side_dist->y += player->ray->delta_dist->y * 32;
			player->ray->map_pos->y += player->ray->step.y;
			printf("ray cast in y direction!\n");
			wall_side = 1;
		}
		if (map.map[(int)player->ray->map_pos->y][(int) player->ray->map_pos->x] == '1')
			wall_hit = 1;
		printf("new side dist:\nx: %f	y: %f\n", player->ray->side_dist->x, player->ray->side_dist->y);
	}
	if (wall_side == 0)
		wall_distance = (player->ray->side_dist->x - player->ray->delta_dist->x) * 32;
	else
		wall_distance = (player->ray->side_dist->y - player->ray->delta_dist->y) * 32;
	printf("wall hit! distance to wall from camera plane: %f\nCell coordinates: (%d/%d)\n", wall_distance, player->ray->map_pos->x, player->ray->map_pos->y);
}

void	ft_calc_step(t_window *window, t_rc *rc)
{
	if (rc->dir->x < 0)
	{
		rc->step.x = -1;
		rc->side_dist->x = (window->player->pos->x - rc->map_pos->x * 32) * rc->delta_dist->x;
	}
	else
	{
		rc->step.x = 1;
		rc->side_dist->x = (32 * (rc->map_pos->x + 1.0) - window->player->pos->x) * rc->delta_dist->x;
	}
	if (rc->dir->y < 0)
	{
		rc->step.y = -1;
		rc->side_dist->y = (window->player->pos->y - rc->map_pos->y * 32) * rc->delta_dist->y;
	}
	else
	{
		rc->step.y = 1;
		rc->side_dist->y = (32 * (rc->map_pos->y + 1.0) - window->player->pos->y) * rc->delta_dist->y;
	}
	printf("	side distances:\nx: %f	y: %f\n", rc->side_dist->x, rc->side_dist->y);
}

void	ft_init_rc(t_window *window, t_rc *rc)
{
	rc->map_pos->x = (int)window->player->pos->x / 32;
	rc->map_pos->y = (int)window->player->pos->y / 32;
	rc->dir->x = window->player->dir->x;
	rc->dir->y = window->player->dir->y + window->player->camera.x * 0.66;
	printf("	ray dirs:\nx: %f	y: %f\n", rc->dir->x, rc->dir->y);
	if (rc->dir->x == 0)
		rc->delta_dist->x = INFINITY;
	else
		rc->delta_dist->x = fabs(1 / rc->dir->x);
	if (rc->dir->y == 0)
		rc->delta_dist->x = INFINITY;
	else
		rc->delta_dist->y = fabs(1 / rc->dir->y);
	printf("	delta dist:\nx: %f	y: %f\n", rc->delta_dist->x, rc->delta_dist->y);
}
