#include "../incl/cub3d.h"

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
	printf("addr: %s\n", map->no_tex->addr);
}
