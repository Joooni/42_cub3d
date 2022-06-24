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
	if (set_path(window, path))
		ft_end_process(ERR_INV_PATH);
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

void	ft_init_player(t_window *window)
{
	window->player = (t_player *)ft_calloc(1, sizeof(t_player));
	window->player->key = (t_key *)ft_calloc(1, sizeof(t_key));
	window->player->pos = ft_init_vector(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	window->player->dir = ft_init_vector(M_INIT_VECTOR_X, M_INIT_VECTOR_Y);
	window->player->size = 10;
	window->player->color = 0x0058BD55;
	window->player->key->w = 0;
	window->player->key->a = 0;
	window->player->key->s = 0;
	window->player->key->d = 0;
	window->player->key->a_l = 0;
	window->player->key->a_r = 0;
	window->player->key->a_u = 0;
	window->player->key->a_d = 0;
	window->player->plane.x = 0;
	window->player->plane.y = 2;
}

t_vec	*ft_init_vector(double x, double y)
{
	t_vec	*vec;

	vec = ft_calloc(1, sizeof(t_vec));
	vec->x = x;
	vec->y = y;
	return (vec);
}

t_rc	*ft_init_ray(void)
{
	t_rc	*ray;

	ray = (t_rc *)ft_calloc(1, sizeof(t_rc));
	ray->dir = (t_vec *)ft_calloc(1, sizeof(t_vec));
	ray->side_dist = (t_vec *)ft_calloc(1, sizeof(t_vec));
	ray->map_pos = (t_vec_i *)ft_calloc(1, sizeof(t_vec_i));
	ray->delta_dist = ft_calloc(1, sizeof(t_vec));
	return (ray);
}
