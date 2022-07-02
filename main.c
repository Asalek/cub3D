/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 02:31:12 by yelgharo          #+#    #+#             */
/*   Updated: 2022/07/02 16:49:12 by asalek           ###   ########.fr       */
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

void	texture(t_structs *all)
{
	int		wid;
	int		hig;
	t_img	img[4];

	puts("AA");
	img[0].img = mlx_xpm_file_to_image(all->mlx->mlx_ptr, IMG_1, &wid, &hig);
	puts("BB");
	if (!img[0].img)
		return (printf("assets not set"), exit(0));
	img[0].addr = mlx_get_data_addr(img[0].img, &img[0].bp, &img[0].ll, &img[0].e);
	
	img[1].img = mlx_xpm_file_to_image(all->mlx->mlx_ptr, IMG_2, &wid, &hig);
	if (!img[1].img)
		return (printf("assets not set"), exit(0));
	img[1].addr = mlx_get_data_addr(img[1].img, &img[1].bp, &img[1].ll, &img[1].e);	
	// img[2].img = mlx_xpm_file_to_image(all->mlx->mlx_ptr, IMG_3, &wid, &hig);
	// if (!img[2].img)
	// 	return (printf("assets not set"), exit(0));
	// img[2].addr = mlx_get_data_addr(img[2].img, &img[2].bp, &img[2].ll, &img[2].e);
	
	// img[3].img = mlx_xpm_file_to_image(all->mlx->mlx_ptr, IMG_4, &wid, &hig);
	// if (!img[3].img)
	// 	return (printf("assets not set"), exit(0));
	// img[3].addr = mlx_get_data_addr(img[3].img, &img[3].bp, &img[3].ll, &img[3].e);
	
	// img[4].img = mlx_xpm_file_to_image(all->mlx->mlx_ptr, IMG_4, &wid, &hig);
	// if (!img[4].img)
	// 	return (printf("assets not set"), exit(0));
	// img[4].addr = mlx_get_data_addr(img[4].img, &img[4].bp, &img[4].ll, &img[4].e);
	all->img = img;
}

void	window_init(t_structs *all)
{
	t_mlx	s;
	// t_asset asset;
	int	i;

	i = 0;
	all->ray->tab = malloc(X_AXIS * sizeof(unsigned int));
	if (!all->ray->tab)
	{
		printf("Failed to allocat the main Table");
		exit(0);
	}
	while (i < X_AXIS)
	{
		all->ray->tab[i] = malloc(Y_AXIS * sizeof(unsigned int));
		if (!all->ray->tab[i])
		{
			printf("Failed to allocat table number : %d", i);
			exit(0);
		}
		i++;
	}
	s.mlx_ptr = mlx_init();
	s.win_ptr = mlx_new_window (s.mlx_ptr, X_AXIS, Y_AXIS, "Cub3D_Asalek_Yelgharo");
	all->mlx = &s;
	// asset.img = mlx_new_image(s.mlx_ptr, X_AXIS, Y_AXIS);
	// asset.addr = mlx_get_data_addr(asset.img, &asset.bits_per_pixel, &asset.line_length, &asset.endian);
	// asset.addr[y * recup->asset.line_length / 4 + x] = color;
	// my_mlx_pixel_put(&asset, 50, 50, 255);
	texture(all);
	mlx_put_image_to_window(s.mlx_ptr, s.win_ptr, all->img[0].img, 0, 0); //put image to window
	// drawONscreen()
	// mlx_hook(s.win_ptr, 33, 1L << 17, ft_exit, recup);
	mlx_loop(s.mlx_ptr);
}

int	main(int ac, char **av)
{
	t_map	map;
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
	window_init(&all);
	int i = 0;
	while (all.map[i])
	{
		printf("%s\n", all.map[i]);
		i++;
	}
	return (0);	
}
