#include "incl/cub3d.h"

/*
small testfunction to see what got red
*/
void print_read(t_window *window)
{
	int i = 0;
	while (i < window->map->rows)
	{
		printf("line[%d] %s", i, window->map->map[i]);
		i++;
	}
	printf("F: %d,%d,%d C: %d,%d,%d\n rows: %d\ncolumns: %d\ndirection: %c\n", window->map->f->red, window->map->f->green, window->map->f->blue, window->map->c->red, window->map->c->green, window->map->c->blue, window->map->rows, window->map->columns, window->map->direction);
	printf("Player x: %d y: %d\n", (int)window->player->pos->x, (int)window->player->pos->y);

	// printf("-------\nTEST\n---------\nmap[6][31]: %c\n------------\n", window->map->map[6][31]);
	// if (window->map->map[6][31] != '1')
	// 	printf("true\n");
	// else
	// 	printf("false\n");
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
		ft_end_process(ERR_INV_INPUT);
	mlx = mlx_init();
	window->mlx = mlx;
	ft_init(window, argv[1]);
	if (map_handler(window))
		ft_end_process(ERR_INV_MAP);
	textures_handler(window);
	mlx_loop_hook(window->mlx, ft_render_next_frame, window);
	mlx_hook(window->win, 17, 0, ft_close, window);
	mlx_hook(window->win, 2, 1L << 0, ft_key_press, window);
	mlx_hook(window->win, 3, 1L << 1, ft_key_release, window);
	//print_read(window);
	printf("%s\n", argv[0]); //testing
	mlx_loop(window->mlx);
	return (0);
}
