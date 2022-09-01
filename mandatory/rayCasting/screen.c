/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelgharo <yelgharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:02:53 by asalek            #+#    #+#             */
/*   Updated: 2022/09/01 23:41:59 by yelgharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	paint_on_screen(t_ray *ray, t_mlx *mlx, char **map)
{
	int	i;
	int	x;
	int	y;

	mlx->img = mlx_new_image(mlx->mlx, X_AXIS, Y_AXIS);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, \
	&mlx->size_line, &mlx->endian);
	i = 0;
	while (i++ < X_AXIS)
	{
		mlx->x = i;
		dig_difftial_ans_paint(ray, mlx, map, i);
	}
	x = 0;
	while (x < Y_AXIS)
	{
		y = -1;
		while (++y < X_AXIS)
			my_mlx_pixel_put(mlx, y, x, ray->tab[x][y]);
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_string_put(mlx->mlx, mlx->win, (X_AXIS - (X_AXIS / 5)), \
	0, 0xf5f516, "Asalek & Yelgaro");
	mlx_destroy_image(mlx->mlx, mlx->img);
}

void	window_creation(t_all *all, t_ray *ray, t_map p_map)
{
	t_mlx	s;

	table_allocation(ray);
	all->mlx = &s;
	all->ray = ray;
	s.mlx = mlx_init();
	s.win = mlx_new_window (s.mlx, X_AXIS, Y_AXIS, "Cub3D_Asalek_Yelgharo");
	texture_getter(s.mlx, ray, p_map);
	spirit_img(ray, s.mlx);
	all->mlx->analog.w = 0;
	all->mlx->analog.d = 0;
	all->mlx->analog.space = 0;
	all->mlx->analog.up_arrow = 0;
	paint_on_screen(ray, &s, all->map);
	mlx_hook(s.win, 02, 1L << 0, button_press, all);
	mlx_hook(s.win, 03, 1L << 1, button_release, all);
	mlx_hook(s.win, 17, 1L << 17, esc, all);
	mlx_hook(s.win, 06, 1L << 06, mouse, all);
	mlx_loop_hook(s.mlx, player_movement, all);
	mlx_loop(s.mlx);
}

void	get_image(void *mlx, t_img	*img, char *filename)
{
	int	i;
	int	j;

	img->img = mlx_xpm_file_to_image(mlx, filename, &i, &j);
	if (!img->img)
	{
		printf("invalid texture files\n");
		exit(0);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->sl, &img->en);
	if (!img->addr)
	{
		printf("Error While getting Img Address\n");
		exit(0);
	}
}

void	texture_getter(void *mlx, t_ray *ray, t_map parsing)
{
	ray->c_color = (parsing.c.r << 16) + (parsing.c.g << 8)
		+ parsing.c.b;
	ray->f_color = (parsing.f.r << 16) + (parsing.f.g << 8)
		+ parsing.f.b;
	get_image(mlx, &ray->img[0], IMG_1);
	get_image(mlx, &ray->img[1], IMG_2);
	get_image(mlx, &ray->img[2], IMG_3);
	get_image(mlx, &ray->img[3], IMG_4);
	get_image(mlx, &ray->img[4], IMG_5);
	get_image(mlx, &ray->img[5], IMG_6);
	get_image(mlx, &ray->img[6], IMG_7);
	get_image(mlx, &ray->img[7], IMG_8);
}
