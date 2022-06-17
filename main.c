#include "incl/cub3d.h"

/*
checks if the filepath ends with "".cub"
*/
int set_path(t_window *window, char *path)
{
	int len;
	int flag;

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

int	main(int argc, char **argv)
{
	t_window	*window;
	void		*mlx;

	window = (t_window *)ft_calloc(1, sizeof(t_window));
	window->map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!window || !window->map)
		ft_end_process(ERR_MLX_INIT);
	if (argc != 2)
		ft_end_process("Invalid input");
	mlx = mlx_init();
	window->mlx = mlx;
	ft_init(window, argv[1]);
	mlx_loop_hook(window->mlx, ft_render_next_frame, window);
	mlx_hook(window->win, 17, 0, ft_close, window);
	mlx_hook(window->win, 2, 1L << 0, ft_key_press, window);
	if (map_handler(window))
		ft_end_process("Invalid map-read");
	printf("%s\n", argv[0]); //testing
	mlx_loop(window->mlx);
	return (0);
}
