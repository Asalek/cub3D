/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelgharo <yelgharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 04:33:19 by yelgharo          #+#    #+#             */
/*   Updated: 2022/06/15 11:50:09 by yelgharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 1

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

	char	*north;
	char	*west;
	char	*east;
	char	*south;

	t_color	f;
	t_color	c;
}	t_map;

//-------------------map :
void	get_map(char *s, t_map *tab);
int		read_map_size(char *s);
void	read_map(t_map *tab);

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
