#include "../incl/cub3d.h"

void	ft_free_player(t_window *window)
{
	free(window->player->key);
	free(window->player->pos);
	free(window->player->dir);
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
}

void	ft_free_matrix(t_color ***matrix)
{
	int	i;

	i = -1;
	while (++i < M_TEXTURE_HEIGHT)
		free(matrix[i]);
	free(matrix);
}
