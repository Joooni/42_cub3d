/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsubel <jsubel@student.42wolfsburg.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 09:30:22 by jsubel            #+#    #+#             */
/*   Updated: 2022/06/13 09:55:06 by jsubel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"
# include <stdint.h>
# include "error.h"

/**
* @brief minilibx image structure
*
* @param img: image identifier
* @param addr: address of image
* @param bpp: bits per pixel
* @param line_len: number of byters to store one line of image
* @param endian: little or big
*/
typedef struct s_image {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_color
{
	int8_t			channel[4];
}	t_color;

typedef struct s_player
{
	double	x;
	double	y;
}	t_player;

typedef struct s_window
{
	void		*mlx;
	void		*win;
	t_image		*img;
	t_player	*player;
}	t_window;

#endif