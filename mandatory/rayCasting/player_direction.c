/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:00:24 by asalek            #+#    #+#             */
/*   Updated: 2022/08/07 18:59:39 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	set_dir_plane_w(t_ray *ray, char p)
{
	if (p == 'W')
	{
		ray->dirx = 0;
		ray->planey = 0;
		ray->diry = -1;
		ray->planex = -0.66;
		return (1);
	}
	return (0);
}

int	set_dir_plane(t_ray *ray, char p)
{
	if (p == 'S')
	{
		ray->dirx = 1;
		ray->diry = 0;
		ray->planex = 0;
		ray->planey = -0.66;
		return (1);
	}
	else if (p == 'N')
	{
		ray->dirx = -1;
		ray->diry = 0;
		ray->planex = 0;
		ray->planey = 0.66;
		return (1);
	}
	else if (p == 'E')
	{
		ray->dirx = 0;
		ray->diry = 1;
		ray->planex = 0.66;
		ray->planey = 0;
		return (1);
	}
	return (set_dir_plane_w(ray, p));
}

void	player_direction(t_ray *ray, char **map)
{
	int		x;
	int		y;
	char	p;

	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			p = map[x][y];
			if (set_dir_plane(ray, p) == 1)
			{
				ray->posx = x;
				ray->posy = y;
				map[x][y] = '0';
			}
		}
	}
}
