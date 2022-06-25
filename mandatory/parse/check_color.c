/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelgharo <yelgharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:53:48 by yelgharo          #+#    #+#             */
/*   Updated: 2022/06/20 13:17:39 by yelgharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_color(int num)
{
	if (num == 0)
		printf("Error:\n\tLess/More Comma\n\t   Wrong !!\n");
	else if (num == 1)
		printf("Error:\n\tLess/More Than 0/255\n\t\tWrong !!\n");
	else if (num == 2)
		printf("Error:\n\tCheck The G.R.B\n\t\tWrong !!\n");
	exit (1);
}

int	ceiling_while(t_map *map, int i, int l, int *j)
{
	int		n;
	int		r;
	char	tmp[4];

	n = 0;
	r = 0;
	while (map->tab[i][*j] && map->tab[i][*j] != ',')
		tmp[n++] = map->tab[i][(*j)++];
	tmp[n] = '\0';
	if (map->tab[i][*j])
	{
		if (map->tab[i][*j] == ',')
			r++;
		(*j)++;
	}
	if (l == 0)
		map->c.r = ft_atoi(tmp);
	else if (l == 1)
		map->c.g = ft_atoi(tmp);
	else if (l == 2)
		map->c.b = ft_atoi(tmp);
	return (r);
}

int	floor_while(t_map *map, int i, int l, int *j)
{
	int		n;
	int		r;
	char	tmp[4];

	n = 0;
	r = 0;
	while (map->tab[i][*j] && map->tab[i][*j] != ',')
		tmp[n++] = map->tab[i][(*j)++];
	tmp[n] = '\0';
	if (map->tab[i][*j])
	{
		if (map->tab[i][*j] == ',')
			r++;
		(*j)++;
	}
	if (l == 0)
		map->f.r = ft_atoi(tmp);
	else if (l == 1)
		map->f.g = ft_atoi(tmp);
	else if (l == 2)
		map->f.b = ft_atoi(tmp);
	return (r);
}

void	ft_color_ceiling(t_map *map, int i, int *e, int j)
{
	static int		l;
	int				r;

	r = 0;
	while (map->tab[i][j] != '\0' && map->tab[i][j] <= 32)
		j++;
	while (map->tab[i][j])
	{
		r += ceiling_while(map, i, l, &j);
		l++;
	}
	if (r != 2)
		error_color(0);
	if ((map->c.r < 0 || map->c.r > 255) || (map->c.g < 0 \
		|| map->c.g > 255) || (map->c.b < 0 || map->c.b > 255))
		error_color(1);
	if (l != 3)
		error_color(2);
	(*e)++;
}

void	ft_color_floor(t_map *map, int i, int *e, int j)
{
	static int		l;
	int				r;

	r = 0;
	while (map->tab[i][j] != '\0' && map->tab[i][j] <= 32)
		j++;
	while (map->tab[i][j])
	{
		r += floor_while(map, i, l, &j);
		l++;
	}
	if (r != 2)
		error_color(0);
	if ((map->f.r < 0 || map->f.r > 255) || (map->f.g < 0 \
		|| map->f.g > 255) || (map->f.b < 0 || map->f.b > 255))
		error_color(1);
	if (l != 3)
		error_color(2);
	(*e)++;
}
