/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 09:24:48 by jsubel            #+#    #+#             */
/*   Updated: 2022/06/13 10:54:46 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/cub3d.h"

int	main(int argc, char **argv)
{
	void	*mlx;

	if (argc != 2)
		ft_end_process();
	mlx = mlx_init();
	ft_init(mlx);
	mlx_loop(mlx);
}

void	ft_init(void *mlx)
{
	t_window	*window;

	window = (t_window *)ft_calloc(1, sizeof(t_window));
	window->mlx = mlx;
	window->mlx = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	if (!fractal->win)
		ft_end_process(ERR_WINDOW_INIT);
	window->img = ft_init_image(mlx);
	window->player->x = 30;
	window->player->y = 30;

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
	image->addr = mlx_get_data_addr(
			image->img,
			&(image->bpp),
			&(image->line_len),
			&(image->endian));
	return (image);
}

void	ft_end_process(char *s)
{
	perror(s);
	exit(1);
}