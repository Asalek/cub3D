/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelgharo <yelgharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:02:29 by yelgharo          #+#    #+#             */
/*   Updated: 2022/09/01 22:42:48 by yelgharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	part_1(t_all *t, int i, int posx, int posy)
{
	if (i >= 0 && i <= 10)
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
		t->ray->s_img[0].img, posx, posy);
	else if (i > 10 && i <= 20)
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
		t->ray->s_img[1].img, posx, posy);
	else if (i > 20 && i <= 30)
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
		t->ray->s_img[2].img, posx, posy);
	else if (i > 30 && i <= 40)
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
		t->ray->s_img[3].img, posx, posy);
	else if (i > 40 && i <= 50)
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
		t->ray->s_img[4].img, posx, posy);
	else if (i > 50 && i <= 60)
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
		t->ray->s_img[5].img, posx, posy);
	else if (i > 60 && i <= 70)
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
		t->ray->s_img[6].img, posx, posy);
	else if (i >= 70 && i <= 80)
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
		t->ray->s_img[7].img, posx, posy);
}

void	part_2(t_all *t, int i, int posx, int posy)
{
	if (i >= 80 && i <= 90)
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
		t->ray->s_img[8].img, posx, posy);
	else if (i >= 90 && i < 100)
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
		t->ray->s_img[9].img, posx, posy);
	else if (i >= 100 && i < 110)
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
		t->ray->s_img[10].img, posx, posy);
	else if (i >= 110 && i < 120)
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
		t->ray->s_img[11].img, posx, posy);
	else if (i >= 120 && i < 130)
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
		t->ray->s_img[12].img, posx, posy);
	else if (i >= 130 && i < 140)
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
		t->ray->s_img[13].img, posx, posy);
	else if (i >= 140 && i < 150)
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
		t->ray->s_img[14].img, posx, posy);
	else if (i >= 150 && i < 160)
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
		t->ray->s_img[15].img, posx, posy);
}

void	animation(t_all *t, int i, int posx, int posy)
{
	if (i >= 0 && i <= 80)
		part_1(t, i, posx, posy);
	else if (i >= 80 && i <= 160)
		part_2(t, i, posx, posy);
	else if (i >= 160 && i < 170)
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
		t->ray->s_img[16].img, posx, posy);
	else if (i >= 170 && i < 180)
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
		t->ray->s_img[17].img, posx, posy);
}

void	to_display(t_all *t)
{
	static int	i;
	int			posx;
	int			posy;

	posx = (X_AXIS - (X_AXIS / 3.4));
	posy = (Y_AXIS - (Y_AXIS + (Y_AXIS / 5)));
	if (t->mlx->analog.up_arrow == 1)
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
		t->ray->g_img[2].img, (X_AXIS / 3), (Y_AXIS) - (Y_AXIS / 2));
	else if (t->mlx->analog.space == 0)
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
		t->ray->g_img[0].img, (X_AXIS / 3), (Y_AXIS) - (Y_AXIS / 2));
	else
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
		t->ray->g_img[1].img, (X_AXIS / 3), (Y_AXIS) - (Y_AXIS / 2));
	if (i > 0)
	{
		if (i > 0 && i <= 180)
			animation(t, i, posx, posy);
		else
			i = 0;
	}
	i++;
}
