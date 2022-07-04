/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:00:24 by asalek            #+#    #+#             */
/*   Updated: 2022/07/04 23:01:09 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
			if (p == 'N' || p == 'E' || p == 'W' || p == 'S')
			{
				ray->posx = x;
				ray->posy = y;
				map[x][y] = '0';
				if (p == 'S' || p == 'N')
				{
					ray->dirx = 1;
					ray->diry = 0;
					ray->planex = 0;
					ray->planey = -0.66;
					if (p == 'N')
					{
						ray->dirx = -1;
						ray->planey = 0.66;
					}
				}
				if (p == 'W' || p == 'E')
				{
					ray->dirx = 0;
					ray->diry = 1;
					ray->planex = 0.66;
					ray->planey = 0;
					if (p == 'W')
					{
						ray->diry = -1;
						ray->planex = -0.66;
					}
				}
			}
		}
	}
}

