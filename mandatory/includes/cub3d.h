/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 04:33:19 by yelgharo          #+#    #+#             */
/*   Updated: 2022/08/26 16:03:29 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
// # include <MMsystem.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx_opengl_20191021/mlx.h"

# define BUFFER_SIZE 1
# define X_AXIS 800
# define Y_AXIS 500
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
	double			posx; //position x du joueur
	double			posy; //position y du joueur
	double			dirx; //vecteur de direction (commence à -1 pour N, 1 pour S, 0 sinon)
	double			diry; //vecteur de direction (commence à -1 pour W, 1 pour E, 0 sinon)
	double			planex; //vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
	double			planey; //vecteur du plan (commence à 0.66 pour N, -0.66 pour S, 0 sinon)
	double			raydirx; //calcul de direction x du rayon
	double			raydiry; //calcul de direction y du rayon
	double			camera; //point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
	int				mapx; // coordonée x du carré dans lequel est pos
	int				mapy; // coordonnée y du carré dans lequel est pos
	int				stepx; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	int				stepy; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	double			sidedistx; //distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x)
	double			sidedisty; //distance que le rayon parcours jusqu'au premier point d'intersection horizontal (= un coté y)
	double			deltadistx; //distance que rayon parcours entre chaque point d'intersection vertical
	double			deltadisty; //distance que le rayon parcours entre chaque point d'intersection horizontal
	int				hit; // 1 si un mur a ete touche, 0 sinon
	double			perpwalldist; // distance du joueur au mur
	int				side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	int				line_height; //hauteur de la ligne a dessiner
	int				drawstart; //position de debut ou il faut dessiner
	int				drawend; //position de fin ou il faut dessiner
	unsigned int	**tab; //tablau de couleur
	unsigned int	f_color; //floor color
	unsigned int	c_color; //ciel color
	unsigned int	color; //wall colors
	int				texx; // coordonnée x de la texture
	int				texy; // coordonnée y de la texture
	int				img_n;// image number 1 to 7
	double			steps; //indique de combien augmenter les coordonnées de la texture pour chaque pixel
	double			wallx; // valeur où le mur a été touché : coordonnée y si side == 0, coordonnée x si side == 1
	double			tex_position;// coordonnée de départ
	t_img			img[8];
}	t_ray;

typedef struct s_analog
{
	int	a;
	int	w;
	int	s;
	int	d;
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
void			dig_difftial_ans_paint(t_ray *ray, t_mlx *mlx \
				, char **map, int x);

#endif
