#include "incl/cub3d.h"

int	main(int argc, char **argv)
{
	t_window	*window;
	void		*mlx;

	window = (t_window *)ft_calloc(1, sizeof(t_window));
	if (!window)
		ft_end_process(ERR_MLX_INIT);
	if (argc != 2)
		ft_end_process("Invalid input");
	mlx = mlx_init();
	window->mlx = mlx;
	ft_init(window);
	mlx_loop_hook(window->mlx, ft_render_next_frame, window);
	mlx_hook(window->win, 17, 0, ft_close, window);
	mlx_hook(window->win, 2, 1L << 0, ft_key_press, window);
	printf("%s\n", argv[0]);
	mlx_loop(window->mlx);
	return (0);
}

void	ft_init(t_window *window)
{
	window->win = mlx_new_window(window->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	if (!window->win)
		ft_end_process(ERR_WINDOW_INIT);
	window->img = ft_init_image(window->mlx);
	window->player = ft_calloc(1, sizeof(t_player));
	window->player->x = 30;
	window->player->y = 30;
	window->player->size = 5;
}

t_image *ft_init_image(void *mlx)
{
	t_image	*image;

	image = (t_image *)ft_calloc(1, sizeof(t_image));
	if (!image)
		ft_end_process(ERR_IMAGE_INIT);
	image->img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!image->img)
		ft_end_process(ERR_IMAGE_INIT);
	image->addr = mlx_get_data_addr(image->img, &(image->bpp), &(image->line_len), &(image->endian));
	return (image);
}

int	ft_close(t_window *window)
{
	if (window->img->img != NULL)
	{
		mlx_destroy_image(window->mlx, window->img->img);
	}
	if (window->win != NULL)
	{
		mlx_destroy_window(window->mlx, window->win);
	}
	exit(0);
}

int	ft_key_press(int keycode, t_window *window)
{
	if (keycode == KEY_ESCAPE)
		ft_close(window);
	else if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT
		|| keycode == ARROW_UP || keycode == ARROW_DOWN)
		ft_move(keycode, window);
	else
		printf(":c I don't know that key, sorry. :c\n");
	return (0);
}

int	ft_render_next_frame(t_window *window)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			ft_pixel_put_img(window->img, x, y, 0x00000000);
			x++;
		}
		y++;
	}
	ft_draw_player(window);
	mlx_put_image_to_window(window->mlx, window->win, window->img->img, 0, 0);
	return (0);
}

void	ft_pixel_put_img(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	ft_move(int keycode, t_window *window)
{
	if (keycode == ARROW_LEFT)
		window->player->x -= 8;
	else if (keycode == ARROW_RIGHT)
		window->player->x += 8;
	else if (keycode == ARROW_UP)
		window->player->y -= 8;
	else if (keycode == ARROW_DOWN)
		window->player->y += 8;
}

void	ft_draw_player(t_window *window)
{
	int	counter_x;
	int	counter_y;

	counter_y = 0;
	while (counter_y < window->player->size)
	{
		counter_x = 0;
		while (counter_x < window->player->size)
		{
			ft_pixel_put_img(window->img,
				window->player->x + counter_x,
				window->player->y + counter_y, 0x00FF0000);
			counter_x++;
		}
		counter_y++;
	}
}