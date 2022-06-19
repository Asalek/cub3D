/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_element_00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelgharo <yelgharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:21:05 by yelgharo          #+#    #+#             */
/*   Updated: 2022/06/19 20:49:12 by yelgharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*void	error_color(int num)
{
	
}*/

char	*ft_path(t_map *map, int i, int *e, int j)
{
	int			n;
	int			l;
	static int	many;
	char		*line;

	n = 0;
	l = 0;
	while (map->tab[i][j] == ' ' || map->tab[i][j] == '\t')
		j++;
	l = ft_strlen(map->tab[i]) - j;
	line = malloc(l);
	while (map->tab[i][j])
	{
		line[n] = map->tab[i][j];
		j++;
		n++;
	}
	line[n] = '\0';
	(*e)++;
	many++;
	if (many > 4)
		error_map(6);
	return (line);
}

void	ft_color_ceiling(t_map *map, int i, int *e, int j)
{
	static int		l;
	int				n;
	int				r;
	char			tmp[4];

	r = 0;
	while (map->tab[i][j] != '\0' && map->tab[i][j] <= 32)
		j++;
	while (map->tab[i][j])
	{
		n = 0;
		while (map->tab[i][j] && map->tab[i][j] != ',')
			tmp[n++] = map->tab[i][j++];
		tmp[n] = '\0';
		if (map->tab[i][j])
		{
			if (map->tab[i][j] == ',')
				r++;
			j++;
		}
		if (l == 0)
			map->c.r = ft_atoi(tmp);
		else if (l == 1)
			map->c.g = ft_atoi(tmp);
		else if (l == 2)
			map->c.b = ft_atoi(tmp);
		l++;
	}
	if (r != 2)
	{
		printf("error a ssat error siiii");
		exit(1);
	}
	if ((map->c.r < 0 || map->c.r > 255) || (map->c.g < 0 \
		|| map->c.g > 255) || (map->c.b < 0 || map->c.b > 255))
	{
		printf("error too big/small");
		exit(1);
	}
	if (l != 3)
	{
		printf("error more/less than expact C");
		exit(1);
	}
	(*e)++;
}

void	ft_color_floor(t_map *map, int i, int *e, int j)
{
	int				n;
	static int		l;
	int				r;
	char		tmp[4];

	r = 0;
	while (map->tab[i][j] != '\0' && map->tab[i][j] <= 32)
		j++;
	while (map->tab[i][j])
	{
		n = 0;
		while (map->tab[i][j] && map->tab[i][j] != ',')
			tmp[n++] = map->tab[i][j++];
		tmp[n] = '\0';
		if (map->tab[i][j])
		{
			if (map->tab[i][j] == ',')
				r++;
			j++;
		}
		if (l == 0)
			map->f.r = ft_atoi(tmp);
		else if (l == 1)
			map->f.g = ft_atoi(tmp);
		else if (l == 2)
			map->f.b = ft_atoi(tmp);
		l++;
	}
	if (r != 2)
	{
		printf("error a ssat error siii");
		exit(1);
	}
	if ((map->f.r < 0 || map->f.r > 255) || (map->f.g < 0 \
		|| map->f.g > 255) || (map->f.b < 0 || map->f.b > 255))
	{
		printf("error too big/small");
		exit(1);
	}
	if (l != 3)
	{
		printf("error more/less than expact F");
		exit(1);
	}
	(*e)++;
}

void	stor_map(t_map *map, int i)
{
	int	j;
	int	e;
	int	l;

	j = 0;
	while (!map->tab[i][0])
		i++;
	map->ln = map->colomn - i;
	map->map = malloc(sizeof(char **) * map->ln + 1);
	while (i < map->colomn)
	{
		e = 0;
		l = ft_strlen(map->tab[i]);
		map->map[j] = malloc(l + 1);
		while (map->tab[i][e])
		{
			map->map[j][e] = map->tab[i][e];
			e++;
		}
		map->map[j][e] = '\0';
		i++;
		j++;
	}
	map->map[j] = (NULL);
}

void	double_check(t_map *map, int i, int *e, int j)
{
	while (map->tab[i][j] && map->tab[i][j] <= 32)
		j++;
	if (map->tab[i][j] == 'N' && map->tab[i][j + 1] == 'O')
		map->north = ft_path(map, i, e, j + 2);
	else if (map->tab[i][j] == 'S' && map->tab[i][j + 1] == 'O')
		map->south = ft_path(map, i, e, j + 2);
	else if (map->tab[i][j] == 'W' && map->tab[i][j + 1] == 'E')
		map->west = ft_path(map, i, e, j + 2);
	else if (map->tab[i][j] == 'E' && map->tab[i][j + 1] == 'A')
		map->east = ft_path(map, i, e, j + 2);
	else if (map->tab[i][j] == 'F')
		ft_color_floor(map, i, e, j+ 1);
	else if (map->tab[i][j] == 'C')
		ft_color_ceiling(map, i, e, j+ 1);
	else if (map->tab[i][j])
	{
		printf("Error:\n\tMore/less Element Needed\n\t\tWrong !!\n");
		exit(1);
	}
}

int	while_condition(t_map *map, int i, int j, int *e)
{
	if (map->tab[i][j] == 'N' && map->tab[i][j + 1] == 'O')
		map->north = ft_path(map, i, e, j + 2);
	else if (map->tab[i][j] == 'S' && map->tab[i][j + 1] == 'O')
		map->south = ft_path(map, i, e, j + 2);
	else if (map->tab[i][j] == 'W' && map->tab[i][j + 1] == 'E')
		map->west = ft_path(map, i, e, j + 2);
	else if (map->tab[i][j] == 'E' && map->tab[i][j + 1] == 'A')
		map->east = ft_path(map, i, e, j + 2);
	else if (map->tab[i][j] == 'F')
		ft_color_floor(map, i, e, j + 1);
	else if (map->tab[i][j] == 'C')
		ft_color_ceiling(map, i, e, j + 1);
	else if ((*e) == 6)
	{
		stor_map(map, i);
		return(1);
	}
	else if ((*e) < 6)
		double_check(map, i, e, j + 1);
	return (0);
}

void	read_map(t_map *map)
{
	int	i;
	int	j;
	int e;

	i = 0;
	e = 0;
	while (i < map->colomn)
	{
		j = 0;
		if (while_condition(map, i, j, &e))
			break ;
		i++;
	}
	i = 0;
	while (i < map->colomn)
	{
		free(map->tab[i]);
		i++;
	}
	free(map->tab);
	if (!map->east || !map->north || !map->west || !map->south)
	{
		printf("Error:\n\tPath Duplicated \n\t    Wrong !!\n");
		exit(1);
	}
}
