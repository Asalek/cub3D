/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:31:12 by yelgharo          #+#    #+#             */
/*   Updated: 2022/07/05 19:08:35 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/includes/cub3d.h"

unsigned int	img_color(t_img *t, int x, int y)
{
	char	*s_d;
	int		p_d;

	p_d = y * t->sl + x * 4;
	s_d = t->addr + p_d;
	return ((((unsigned char)s_d[2]) << 16)
		+ (((unsigned char)s_d[1]) << 8) + ((unsigned char)s_d[0]));
}

void	ft_init(t_map *map)
{
	map->north = NULL;
	map->east = NULL;
	map->west = NULL;
	map->south = NULL;
	map->map = NULL;
	map->w = 0;
	map->s = 0;
	map->n = 0;
	map->e = 0;
	map->position = malloc(sizeof (int) * 2);
}

int	arg_chek(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_strncmp(ft_strrchr(av[1], '.'), ".cub\0", 5))
		{
			printf("Error:\n\tMap's Extension\n\t   Wrong !!\n");
			return (1);
		}
		return (0);
	}
	else if (ac > 2)
	{
		printf("Error:\n\tToo Many Args\n\t   Wrong !!\n");
		return (1);
	}
	printf("Error:\n\tNo Args Detected\n\t   Wrong !!\n");
	return (1);
}

int	main(int ac, char **av)
{
	t_map	map;
	t_all	all;
	t_ray	ray;

	map.tab = NULL;
	if (arg_chek(ac, av))
		return (1);
	map.colomn = read_map_size(av[1]);
	get_map(av[1], &map);
	ft_init(&map);
	read_map(&map);
	map_check(&map);
	player_direction(&ray, map.map);
	all.map = map.map;
	window_creation(&all, &ray, map);
	return (0);
}
