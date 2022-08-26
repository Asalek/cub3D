/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:11:09 by asalek            #+#    #+#             */
/*   Updated: 2022/08/26 16:16:17 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	dig_difftial_ans_paint(t_ray *ray,t_mlx *mlx,char **map,int x)
{
	double	camera_y_coordinate;

	//calculate ray position and direction
	ray->camera = 2 * x / (double)X_AXIS - 1; //x-coordinate in camera space
	camera_y_coordinate = 2 * x / (double)Y_AXIS - 1;
	ray->raydirx = ray->dirx + ray->planex * ray->camera;
	ray->raydiry = ray->diry + ray->planey * ray->camera;
	ray->mapx = (int)ray->posx;//which box of the map we're in
	ray->mapy = (int)ray->posy;
	if (ray->raydirx != 0)
		ray->deltadistx = fabs(1 / ray->raydirx);
	else
		ray->deltadistx = 7728;	//1e30
	if (ray->raydiry != 0)
		ray->deltadisty = fabs(1 / ray->raydiry);
	else
		ray->deltadisty = 7728;
	calc_step_init_sidedist(ray, mlx, map);
}

void	calc_step_init_sidedist(t_ray *r, t_mlx *mlx, char **map)
{
	if (r->raydiry < 0)
	{
		r->stepy = -1;
		r->sidedisty = (r->posy - r->mapy) * r->deltadisty;
	}
	else
	{
		r->stepy = 1;
		r->sidedisty = (r->mapy + 1.0 - r->posy) * r->deltadisty;
	}
	if (r->raydirx < 0)
	{
		r->stepx = -1;
		r->sidedistx = (r->posx - r->mapx) * r->deltadistx;
	}
	else
	{
		r->stepx = 1;
		r->sidedistx = (r->mapx + 1.0 - r->posx) * r->deltadistx;
	}
	walls_hits(r, mlx, map);
}

void	walls_hits(t_ray *r, t_mlx *mlx, char **map)
{
	r->hit = 0; //was there a wall hit?
	while (r->hit == 0)
	{
		r->img_n = 1;
		if (r->sidedistx < r->sidedisty) // loop that increments the ray with 1 square every time
		{
			r->sidedistx += r->deltadistx;
			r->mapx += r->stepx;//either it jumps a square in the x-direction (with stepX) or a square in the y-direction (with stepY)
			r->side = 0; //wall in front or back
			if (r->raydirx > 0)
				r->img_n = 0;
		}
		else
		{
			r->img_n = 3;
			r->sidedisty += r->deltadisty;   //next square
			r->mapy += r->stepy;
			r->side = 1;  //wall in right or left. sloped (3wj)
			if (r->raydiry > 0)
				r->img_n = 2;
		}
		if (map[r->mapx][r->mapy] != '0') //Check if ray has hit a wall or door
		{
			r->hit = 1;
			if (map[r->mapx][r->mapy] == '2')
				r->img_n = 4;
			if (map[r->mapx][r->mapy] == '3')
				r->img_n = 5;
		}
	}
	wall_high(r, mlx);
}
//dda done
void	wall_high(t_ray *r, t_mlx *mlx)
{
	if (r->side == 0)
		r->perpwalldist = r->sidedistx - r->deltadistx;  //how far i'am for the wall
	else
		r->perpwalldist = r->sidedisty - r->deltadisty;
	r->line_height = (int)(Y_AXIS / r->perpwalldist);//height of the vertical line that should be drawn
	//calculate lowest and highest pixel to fill in current stripe
	r->drawstart = -r->line_height / 2 + Y_AXIS / 2;
	if (r->drawstart < 0)
		r->drawstart = 0;
	r->drawend = r->line_height / 2 + Y_AXIS / 2;
	if (r->drawend >= Y_AXIS)
		r->drawend = Y_AXIS - 1;
	//wallX represents the exact value where the wall was hit
	if (r->side == 0)
		r->wallx = r->posy + r->perpwalldist * r->raydiry; // y horizontal on wall
	else
		r->wallx = r->posx + r->perpwalldist * r->raydirx;
	r->wallx -= floor(r->wallx);

	r->texx = (int)(r->wallx * (double)T_W);
	// if (r->side == 0 && r->raydirx > 0)
	// 	r->texx = T_W - r->texx - 1;
	// if (r->side == 1 && r->raydiry < 0)
	r->texx = T_W - r->texx - 1;

	r->steps = 1.0 * T_H / r->line_height;
	r->tex_position = (r->drawstart - Y_AXIS / 2 + \
		r->line_height / 2) * r->steps;
	walls_colors(r, mlx);
}

void	walls_colors(t_ray *r, t_mlx *mlx)
{
	int	i;

	i = 0;
	while (i < r->drawstart)
		r->tab[i++][mlx->x] = r->c_color;
	while (i < r->drawend)
	{
		r->texy = (int)r->tex_position & (T_H - 1);
		r->tex_position += r->steps;
		r->color = img_color(&r->img[r->img_n], r->texx, r->texy);
		r->tab[i][mlx->x] = r->color;
		i++;
	}
	while (i < Y_AXIS)
		r->tab[i++][mlx->x] = r->f_color;
}
//ToDo: set the color of the wall based on the color from the texture