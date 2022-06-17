/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelgharo <yelgharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:31:12 by yelgharo          #+#    #+#             */
/*   Updated: 2022/06/17 11:17:28 by yelgharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init(t_map *map)
{
	map->north = NULL;
	map->east = NULL;
	map->west = NULL;
	map->south = NULL;
	map->map = NULL;
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

	if (arg_chek(ac, av))
		return (1);
	map.colomn = read_map_size(av[1]);
	get_map(av[1], &map);
//	ft_init(&map);
	read_map(&map);
	printf("%s\n", map.north);
	printf("%s\n", map.south);
	printf("%s\n", map.west);
	printf("%s\n", map.east);
	printf("r : %d|\tg : %d|\tb : %d\n", map.f.r, map.f.g, map.f.b);
	printf("r : %d|\tg : %d |\tb : %d\n", map.c.r, map.c.g, map.c.b);
	int i = 0;
	while (map.map[i])
	{
		printf("%s\n",map.map[i]);
		i++;
	}
	return (0);
}
