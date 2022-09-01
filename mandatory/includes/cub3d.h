/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelgharo <yelgharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 04:33:19 by yelgharo          #+#    #+#             */
/*   Updated: 2022/09/02 00:41:58 by yelgharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx_opengl_20191021/mlx.h"

# define BUFFER_SIZE 1
# define X_AXIS 1800
# define Y_AXIS 800
# define PI 3.1415926535
# define T_W 64
# define COS_A 193.2
# define SIN_A 16.93
# define T_H 64
# define SPEED 0.06
# define ROTATE_SPEED 0.06
# define IMG_1 "mandatory/walls_floor/colorstone.xpm"
# define IMG_2 "mandatory/walls_floor/eagle.xpm"
# define IMG_3 "mandatory/walls_floor/purplestone.xpm"
# define IMG_4 "mandatory/walls_floor/redbrick.xpm"
# define IMG_5 "mandatory/walls_floor/door.xpm"
# define IMG_6 "mandatory/walls_floor/door_open.xpm"
# define IMG_7 "mandatory/walls_floor/pillar.xpm"
# define IMG_8 "mandatory/walls_floor/asalek.xpm"

# define S_IMG_1 "mandatory/spirit/fire1.xpm"
# define S_IMG_2 "mandatory/spirit/fire2.xpm"
# define S_IMG_3 "mandatory/spirit/fire3.xpm"
# define S_IMG_4 "mandatory/spirit/fire4.xpm"
# define S_IMG_5 "mandatory/spirit/fire5.xpm"
# define S_IMG_6 "mandatory/spirit/fire6.xpm"
# define S_IMG_7 "mandatory/spirit/fire7.xpm"
# define S_IMG_8 "mandatory/spirit/fire8.xpm"
# define S_IMG_9 "mandatory/spirit/fire9.xpm"
# define S_IMG_10 "mandatory/spirit/fire10.xpm"
# define S_IMG_11 "mandatory/spirit/fire11.xpm"
# define S_IMG_12 "mandatory/spirit/fire12.xpm"
# define S_IMG_13 "mandatory/spirit/fire13.xpm"
# define S_IMG_14 "mandatory/spirit/fire14.xpm"
# define S_IMG_15 "mandatory/spirit/fire15.xpm"
# define S_IMG_16 "mandatory/spirit/fire16.xpm"
# define S_IMG_17 "mandatory/spirit/fire17.xpm"
# define S_IMG_18 "mandatory/spirit/fire18.xpm"

# define GUN_IMG_1 "mandatory/spirit/1.xpm"
# define GUN_IMG_2 "mandatory/spirit/2.xpm"
# define GUN_IMG_3 "mandatory/spirit/6.xpm"
# define GUN_IMG_4 "mandatory/spirit/4.xpm"
# define GUN_IMG_5 "mandatory/spirit/5.xpm"
# define GUN_IMG_6 "mandatory/spirit/2.xpm"

typedef struct s_color {
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_map {
	char	**tab;
	char	**map;
	int		line;
	int		colomn;
	int		ln;
	char	*north;
	char	*west;
	char	*east;
	char	*south;
	int		w;
	int		s;
	int		e;
	int		n;
	int		*position;
	t_color	f;
	t_color	c;
}	t_map;

typedef struct s_images
{
	void	*img;
	char	*addr;
	int		bpp;
	int		sl;
	int		en;
}	t_img;

typedef struct s_ray
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			raydirx;
	double			raydiry;
	double			camera;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	int				hit;
	double			perpwalldist;
	int				side;
	int				line_height;
	int				drawstart;
	int				drawend;
	unsigned int	**tab;
	unsigned int	f_color;
	unsigned int	c_color;
	unsigned int	color;
	int				texx;
	int				texy;
	int				img_n;
	double			steps;
	double			wallx;
	double			tex_position;
	t_img			img[8];
	t_img			s_img[18];
	t_img			g_img[6];
}	t_ray;

typedef struct s_analog
{
	int	a;
	int	w;
	int	s;
	int	d;
	int	space;
	int	up_arrow;
	int	left_arrow;
	int	right_arrow;
	int	shift;
}	t_analog;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			x;
	t_analog	analog;
}	t_mlx;

typedef struct s_all
{
	t_mlx		*mlx;
	t_map		*parsing;
	t_ray		*ray;
	char		**map;
}	t_all;

//-------------------stor map :
void			get_map(char *s, t_map *tab);
int				read_map_size(char *s);
void			read_map(t_map *tab);

//-------------------check map :
void			map_check(t_map *map);
void			error_map(int num);
void			ft_color_ceiling(t_map *map, int i, int *e, int j);
void			ft_color_floor(t_map *map, int i, int *e, int j);
void			check_if_func(t_map *map, int i, int j);

//------------------read line :
char			*get_next_line(int fd);

//------------------libft :
size_t			ft_strlen(const char *s);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strrchr(const char *s, int c);
void			*ft_calloc(size_t count, size_t size);
int				ft_strchrr(char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strdup(const char *s1);
int				ft_atoi(const char *str);

//-------------------ray casting :
int				ft_error(char *str, int exit_status);
char			*ft_strchr(char *s, int c);
void			calc_step_init_sidedist(t_ray *r, t_mlx *mlx, char **map);
void			walls_hits(t_ray *r, t_mlx *mlx, char **map);
void			wall_high(t_ray *r, t_mlx *mlx);
void			walls_colors(t_ray *r, t_mlx *mlx);
void			my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
void			get_image(void *mlx, t_img	*img, char *filename);
void			paint_on_screen(t_ray *ray, t_mlx *mlx, char **map);
void			window_creation(t_all *all, t_ray *ray, t_map map);
void			player_direction(t_ray *ray, char **map);
void			texture_getter(void *mlx, t_ray *ray, t_map parsing);
unsigned int	img_color(t_img *t, int x, int y);
int				player_movement(t_all *analog);
int				button_press(int key, t_all *al);
int				button_release(int key, t_all *al);
int				esc(int key);
int				mouse(int x, int y, t_all *all);
void			rotate_player_with_mouse(int x, int old_x, t_all *t);
void			dig_difftial_ans_paint(t_ray *ray, t_mlx *mlx, \
				char **map, int x);
void			wall_hit_if(t_ray *r, char **map);
void			table_allocation(t_ray *ray);
void			r_p_with_if(t_all *t);

//----------------------display sprites :
void			speed(t_all *t);
void			spirit_img(t_ray *r, void *mlx);
void			to_display(t_all *t);

#endif
