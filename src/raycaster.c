#include "../incl/cub3d.h"

/* void	ft_cast_ray(t_window *window)
{
	while (window->player->)
}

void	ft_ray_distance(t_window *window)
{
	int	WallHit;
	int	WallSide;

	WallHit = 0;
	window->player->MapPos->x = (int)window->player->pos->x / 32;
	window->player->MapPos->y = (int)window->player->pos->y / 32;
	window->player->ray->DeltaDist->x = ft_abs(1 / window->player->ray->dir->x);
	window->player->ray->DeltaDist->y = ft_abs(1 / window->player->ray->dir->y);
}

void	ft_step_direction(t_player *player)
{
	if (player->ray->dir->x < 0)
	{
		player->step->x = -1;
		player->ray->SideDist->x = (player->pos->x - player->MapPos->x) * player->ray->DeltaDist->x;
	}
	else
	{
		player->step->x = 1;
		player->ray->SideDist->x = (player->MapPos->x + 1.0 - player->pos->x) * player->ray->DeltaDist->x;
	}
	if (player->ray->dir->y < 0)
	{
		player->step->y = -1;
		player->ray->SideDist->y = (player->pos->y - player->MapPos->y) * player->ray->DeltaDist->y;
	}
	else
	{
		player->step->y = 1;
		player->ray->SideDist->y = (player->MapPos->y + 1.0 - player->pos->y) * player->ray->DeltaDist->y;
	}
} */