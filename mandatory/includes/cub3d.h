/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelgharo <yelgharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 04:33:19 by yelgharo          #+#    #+#             */
/*   Updated: 2022/06/20 11:56:49 by yelgharo         ###   ########.fr       */
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
#define X_AXIS 800
#define Y_AXIS 600
#define PI 3.1415926535

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
	int 	*position;

	t_color	f;
	t_color	c;
}	t_map;

typedef struct mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	jx;
	double	jy;
	int		x;
	int		y;
}	t_mlx;

typedef struct images
{
	void	*mlx;
	void	*win;
	void	*image;
	void	*path;
	int		width;
	int		height;
}	t_img;

typedef struct	s_ray
{
	double		posx; //position x du joueur
	double		posy; //position y du joueur
	double		dirx; //vecteur de direction (commence à -1 pour N, 1 pour S, 0 sinon)
	double		diry; //vecteur de direction (commence à -1 pour W, 1 pour E, 0 sinon)
	double		planx; //vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
	double		plany; //vecteur du plan (commence à 0.66 pour N, -0.66 pour S, 0 sinon)
	double		raydirx; //calcul de direction x du rayon
	double		raydiry; //calcul de direction y du rayon
	double		camerax; //point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
	int		mapx; // coordonée x du carré dans lequel est pos
	int		mapy; // coordonnée y du carré dans lequel est pos
	double		sidedistx; //distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x)
	double		sidedisty; //distance que le rayon parcours jusqu'au premier point d'intersection horizontal (= un coté y)
	double		deltadistx; //distance que rayon parcours entre chaque point d'intersection vertical
	double		deltadisty; //distance que le rayon parcours entre chaque point d'intersection horizontal
	int		stepx; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	int		stepy; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	int		hit; // 1 si un mur a ete touche, 0 sinon
	int		side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	double		perpwalldist; // distance du joueur au mur
	int		lineheight; //hauteur de la ligne a dessiner
	int		drawstart; //position de debut ou il faut dessiner
	int		drawend; //position de fin ou il faut dessiner
	int		x; //permet de parcourir tous les rayons
	unsigned int	**tab;
}					t_ray;

typedef struct  s_assets {
  void        *img;
  char        *addr;
  int         bits_per_pixel;
  int         line_length;
  int         endian;
}               t_asset;

typedef struct all_structs
{
	t_mlx	*mlx;
	char	**map;
	t_ray	*ray;
}	t_structs;


//-------------------stor map :
void	get_map(char *s, t_map *tab);
int		read_map_size(char *s);
void	read_map(t_map *tab);

//-------------------check map :
void	map_check(t_map *map);
void	error_map(int num);
void	ft_color_ceiling(t_map *map, int i, int *e, int j);
void	ft_color_floor(t_map *map, int i, int *e, int j);

//------------------read line :
char	*get_next_line(int fd);

//------------------libft :
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strrchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
int		ft_strchr(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
int		ft_atoi(const char *str);

#endif
