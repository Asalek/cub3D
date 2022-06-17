/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_element_00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelgharo <yelgharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:21:05 by yelgharo          #+#    #+#             */
/*   Updated: 2022/06/17 15:07:22 by yelgharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_path(t_map *map, char *line, int i, int *e)
{
	int	n;
	int	l;
	int	j;

	n = 0;
	l = 0;
	j = 2;
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
	return (line);
}

void	ft_color_ceiling(t_map *map, int i, int *e)
{
	int		n;
	int		l;
	int		j;
	char	tmp[4];

	j = 1;
	l = 0;
	while (map->tab[i][j] == ' ' || map->tab[i][j] == '\t')
		j++;
	while (map->tab[i][j])
	{
		n = 0;
		while (map->tab[i][j] && map->tab[i][j] != ',')
			tmp[n++] = map->tab[i][j++];
		j++;
		tmp[n] = '\0';
		if (l == 0)
			map->c.r = ft_atoi(tmp);
		else if (l == 1)
			map->c.g = ft_atoi(tmp);
		else if (l == 2)
			map->c.b = ft_atoi(tmp);
		l++;
	}
	(*e)++;
}

void	ft_color_floor(t_map *map, int i, int *e)
{
	int		n;
	int		l;
	int		j;
	char	tmp[4];

	j = 1;
	l = 0;
	while (map->tab[i][j] == ' ' || map->tab[i][j] == '\t')
		j++;
	while (map->tab[i][j])
	{
		n = 0;
		while (map->tab[i][j] && map->tab[i][j] != ',')
			tmp[n++] = map->tab[i][j++];
		j++;
		tmp[n] = '\0';
		if (l == 0)
			map->f.r = ft_atoi(tmp);
		else if (l == 1)
			map->f.g = ft_atoi(tmp);
		else if (l == 2)
			map->f.b = ft_atoi(tmp);
		l++;
	}
	(*e)++;
}

void	stor_map(t_map *map, int i)
{
	int	j;
	int	e;
	int	l;

	j = 0;
	while (map->tab[i][0] == '\n' || !map->tab[i][0])
		i++;
	map->map = malloc(sizeof(char **) * (map->colomn - i) + 1);
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
		if (map->tab[i][j] == 'N' && map->tab[i][j + 1] == 'O')
			map->north = ft_path(map, map->north, i, &e);
		else if (map->tab[i][j] == 'S' && map->tab[i][j + 1] == 'O')
			map->south = ft_path(map, map->south, i, &e);
		else if (map->tab[i][j] == 'W' && map->tab[i][j + 1] == 'E')
			map->west = ft_path(map, map->west, i, &e);
		else if (map->tab[i][j] == 'E' && map->tab[i][j + 1] == 'A')
			map->east = ft_path(map, map->east, i, &e);
		else if (map->tab[i][j] == 'F')
			ft_color_floor(map, i, &e);
		else if (map->tab[i][j] == 'C')
			ft_color_ceiling(map, i, &e);
		else if (e == 6)
		{
			stor_map(map, i + 1);
			break ;
		}
		i++;
	}
	for (i = 0; i < map->colomn; i++)
		free(map->tab[i]);
	free(map->tab);
}
