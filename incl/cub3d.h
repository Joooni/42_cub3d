/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtomala <jtomala@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:06:26 by jtomala           #+#    #+#             */
/*   Updated: 2022/09/05 13:21:37 by jtomala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# define WINDOW_WIDTH		1281
# define WINDOW_HEIGHT		1080
# define M_DEGREE_TURN		0.05
# define M_FOV				0.66
# define M_BASE_SPEED		2
# define M_SPRINT_SPEED		3
# define M_TEXTURE_WIDTH	64
# define M_TEXTURE_HEIGHT	64
# define M_TURN_FACTOR		15
# define MINIMAP_FACTOR		0.3
# define PLAYER_POS			"WESN"
# define VALID_SYMBOLS		"0123NESW"
# define MAP_EMPTY_SPACE	'0'
# define MAP_WALL			'1'
# define MAP_DOOR_CLOSED	'2'
# define MAP_DOOR_OPEN		'3'

# include <stdlib.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# include <math.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <stdint.h>
# include <math.h>
# include "error.h"
# include "keys.h"
#include <sys/time.h>

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

typedef struct s_vec_i {
	int	x;
	int	y;
}	t_vec_i;


typedef struct s_vec {
	double	x;
	double	y;
}	t_vec;

typedef struct s_rect{
	int	x;
	int	y;
	int	size_x;
	int	size_y;
	int	color;
}	t_rect;

typedef struct s_rc
{
	t_vec_i	*pixel;
	t_vec	*dir;
	t_vec	*side_dist;
	t_vec	*delta_dist;
	t_vec_i	step;
	t_vec_i	*map_pos;
	int		hit;
	int		side;
	double	wall_dist_perp;
	double	line_height;
	double	draw_start;
	double	draw_end;
	int		color;
	double	wall_hit_x;
	t_vec_i	tex;
	double	tex_pos;
	double	step_tex;
	int		door_flag;
	t_vec_i	door_pos;
}	t_rc;

typedef struct s_key
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		a_l;
	int		a_r;
	int		a_u;
	int		a_d;
	int		spacebar;
	int		e;
	int		m;
}	t_key;

typedef struct s_player
{
	t_vec_i	map_pos;
	t_vec	*pos;
	t_vec	*dir;
	t_vec	plane;
	t_vec	camera;
	t_vec	step;
	t_rc	*ray;
	t_key 	*key;
	int		size;
	int		color;
	int		mouse_x;
	int		mouse_hide;
	int		speed;
}	t_player;

typedef struct s_color
{
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;
	unsigned char	t;
}	t_color;

typedef struct s_textures
{
	void *img;
	char *addr;
	int	bpp;
	int line_len;
	int height;
	int endian;
	t_color ***matrix;
	int open_flag;
}	t_textures;

typedef struct s_map
{
	char **map;
	char *path;
	int rows;
	int columns;
	char direction;
	int overhang;
	int new_line;
	t_vec_i	index_dir;
	char *no_path;
	char *so_path;
	char *we_path;
	char *ea_path;
	char *do_path;
	char *f_tex;
	char *c_tex;
	t_color *f;
	t_color *c;
	t_textures *no_tex;
	t_textures *so_tex;
	t_textures *we_tex;
	t_textures *ea_tex;
	t_textures *wall_o_tex;
	t_textures *wall_c_tex;
}	t_map;

typedef struct s_check
{
	int end_pos_flag;
	int start_x;
	int start_y;
}	t_check;

typedef struct s_window
{
	void		*mlx;
	void		*win;
	t_image		*img;
	t_player	*player;
	t_map		*map;
	t_check		*check;
	double		scale_factor;
	double		start_time;
	double		old_time;
	double		time_stamp;
}	t_window;



//time.c
long long	get_time(void);
long long 	curr_time(t_window *window);
void		render_time(t_window *window);

// init.c

void	ft_init(t_window *window, char *path);
int 	set_path(t_window *window, char *path);
t_image	*ft_init_image(void *mlx);
void	ft_init_player(t_window *window);
t_vec	*ft_init_vector (double x, double y);
t_rc	*ft_init_ray(void);
void	ft_init_tex(t_window *window);
void	ft_init_player_dir(t_player *player, char dir);

// free.c

void	ft_free_ray(t_rc *ray);
void	ft_free_player(t_window *window);
void	ft_free_tex(t_window *window);
void	ft_free_matrix(t_color ***matrix);
void	ft_free_map(t_window *window);
// controls.c

int		ft_key_press(int keycode, t_window *window);
int		ft_key_release(int keycode, t_window *window);
void	ft_move(t_window *window);
void	ft_turn_right(t_window *window, int diff_x);
void	ft_turn_left(t_window *window, int diff_x);

// void	ft_turn(int keycode, t_window *window);

//	controls_move.c

void	ft_move_up(t_window *window);
void	ft_move_left(t_window *window);
void	ft_move_right(t_window *window);
void	ft_move_down(t_window *window);
void	ft_mouse_tracker(t_window *window);

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

int		ft_close(t_window *window);
int		ft_tcolor_to_int(t_color color);


// raycaster.c

void	ft_cast_ray(t_window *window);
void	ft_init_rc(t_window *window, t_rc *rc);
void	ft_calc_step(t_window *window, t_rc *rc);
void	ft_calc_hit(t_map map, t_rc *ray);
void	ft_calc_distance(t_rc *ray);
void	ft_draw_to_wall(t_rc *ray);

//map_helper.c

void	map_handler(t_window *window);
int		count_map(t_window *window, char *line);
int		safe_preoptions(t_map *map, char *line, int counter);
int 	safe_map(t_window *window, int rows);

// check_map.c

int		check_map(t_window *window);

//check_map_utils.c

int		init_colors(t_window *window);

//draw_map.c

void	draw_map(t_window *window);
// void	ft_scale_factor(t_window *window);
//	3drawing.c
void	drawing_handler(t_window *window, t_rc *ray, int x);
void	ft_calc_tex_x(t_window *window, t_rc *ray);
void	ft_draw_floor_ceiling(t_window *window, t_rc *ray, int x);

//	textures.c
void	textures_handler(t_window *window);
void	ft_load_textures(t_window *window);

// ft_split_cub3d.c
char	**ft_split_cub3d(const char *s, char c);

// ft_isvalidchar.c
int		ft_isvalidchar(t_window *window, int pos_x, int pos_y);
int		new_line_check(t_window *window, char *line);

//check_map2.c
int		square_exists(t_window *window, int i, int j);
int		square_below_exists(t_window *window, int i, int j);
int		square_above_exists(t_window *window, int i, int j);
int		square_left_exists(t_window *window, int i, int j);
int		square_right_exists(t_window *window, int i, int j);

//movement.c
void	ft_key_press2(int keycode, t_window *window);
void	ft_key_release2(int keycode, t_window *window);

#endif