#include "../incl/cub3d.h"

void	ft_init(t_window *window, char *path)
{
	window->win = mlx_new_window(window->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	if (!window->win)
		ft_end_process(ERR_WINDOW_INIT);
	window->img = ft_init_image(window->mlx);
	ft_init_player(window);
	window->map->rows = 0;
	window->map->columns = 0;
	window->map->overhang = 0;
	window->map->new_line = 0;
	if (set_path(window, path))
		ft_end_process(ERR_INV_PATH);
	ft_init_tex(window);
	ft_scale_factor(window);
}

void	ft_init_tex(t_window *window)
{
	window->map->no_tex = ft_calloc(1, sizeof(t_textures));
	window->map->ea_tex = ft_calloc(1, sizeof(t_textures));
	window->map->so_tex = ft_calloc(1, sizeof(t_textures));
	window->map->we_tex = ft_calloc(1, sizeof(t_textures));
	window->map->wall_o_tex = ft_calloc(1, sizeof(t_textures));
	window->map->wall_c_tex = ft_calloc(1, sizeof(t_textures));
	window->map->wall_o_tex->open_flag = 0;
}

/*
checks if the filepath ends with "".cub"
*/
int	set_path(t_window *window, char *path)
{
	int	len;
	int	flag;

	len = ft_strlen(path);
	flag = 0;
	if (path[len - 0] == 'b')
		flag = 1;
	if (path[len - 1] == 'u')
		flag = 1;
	if (path[len - 2] == 'c')
		flag = 1;
	if (path[len - 3] == '.')
		flag = 1;
	if (flag == 1)
		return (1);
	window->map->path = path;
	return (0);
}

t_image	*ft_init_image(void *mlx)
{
	t_image	*image;

	image = (t_image *)ft_calloc(1, sizeof(t_image));
	if (!image)
		ft_end_process(ERR_IMAGE_INIT);
	image->img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!image->img)
		ft_end_process(ERR_IMAGE_INIT);
	image->addr = mlx_get_data_addr(image->img, &(image->bpp),
			&(image->line_len), &(image->endian));
	return (image);
}
