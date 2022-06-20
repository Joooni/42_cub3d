#include "../incl/cub3d.h"

int	ft_key_press(int keycode, t_window *window)
{
	if (keycode == KEY_ESCAPE)
		ft_close(window);
<<<<<<< HEAD
	else if (keycode == ARROW_UP || keycode == ARROW_DOWN
=======
	else if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT
		|| keycode == ARROW_UP || keycode == ARROW_DOWN
>>>>>>> 23efd1e6258c5f5d403daff58f2905e49ca74534
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
	double	old_dir_x;

	old_dir_x = window->player->dir->x;
	if (keycode == ARROW_RIGHT)
	{
		window->player->dir->x = old_dir_x * cos(M_DEGREE_TURN) - window->player->dir->y * sin(M_DEGREE_TURN);
		window->player->dir->y = old_dir_x * sin(M_DEGREE_TURN) + window->player->dir->y * cos(M_DEGREE_TURN);
	}
	else
	{
		window->player->dir->x = old_dir_x * cos(M_DEGREE_TURN) + window->player->dir->y * sin(M_DEGREE_TURN);
		window->player->dir->y = old_dir_x * sin(M_DEGREE_TURN) * -1 + window->player->dir->y * cos(M_DEGREE_TURN);
	}
}