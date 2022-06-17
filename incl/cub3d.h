#ifndef CUB3D_H

# define CUB3D_H

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define M_DEGREE_TURN 5

# include <stdlib.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# include <math.h>
# include "../libft/libft.h"
# include <stdint.h>
# include "error.h"
# include "keys.h"

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

typedef struct s_vec {
	double	x;
	double	y;
}	t_vec;

typedef struct s_color
{
	int8_t			channel[4];
}	t_color;

typedef struct s_rect{
	int	x;
	int	y;
	int	size_x;
	int	size_y;
	int	color;
}	t_rect;

typedef struct s_rc
{
	t_vec	dir;
	t_vec	SideDist;
	t_vec	DeltaDist;
}	t_rc;

typedef struct s_player
{
	t_vec	MapPos;
	t_vec	*pos;
	t_vec	*dir;
	t_vec	plane;
	t_vec	camera;
	t_vec	step;
	t_rc	ray;
	int		size;
	int		color;
}	t_player;

typedef struct s_window
{
	void		*mlx;
	void		*win;
	t_image		*img;
	t_player	*player;
}	t_window;

// init.c

void	ft_init(t_window *window);
t_image	*ft_init_image(void *mlx);
void	ft_init_player(t_window *window);
t_vec	*ft_init_vector (double x, double y);

// controls.c

int		ft_key_press(int keycode, t_window *window);
void	ft_move(int keycode, t_window *window);
void	ft_turn(int keycode, t_window *window);

// draw_minimap.c

void	ft_draw_grid(t_window *window);
void	ft_draw_player(t_window *window);
void	ft_grid_highlight(t_window *window);

// draw_utils.c

void	ft_pixel_put_img(t_image *img, int x, int y, int color);
int		ft_render_next_frame(t_window *window);
void	ft_draw_rect(t_window *window, t_rect rect);
void	ft_draw_vector(t_window *window, t_vec vector);

// utils.c

int	ft_close(t_window *window);

// raycaster.c

void	ft_cast_ray(t_window *window);
void	ft_ray_distance(t_window *window);
void	ft_step_direction(t_player *player);

#endif