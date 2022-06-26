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
