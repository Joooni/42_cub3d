#include "../incl/cub3d.h"

void	drawing_handler(t_window *window, t_rc *ray, int x)
{
	//printf("line_height: %d\n", line_height);
	//printf("start: %d\nend: %d\n", draw_start, draw_end);
	//printf("side: %d\n", ray->side);
	//north and south
	//remove this when the textures work
/* 	if (ray->side == 1)
	{
		ray->color = 0xd19041;
		if (ray->dir->y < 0)
			ray->color = 0xa85032;
	}
	else
	{
		ray->color = 0xeb9834;
		if (ray->dir->x < 0)
			ray->color = 0xd94d1e;
	} */
	ft_calc_tex_x(window, ray);
	// scaling of texture coordinates to necessary wall size
	ray->step_tex = 1.0 * M_TEXTURE_HEIGHT / ray->line_height;
	ray->tex_pos = (ray->draw_start - WINDOW_HEIGHT / 2
		+ ray->line_height / 2) * ray->step_tex;
	// actual drawing loop
	while (ray->draw_start <= ray->draw_end)
	{
		ray->tex.y = (int)ray->tex_pos & (M_TEXTURE_HEIGHT - 1);
		ray->tex_pos += ray->step_tex;
		ray->color = ft_tcolor_to_int(*(window->map->no_tex->matrix[ray->tex.y][ray->tex.x]));
		if (ray->side == 1 && ray->dir->y < 0)
			ray->color = ft_tcolor_to_int(*(window->map->no_tex->matrix[ray->tex.y][ray->tex.x]));
		else if (ray->side == 1 && ray->dir->y > 0)
			ray->color = ft_tcolor_to_int(*(window->map->so_tex->matrix[ray->tex.y][ray->tex.x]));
		else if (ray->side == 0 && ray->dir->x > 0)
			ray->color = ft_tcolor_to_int(*(window->map->ea_tex->matrix[ray->tex.y][ray->tex.x]));
		else
			ray->color = ft_tcolor_to_int(*(window->map->we_tex->matrix[ray->tex.y][ray->tex.x]));
		ft_pixel_put_img(window->img, x, ray->draw_start, ray->color);
		ray->draw_start++;
	}
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
		ray->wall_hit_x = window->player->pos->y + ray->wall_dist_perp * ray->dir->y;
	else
		ray->wall_hit_x = window->player->pos->x + ray->wall_dist_perp * ray->dir->x;
	// find corresponding x-coordinate of texture
	ray->tex.x = (int)ray->wall_hit_x % (int)M_TEXTURE_WIDTH;
	if (ray->side == 0 && ray->dir->x > 0)
		ray->tex.x = M_TEXTURE_WIDTH - ray->tex.x - 1;
	if (ray->side == 1 && ray->dir->y < 0)
		ray->tex.x = M_TEXTURE_WIDTH - ray->tex.x - 1;
	
}