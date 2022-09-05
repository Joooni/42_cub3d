/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:08:09 by jtomala           #+#    #+#             */
/*   Updated: 2022/09/05 13:59:08 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

static void	ft_get_tex_address(t_window *window);

static t_color	*ft_set_color(t_textures *tex, int x, int y)
{
	int	*pos;

	pos = (int *)(tex->addr + (y * tex->line_len + \
		x * (tex->bpp / 8)));
	return ((t_color *)pos);
}

static t_color	***create_matrix(t_textures *tex, int height, int width)
{
	int	i;
	int	j;

	tex->matrix = ft_calloc(height, sizeof(t_color **));
	j = 0;
	while (j < height)
	{
		tex->matrix[j] = ft_calloc(width, sizeof(t_color *));
		i = 0;
		while (i < width)
		{
			tex->matrix[j][i] = ft_set_color(tex, i, j);
			i++;
		}
		j++;
	}
	tex->height = j;
	return (tex->matrix);
}

void	textures_handler(t_window *window)
{
	int		width;
	int		height;

	width = M_TEXTURE_WIDTH;
	height = M_TEXTURE_HEIGHT;
	ft_load_textures(window);
	window->map->no_tex->matrix
		= create_matrix(window->map->no_tex, height, width);
	window->map->so_tex->matrix
		= create_matrix(window->map->so_tex, height, width);
	window->map->we_tex->matrix
		= create_matrix(window->map->we_tex, height, width);
	window->map->ea_tex->matrix
		= create_matrix(window->map->ea_tex, height, width);
	window->map->wall_c_tex->matrix
		= create_matrix(window->map->wall_c_tex, height, width);
}

void	ft_load_textures(t_window *window)
{
	t_map	*map;
	int		width;
	int		height;

	map = window->map;
	width = M_TEXTURE_WIDTH;
	height = M_TEXTURE_HEIGHT;
	map->no_tex->img = mlx_xpm_file_to_image(window->mlx, map->no_path, \
		&width, &height);
	map->so_tex->img = mlx_xpm_file_to_image(window->mlx, map->so_path, \
		&width, &height);
	map->we_tex->img = mlx_xpm_file_to_image(window->mlx, map->we_path, \
		&width, &height);
	map->ea_tex->img = mlx_xpm_file_to_image(window->mlx, map->ea_path, \
		&width, &height);
	if (map->do_path)
		map->wall_c_tex->img = mlx_xpm_file_to_image(window->mlx, map->do_path, \
			&width, &height);
	else
		map->wall_c_tex->img = mlx_xpm_file_to_image(window->mlx, \
			"textures/door.xpm", &width, &height);
	if (!map->no_tex->img || !map->so_tex->img
		|| !map->we_tex->img || !map->ea_tex->img || !map->wall_c_tex->img)
		ft_end_process(ERR_INV_TEX);
	ft_get_tex_address(window);
}

static void	ft_get_tex_address(t_window *window)
{
	t_map	*map;

	map = window->map;
	map->no_tex->addr = mlx_get_data_addr(map->no_tex->img, \
		&(map->no_tex->bpp), &(map->no_tex->line_len), &(map->no_tex->endian));
	map->so_tex->addr = mlx_get_data_addr(map->so_tex->img, \
		&(map->so_tex->bpp), &(map->so_tex->line_len), &(map->so_tex->endian));
	map->we_tex->addr = mlx_get_data_addr(map->we_tex->img, \
		&(map->we_tex->bpp), &(map->we_tex->line_len), &(map->we_tex->endian));
	map->ea_tex->addr = mlx_get_data_addr(map->ea_tex->img, \
		&(map->ea_tex->bpp), &(map->ea_tex->line_len), &(map->ea_tex->endian));
	map->wall_c_tex->addr = mlx_get_data_addr(map->wall_c_tex->img, \
		&(map->wall_c_tex->bpp), &(map->wall_c_tex->line_len), \
		&(map->wall_c_tex->endian));
	if (!map->no_tex->addr || !map->so_tex->addr
		|| !map->we_tex->addr || !map->ea_tex->addr || !map->wall_c_tex->addr)
		ft_end_process(ERR_INV_TEX_ADDR);
}
