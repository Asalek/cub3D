/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:31:12 by yelgharo          #+#    #+#             */
/*   Updated: 2022/08/04 17:33:43 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/includes/cub3d.h"

unsigned int	img_color(t_img *t, int x, int y)
{
	int		offset;
	char	*img_pix;
	uint32_t	color;
	offset = y * t->sl + x * (t->bpp / 8);//memory offset (line_length differs from the actual window width)
	img_pix = t->addr + offset;
	if (!img_pix)
	{
		printf("Error in puting pixel's color!\n");
		exit(0);
	}
	color = (((unsigned char)img_pix[2] << 16) + ((unsigned char)img_pix[1] << 8) + (unsigned char)img_pix[0]);
	if (color)
		return (color);
	else
		return ((unsigned int)4732952);
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
