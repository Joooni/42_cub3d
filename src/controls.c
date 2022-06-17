#include "../incl/cub3d.h"

int	ft_key_press(int keycode, t_window *window)
{
	if (keycode == KEY_ESCAPE)
		ft_close(window);
	else if (keycode == ARROW_UP || keycode == ARROW_DOWN
		|| keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D )
		ft_move(keycode, window);
	else if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT)
		ft_turn(keycode, window);
	else
		printf(":c I don't know that key, sorry. :c\n");
	return (0);
}



void	ft_move(int keycode, t_window *window)
{
	int	mv_dist;

	mv_dist = 8;
	if (keycode == KEY_A && window->player->pos->x > mv_dist)
		window->player->pos->x -= 8;
	else if (keycode == KEY_D && WINDOW_WIDTH > window->player->pos->x + mv_dist)
		window->player->pos->x += 8;
	else if ((keycode == ARROW_UP || keycode == KEY_W) && window->player->pos->y >
		mv_dist)
		window->player->pos->y -= 8;
	else if ((keycode == ARROW_DOWN || keycode == KEY_S) && WINDOW_HEIGHT >
		window->player->pos->y + mv_dist)
		window->player->pos->y += 8;
}

void	ft_turn(int keycode, t_window *window)
{
	float radian;

	radian = M_DEGREE_TURN * 180 / M_PI;
	printf("sin: %f cos: %f\n", sin(radian), cos(radian));
	if (keycode == ARROW_LEFT)
	{
		window->player->dir->x = window->player->dir->x * cos(radian) - window->player->dir->y * sin(radian);
		window->player->dir->y = window->player->dir->x * sin(radian) + window->player->dir->y * cos(radian);
	}
	else
	{
		window->player->dir->x = window->player->dir->x * cos(radian) + window->player->dir->y * sin(radian);
		window->player->dir->y = window->player->dir->x * sin(radian) * -1 + window->player->dir->y * cos(radian);
	}
}