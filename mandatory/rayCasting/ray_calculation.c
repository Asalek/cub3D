#include "../includes/cub3d.h"

void	dig_difftial_ans_paint(t_ray *ray,t_mlx *mlx,char **map,int x)
{
	//calculate ray position and direction
	ray->camera = 2 * x / (double)X_AXIS - 1; //x-coordinate in camera space
	ray->raydirx = ray->dirx + ray->planex * ray->camera;
	ray->raydiry = ray->diry + ray->planey * ray->camera;
	ray->mapx = (int)ray->posx;//which box of the map we're in
	ray->mapy = (int)ray->posy;
	// if (ray->dirx == 0)
	// 	ray->deltadistx = 1e30;
	// else
	ray->deltadistx = fabs(1 / ray->raydirx);
	// if (ray->diry == 0)
	// 	ray->deltadisty = 1e30;
	// else
		ray->deltadisty = fabs(1 / ray->raydiry);
	// ray->deltadistx = sqrt(1 + (ray->diry * ray->diry) / (ray->dirx * ray->dirx));// ray to the second X encounter with
	// ray->deltadisty = sqrt(1 + (ray->dirx * ray->dirx) / (ray->diry * ray->diry));// ray to the second Y encounter with
	ray->hit = 0; //was there a wall hit?
	calc_step_init_sidedist(ray, mlx, map);
}

void	calc_step_init_sidedist(t_ray *r, t_mlx *mlx, char **map)
{
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
	walls_hits(r, mlx, map);
}

void	walls_hits(t_ray *r, t_mlx *mlx, char **map)
{
	while (r->hit == 0)
	{
		if (r->sidedistx < r->sidedisty)
		{
			r->img_n = 1;
			r->sidedistx += r->deltadistx;
			r->mapx += r->stepx;
			if (r->raydirx > 0)
				r->img_n = 0;
			r->side = 0;
		}
		else
		{
			r->sidedisty += r->deltadisty;
			r->mapy += r->stepy;
			r->img_n = 3;
			if (r->raydiry > 0)
				r->img_n = 2;
			r->side = 1;
		}
		if (map[r->mapx][r->mapy] == '1') //Check if ray has hit a wall
			r->hit = 1;
	}
	wall_high(r, mlx);
}

void	wall_high(t_ray *r, t_mlx *mlx)
{
	if (r->side == 0)
		r->perpwalldist = r->sidedistx - r->deltadistx;
	else
		r->perpwalldist = r->sidedisty - r->deltadisty;
	r->line_height = (int)(Y_AXIS / r->perpwalldist);
	r->drawstart = -r->line_height / 2 + Y_AXIS / 2;
	if (r->drawstart < 0)
		r->drawstart = 0;
	r->drawend = r->line_height / 2 + Y_AXIS / 2;
	if (r->drawend >= Y_AXIS)
		r->drawend = Y_AXIS - 1;
	if (r->side == 0)
		r->wallx = r->posy + r->perpwalldist * r->raydiry;
	else
		r->wallx = r->posx + r->perpwalldist * r->raydirx;
	r->wallx -= floor(r->wallx);
	r->texx = (int)(r->wallx * (float)T_W);
	if (r->side == 0 && r->raydirx > 0)
		r->texx = T_W - r->texx - 1;
	if (r->side == 1 && r->raydiry < 0)
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
		r->color = get_color(&r->img[r->img_n], r->texx, r->texy);
		r->tab[i][mlx->x] = r->color;
		i++;
	}
	while (i < Y_AXIS)
		r->tab[i++][mlx->x] = r->f_color;
}
