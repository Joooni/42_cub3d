#include "../incl/cub3d.h"

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
