/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:23:44 by asalek            #+#    #+#             */
/*   Updated: 2022/08/30 18:18:37 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_player(t_all *t)
{
	if (t->mlx->analog.left_arrow == 1)
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
	if (t->mlx->analog.right_arrow == 1)
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
	// int poss = 0;
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
	spirit_display();
	if (i > 0)
	{
		if (i >= 0 && i <= 3)
		{
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[0].img, 5, 0);//b		
			// mlx_destroy_image(t->mlx->mlx, t->ray->s_img[0].img);//b
		}
		else if (i > 3 && i <= 6)
		{
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[1].img, 5, 0);//b		
			// mlx_destroy_image(t->mlx->mlx, t->ray->s_img[1].img);//b
		}
		else if (i > 6 && i <= 9)
		{
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[2].img, 5, 0);//b		
			// mlx_destroy_image(t->mlx->mlx, t->ray->s_img[2].img);//b
		}
		else if (i > 9 && i <= 12)
		{
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[3].img, 5, 0);//b		
			// mlx_destroy_image(t->mlx->mlx, t->ray->s_img[3].img);//b
		}
		else if (i > 12 && i <= 15)
		{
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[4].img, 5, 0);//b		
			// mlx_destroy_image(t->mlx->mlx, t->ray->s_img[4].img);//b
		}
		else if (i > 15 && i <= 18)
		{
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[5].img, 5, 0);//b		
			// mlx_destroy_image(t->mlx->mlx, t->ray->s_img[5].img);//b
		}
		else if (i > 18 && i <= 21)
		{
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[6].img, 5, 0);//b		
			// mlx_destroy_image(t->mlx->mlx, t->ray->s_img[6].img);//b
		}
		else if (i > 21 && i <= 24)
		{
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[7].img, 5, 0);//b		
			// mlx_destroy_image(t->mlx->mlx, t->ray->s_img[7].img);//b
		}
		else if (i > 24 && i <= 27)
		{
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[8].img, 5, 0);//b		
			// mlx_destroy_image(t->mlx->mlx, t->ray->s_img[8].img);//b
		}
		else if (i > 27 && i < 31)
		{
			mlx_put_image_to_window(t->mlx->mlx, t->mlx->win, t->ray->s_img[9].img, 5, 0);//b		
			// mlx_destroy_image(t->mlx->mlx, t->ray->s_img[9].img);//b
		}
		else
			i = 0;
	}
	i++;
	return (0);
}
