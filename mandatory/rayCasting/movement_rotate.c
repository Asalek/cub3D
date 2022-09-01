/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:23:44 by asalek            #+#    #+#             */
/*   Updated: 2022/09/01 15:30:48 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_player(t_all *t)
{
	double	olddirx;
	double	oldplanex;

	oldplanex = t->ray->planex;
	olddirx = t->ray->dirx;
	if (t->mlx->analog.left_arrow == 1)
	{
		t->ray->dirx = t->ray->dirx * cos(-ROTATE_SPEED) \
			- t->ray->diry * sin(-ROTATE_SPEED);
		t->ray->diry = olddirx * sin(-ROTATE_SPEED) \
			+ t->ray->diry * cos(-ROTATE_SPEED);
		t->ray->planex = t->ray->planex * cos(-ROTATE_SPEED) \
			- t->ray->planey * sin(-ROTATE_SPEED);
		t->ray->planey = oldplanex * sin(-ROTATE_SPEED) \
			+ t->ray->planey * cos(-ROTATE_SPEED);
	}
	if (t->mlx->analog.right_arrow == 1)
	{
		t->ray->dirx = t->ray->dirx * cos(ROTATE_SPEED) \
			- t->ray->diry * sin(ROTATE_SPEED);
		t->ray->diry = olddirx * sin(ROTATE_SPEED) \
			+ t->ray->diry * cos(ROTATE_SPEED);
		t->ray->planex = t->ray->planex * cos(ROTATE_SPEED) \
			- t->ray->planey * sin(ROTATE_SPEED);
		t->ray->planey = oldplanex * sin(ROTATE_SPEED) \
			+ t->ray->planey * cos(ROTATE_SPEED);
	}
}

void	rotate_player_with_mouse(int x, int old_x, t_all *t)
{
	if (x > old_x)
	{
		double oldDirX = t->ray->dirx;
		double oldPlaneX = t->ray->planex;
		
		t->ray->dirx = t->ray->dirx * cos(-ROTATE_SPEED)\
			- t->ray->diry * sin(-ROTATE_SPEED);
		t->ray->diry = oldDirX * sin(-ROTATE_SPEED)\
			+ t->ray->diry * cos(-ROTATE_SPEED);
		t->ray->planex = t->ray->planex * cos(-ROTATE_SPEED)\
			- t->ray->planey * sin(-ROTATE_SPEED);
		t->ray->planey = oldPlaneX * sin(-ROTATE_SPEED)\
			+ t->ray->planey * cos(-ROTATE_SPEED);
	}
	if (x < old_x)
	{
		double oldDirX = t->ray->dirx;
		double oldPlaneX = t->ray->planex;
		
		t->ray->dirx = t->ray->dirx * cos(ROTATE_SPEED)\
			- t->ray->diry * sin(ROTATE_SPEED);
		t->ray->diry = oldDirX * sin(ROTATE_SPEED)\
			+ t->ray->diry * cos(ROTATE_SPEED);
		t->ray->planex = t->ray->planex * cos(ROTATE_SPEED)\
			- t->ray->planey * sin(ROTATE_SPEED);
		t->ray->planey = oldPlaneX * sin(ROTATE_SPEED)\
			+ t->ray->planey * cos(ROTATE_SPEED);
	}
}

void	s_key(t_all *t)
{
	if (t->mlx->analog.s == 1)
	{
		if (t->map[(int)(t->ray->posx - t->ray->dirx * SPEED)]\
			[(int)t->ray->posy] != '1')
			t->ray->posx -= t->ray->dirx * SPEED;
		if (t->map[(int)(t->ray->posx)]\
			[(int)(t->ray->posy - t->ray->diry * SPEED)] != '1')
			t->ray->posy -= t->ray->diry * SPEED;
	}
	if (t->mlx->analog.shift == 1 && t->mlx->analog.w == 1)
	{
		if (t->map[(int)(t->ray->posx + t->ray->dirx * 0.23)] \
		[(int)t->ray->posy] != '1')
			t->ray->posx += t->ray->dirx * 0.23;
		if (t->map[(int)(t->ray->posx)] \
		[(int)(t->ray->posy + t->ray->diry * 0.23)] != '1')
			t->ray->posy +=t->ray->diry * 0.23;
	}
	else if (t->mlx->analog.w == 1)
	{
		if (t->map[(int)(t->ray->posx + t->ray->dirx * SPEED)] \
		[(int)t->ray->posy] != '1')
			t->ray->posx += t->ray->dirx * SPEED;
		if (t->map[(int)(t->ray->posx)] \
		[(int)(t->ray->posy + t->ray->diry * SPEED)] != '1')
			t->ray->posy +=t->ray->diry * SPEED;
	}
}

void	doors_open_close(t_all *t)
{
	int	i;
	int	j;

	i = -1;
	while (t->map[++i])
	{
		j = -1;
		while (t->map[i][++j])
		{
			if (t->map[i][j] == '2' && (fabs(i - t->ray->posx)))
				t->map[i][j] = '3';				
			if (t->map[i][j] == '3' && (fabs(j - t->ray->posy) >= 3))
				t->map[i][j] = '2';				
		}
	}
}

int	player_movement(t_all *t)
{
	static int i = 0;
	int poss = (X_AXIS - (X_AXIS / 3.4));
	int possy = (Y_AXIS - (Y_AXIS + (Y_AXIS / 6)));
	if (t->mlx->analog.a == 1)
	{
		if (t->map[(int)t->ray->posx] \
		[(int)(t->ray->posy - SPEED * t->ray->planey)] != '1')
			t->ray->posy = t->ray->posy - SPEED * t->ray->planey;
		if (t->map[(int)(t->ray->posx - SPEED * t->ray->planex)] \
		[(int)(t->ray->posy)] != '1')
			t->ray->posx = t->ray->posx - SPEED * t->ray->planex;
	}
	if (t->mlx->analog.d == 1)
	{
		if (t->map[(int)t->ray->posx] \
		[(int)(t->ray->posy + SPEED * t->ray->planey)] != '1')
			t->ray->posy = t->ray->posy + SPEED * t->ray->planey;
		if (t->map[(int)(t->ray->posx + t->ray->planex * SPEED)] \
		[(int)(t->ray->posy)] != '1')
			t->ray->posx = t->ray->posx + t->ray->planex * SPEED;
	}
	s_key(t);
	rotate_player(t);
	doors_open_close(t);
	paint_on_screen(t->ray, t->mlx, t->map);
	if (t->mlx->analog.up_arrow == 1)
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->g_img[2].img, (X_AXIS / 3),  (Y_AXIS) - (Y_AXIS / 2));
	else if (t->mlx->analog.space == 0)
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->g_img[0].img, (X_AXIS / 3),  (Y_AXIS) - (Y_AXIS / 2));
	else
		mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->g_img[1].img, (X_AXIS / 3),  (Y_AXIS) - (Y_AXIS / 2));
	if (i > 0)
	{
		if (i >= 0 && i <= 10)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[0].img, poss,  possy);
		else if (i > 10 && i <= 20)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[1].img, poss,  possy);		
		else if (i > 20 && i <= 30)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[2].img, poss,  possy);
		else if (i > 30 && i <= 40)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[3].img, poss,  possy);
		else if (i > 40 && i <= 50)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[4].img, poss,  possy);
		else if (i > 50 && i <= 60)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[5].img, poss,  possy);
		else if (i > 60 && i <= 70)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[6].img, poss,  possy);		
		else if (i >= 70 && i <= 80)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[7].img, poss,  possy);		
		else if (i >= 80 && i <= 90)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[8].img, poss,  possy);		
		else if (i >= 90 && i < 100)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[9].img, poss,  possy);		
		else if (i >= 100 && i < 110)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[10].img, poss, possy);		
		else if (i >= 110 && i < 120)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[11].img, poss, possy);		
		else if (i >= 120 && i < 130)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[12].img, poss, possy);		
		else if (i >= 130 && i < 140)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[13].img, poss, possy);		
		else if (i >= 140 && i < 150)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[14].img, poss, possy);		
		else if (i >= 150 && i < 160)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[15].img, poss, possy);		
		else if (i >= 160 && i < 170)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[16].img, poss, possy);		
		else if (i >= 170 && i < 180)
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[17].img, poss, possy);
		else
			i = 0;
	}
	i++;
	return (0);
}
