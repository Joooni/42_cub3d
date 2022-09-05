/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:08:29 by jtomala           #+#    #+#             */
/*   Updated: 2022/09/05 13:08:44 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/cub3d.h"

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
	mlx_mouse_move(window->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	map_handler(window);
	ft_init_player_dir(window->player, window->map->direction);
	textures_handler(window);
	mlx_loop_hook(window->mlx, ft_render_next_frame, window);
	mlx_hook(window->win, 17, 0, ft_close, window);
	mlx_hook(window->win, 2, 1L << 0, ft_key_press, window);
	mlx_hook(window->win, 3, 1L << 1, ft_key_release, window);
	mlx_loop(window->mlx);
	return (0);
}
