/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelgharo <yelgharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 22:58:00 by yelgharo          #+#    #+#             */
/*   Updated: 2022/09/02 00:16:09 by yelgharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	wall_hit_if(t_ray *r, char **map)
{
	r->hit = 1;
	if (map[r->mapx][r->mapy] == '2')
		r->img_n = 4;
	if (map[r->mapx][r->mapy] == '3')
		r->img_n = 5;
}

void	table_allocation(t_ray *ray)
{
	int		i;

	i = -1;
	ray->tab = malloc(Y_AXIS * sizeof(unsigned int *));
	if (!ray->tab)
	{
		printf("Failed to allocat the main Table");
		exit(0);
	}
	while (++i < Y_AXIS)
	{
		ray->tab[i] = malloc(X_AXIS * sizeof(unsigned int));
		if (!ray->tab[i])
		{
			printf("Failed to allocat table number : %d", i);
			exit(0);
		}
	}
}

void	spirit_img(t_ray *r, void *mlx)
{
	get_image(mlx, &r->s_img[0], S_IMG_1);
	get_image(mlx, &r->s_img[1], S_IMG_2);
	get_image(mlx, &r->s_img[2], S_IMG_3);
	get_image(mlx, &r->s_img[3], S_IMG_4);
	get_image(mlx, &r->s_img[4], S_IMG_5);
	get_image(mlx, &r->s_img[5], S_IMG_6);
	get_image(mlx, &r->s_img[6], S_IMG_7);
	get_image(mlx, &r->s_img[7], S_IMG_8);
	get_image(mlx, &r->s_img[8], S_IMG_9);
	get_image(mlx, &r->s_img[9], S_IMG_10);
	get_image(mlx, &r->s_img[10], S_IMG_11);
	get_image(mlx, &r->s_img[11], S_IMG_12);
	get_image(mlx, &r->s_img[12], S_IMG_13);
	get_image(mlx, &r->s_img[13], S_IMG_14);
	get_image(mlx, &r->s_img[14], S_IMG_15);
	get_image(mlx, &r->s_img[15], S_IMG_16);
	get_image(mlx, &r->s_img[16], S_IMG_17);
	get_image(mlx, &r->s_img[17], S_IMG_18);
	get_image(mlx, &r->g_img[0], GUN_IMG_1);
	get_image(mlx, &r->g_img[1], GUN_IMG_2);
	get_image(mlx, &r->g_img[2], GUN_IMG_3);
	get_image(mlx, &r->g_img[3], GUN_IMG_4);
	get_image(mlx, &r->g_img[4], GUN_IMG_5);
	get_image(mlx, &r->g_img[5], GUN_IMG_6);
}

void	r_p_with_if(t_all *t)
{
	double	olddirx;
	double	oldplanex;

	olddirx = t->ray->dirx;
	oldplanex = t->ray->planex;
	t->ray->dirx = t->ray->dirx * cos(ROTATE_SPEED) \
		- t->ray->diry * sin(ROTATE_SPEED);
	t->ray->diry = olddirx * sin(ROTATE_SPEED) \
		+ t->ray->diry * cos(ROTATE_SPEED);
	t->ray->planex = t->ray->planex * cos(ROTATE_SPEED) \
		- t->ray->planey * sin(ROTATE_SPEED);
	t->ray->planey = oldplanex * sin(ROTATE_SPEED) \
		+ t->ray->planey * cos(ROTATE_SPEED);
}

void	speed(t_all *t)
{
	if (t->map[(int)(t->ray->posx + t->ray->dirx * 0.23)] \
	[(int)t->ray->posy] != '1')
		t->ray->posx += t->ray->dirx * 0.23;
	if (t->map[(int)(t->ray->posx)] \
	[(int)(t->ray->posy + t->ray->diry * 0.23)] != '1')
		t->ray->posy += t->ray->diry * 0.23;
}
