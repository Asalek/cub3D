/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelgharo <yelgharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:31:12 by yelgharo          #+#    #+#             */
/*   Updated: 2022/06/21 13:31:53 by yelgharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/includes/cub3d.h"

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
/*
int	main(int ac, char **av)
{
	t_map	map;
	map.tab = NULL;
	if (arg_chek(ac, av))
		return (1);
	map.colomn = read_map_size(av[1]);
	get_map(av[1], &map);
	ft_init(&map);
	read_map(&map);
	map_check(&map);
	printf("Error:\n\tMore/less Element Needed\n\t\tWrong !!\n");
	printf("%s\n", map.north);
	printf("%s\n", map.south);
	printf("%s\n", map.west);
	printf("%s\n", map.east);
	printf("%d,%d,%d\n", map.c.r,map.c.g,map.c.b);
	printf("%d,%d,%d\n", map.f.r,map.f.g,map.f.b);
	printf("%d\n", map.position[0]);
	printf("%d\n", map.position[1]);
	int index =  0; 
	while (index < map.ln) 
	{
		printf("%s\n", map.map[index]);
		index++;
	}
	printf("%d\n", index);
	printf("%d\n", map.colomn);
	printf("%d\n", map.ln);
	return (0);
}
*/

int main(void)
{
	t_mlx	s;

	// int	mapx = 8;
	// int	mapy = 8;
	// int	map[]=
	// {
	// 	1, 1, 1, 1, 1, 1, 1, 1,
	// 	1, 0, 0, 0, 0, 0, 0, 1,
	// 	1, 0, 0, 0, 0, 0, 0, 1,
	// 	1, 0, 1, 0, 0, 1, 0, 1,
	// 	1, 0, 0, 0, 1, 0, 0, 1,
	// 	1, 0, 0, 0, 0, 0, 0, 1,
	// 	1, 0, 0, 0, 0, 0, 0, 1,
	// 	1, 1, 1, 1, 1, 1, 1, 1,
	// };
	s.mlx_ptr = mlx_init();
	s.win_ptr = mlx_new_window (s.mlx_ptr, X_AXIS, Y_AXIS, "Mandelbrot_Set");
	mlx_loop(s.mlx_ptr);
	return (0);
}
