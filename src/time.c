#include "../incl/cub3d.h"

long long	get_time(void)
{
	struct timeval	tp;
	long long		time;

	gettimeofday(&tp, NULL);
	time = (tp.tv_sec * 1000) + (tp.tv_usec / 1000);
	return (time);
}

void	render_time(t_window *window)
{
	char		*temp;
	u_int64_t	time;
	double		frametime;

	temp = ft_calloc(1, sizeof(char *));
	time = get_time() - window->start_time;
	// printf("%llu.%llus\n", time / 1000, time % 1000);
	frametime = (time - window->old_time) / 1000.0;
	temp = ft_itoa(1 / frametime);
	//printf("FPS: %d\n", (int)(1.0 / frametime));
	window->old_time = time;
	// printf("oldtime: %f\n", window->old_time / 1000);
	mlx_string_put(window->mlx, window->win, WINDOW_WIDTH - 25, 25, 0x444444, temp);
	free(temp);

}
