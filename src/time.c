#include "../incl/cub3d.h"

// returns the current time since Epoch in milliseconds
long long	get_time(void)
{
	struct timeval	tp;
	long long		time;

	gettimeofday(&tp, NULL);
	time = (tp.tv_sec * 1000) + (tp.tv_usec / 1000);
	return (time);
}

// Returns the time since program start in milliseconds
long long curr_time(t_window *window)
{
	return ((get_time() - window->start_time));
}

// print FPS in the top right corner
void	render_time(t_window *window)
{
	char		*temp;
	u_int64_t	time;
	double		frametime;

	time = get_time() - window->start_time;
	// printf("%llu.%llus\n", time / 1000, time % 1000);
	frametime = (time - window->old_time) / 1000.0;
	temp = ft_itoa((int)(1 / frametime));
	//printf("FPS: %d\n", (int)(1.0 / frametime));
	window->old_time = time;
	// printf("oldtime: %f\n", window->old_time / 1000);
	mlx_string_put(window->mlx, window->win, WINDOW_WIDTH - 50, 25, 0x444444, temp);
	mlx_string_put(window->mlx, window->win, WINDOW_WIDTH - 35, 25, 0x444444, "FPS");
	free(temp);
}
