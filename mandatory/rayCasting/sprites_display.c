/* ************************************************************************** */
/*                                                                        */
/*                                                        :::      ::::::::   */
/*   sprites_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelgharo <yelgharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:02:29 by yelgharo          #+#    #+#             */
/*   Updated: 2022/09/01 16:44:44 by yelgharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	to_display(t_all *t)
{
	static int i;
	int poss;
	int possy;

	poss = (X_AXIS - (X_AXIS / 3.4));
	possy = (Y_AXIS - (Y_AXIS + (Y_AXIS / 5)));
	if (t->mlx->analog.up_arrow == 1)
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
		t->ray->g_img[2].img, (X_AXIS / 3),  (Y_AXIS) - (Y_AXIS / 2));
	else if (t->mlx->analog.space == 0)
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
		t->ray->g_img[0].img, (X_AXIS / 3),  (Y_AXIS) - (Y_AXIS / 2));
	else
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, 
		t->ray->g_img[1].img, (X_AXIS / 3),  (Y_AXIS) - (Y_AXIS / 2));
	if (i > 0)
	{
		if (i >= 0 && i <= 10)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
			t->ray->s_img[0].img, poss,  possy);
		else if (i > 10 && i <= 20)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
			t->ray->s_img[1].img, poss,  possy);		
		else if (i > 20 && i <= 30)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
			t->ray->s_img[2].img, poss,  possy);
		else if (i > 30 && i <= 40)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
			t->ray->s_img[3].img, poss,  possy);
		else if (i > 40 && i <= 50)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
			t->ray->s_img[4].img, poss,  possy);
		else if (i > 50 && i <= 60)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
			t->ray->s_img[5].img, poss,  possy);
		else if (i > 60 && i <= 70)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
			t->ray->s_img[6].img, poss,  possy);		
		else if (i >= 70 && i <= 80)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
			t->ray->s_img[7].img, poss,  possy);		
		else if (i >= 80 && i <= 90)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
			t->ray->s_img[8].img, poss,  possy);		
		else if (i >= 90 && i < 100)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
			t->ray->s_img[9].img, poss,  possy);		
		else if (i >= 100 && i < 110)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
			t->ray->s_img[10].img, poss, possy);		
		else if (i >= 110 && i < 120)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
			t->ray->s_img[11].img, poss, possy);		
		else if (i >= 120 && i < 130)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
			t->ray->s_img[12].img, poss, possy);		
		else if (i >= 130 && i < 140)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
			t->ray->s_img[13].img, poss, possy);		
		else if (i >= 140 && i < 150)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
			t->ray->s_img[14].img, poss, possy);		
		else if (i >= 150 && i < 160)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
			t->ray->s_img[15].img, poss, possy);		
		else if (i >= 160 && i < 170)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, \
			t->ray->s_img[16].img, poss, possy);		
		else if (i >= 170 && i < 180)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, 
			t->ray->s_img[17].img, poss, possy);
		else
			i = 0;
	}
}