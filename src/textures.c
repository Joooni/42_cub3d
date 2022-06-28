#include "../incl/cub3d.h"

static t_color *ft_set_color(t_textures *tex, int x, int y)
{
	int *pos;

	pos = (int *)(tex->addr + (y * tex->line_len + \
		x * (tex->bpp / 8)));
	return ((t_color *)pos);
}

static t_color*** create_matrix(t_textures *tex, int heidth, int width)
{
	int i;
	int j;

	tex->matrix = ft_calloc(heidth, sizeof(t_color **));
	j = 0;
	while (j < heidth)
	{
		tex->matrix[j] = ft_calloc(width, sizeof(t_color *));
		i = 0;
		while (i < width)
		{
			tex->matrix[j][i] = ft_set_color(tex, i, j);
			printf("matrix: %d\n", (int)tex->matrix[j][i]);
			printf("b: %d\nr: %d\ng: %d\nt: %d\n", tex->matrix[j][i]->blue, tex->matrix[j][i]->red, tex->matrix[j][i]->green, tex->matrix[j][i]->t);
			i++;
		}
		j++;
	}
	tex->height = j;
	return (tex->matrix);
}

void	textures_handler(t_window *window)
{
	t_map	*map;
	int		width;
	int		height;

	map = window->map;
	map->no_tex->img = mlx_xpm_file_to_image(window->mlx, map->no_path, \
		&width, &height);
	if (!map->no_tex->img)
		ft_end_process("Invalid textures!");
	map->no_tex->addr = mlx_get_data_addr(map->no_tex->img, \
		&(map->no_tex->bpp), &(map->no_tex->line_len), &(map->no_tex->endian));
	window->map->no_tex->matrix = create_matrix(window->map->no_tex, height, width);
}
