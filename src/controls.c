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
	int	mv_dist;

	mv_dist = 8;
	if (keycode == ARROW_LEFT && window->player->pos->x > mv_dist)
		window->player->pos->x -= 8;
	else if (keycode == ARROW_RIGHT && WINDOW_WIDTH > window->player->pos->x + mv_dist)
		window->player->pos->x += 8;
	else if (keycode == ARROW_UP && window->player->pos->y > mv_dist)
		window->player->pos->y -= 8;
	else if (keycode == ARROW_DOWN && WINDOW_HEIGHT > window->player->pos->y + mv_dist)
		window->player->pos->y += 8;
}
