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

void	ft_exit()
{
	exit(0);
}

void	my_mlx_pixel_put(t_asset *data, int x, int y, int color)
{
  char	*dst;

  dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
  *(unsigned int*)dst = color;
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

void	player_direction(t_structs *all)
{
	int		x;
	int		y;
	char	p;

	x = 0;
	while (all->map[x])
	{
		y = 0;
		while (all->map[x][y])
		{
			p = all->map[x][y];
			if (p == 'N' || p == 'E' || p == 'W' || p == 'S')
			{
				all->ray->posx = x;
				all->ray->posy = y;
				all->map[x][y] = '0';
				if (p == 'S' || p == 'N')
				{
					all->ray->dirx = 1;
					all->ray->diry = 0;
					all->ray->planx = 0;
					all->ray->plany = -0.66;
					if (p == 'N')
					{
						all->ray->dirx = -1;
						all->ray->plany = 0.66;
					}
				}
				if (p == 'W' || p == 'E')
				{
					all->ray->dirx = 0;
					all->ray->diry = 1;
					all->ray->planx = 0.66;
					all->ray->plany = 0;
					if (p == 'W')
					{
						all->ray->diry = -1;
						all->ray->planx = -0.66;
					}
				}
				break ;
			}
			y++;
		}
		x++;
	}
}

int	main(int ac, char **av)
{
	t_map	map;
	t_mlx	s;
	t_ray	raycast;
	t_structs	all;

	map.tab = NULL;
	if (arg_chek(ac, av))
		return (1);
	map.colomn = read_map_size(av[1]);
	get_map(av[1], &map);
	ft_init(&map);
	read_map(&map);
	map_check(&map);
	all.map = map.map;
	all.ray = &raycast;
	player_direction(&all);
	int i = 0;
	while (all.map[i])
	{
		printf("%s\n", all.map[i]);
		i++;
	}
	s.mlx_ptr = mlx_init();
	s.win_ptr = mlx_new_window (s.mlx_ptr, X_AXIS, Y_AXIS, "Cub3D_Asalek_Yelgharo");
	// texture()
	// drawONscreen()
	// mlx_hook(s.win_ptr, 33, 1L << 17, ft_exit, recup);
	mlx_loop(s.mlx_ptr);
	return (0);
}
