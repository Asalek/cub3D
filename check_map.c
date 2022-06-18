/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelgharo <yelgharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:21:15 by yelgharo          #+#    #+#             */
/*   Updated: 2022/06/17 23:21:15 by yelgharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_check(t_map *map)
{
	int	i;
	int	j;
	int n;
	int w;
	int e;
	int s;
	int somme;

	n = 0;
	w = 0;
	e = 0;
	s = 0;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] != '0' && map->map[i][j] != '1' \
			&& map->map[i][j] != 'N' && map->map[i][j] != 'S' \
			&& map->map[i][j] != 'W' && map->map[i][j] != 'E' \
			&& map->map[i][j] != ' ')
			{
				printf("error element not expected");
				exit(1);
			}
			else if (map->map[i][j] == '0')
			{
				if (map->map[i - 1][j] <= 32 || map->map[i + 1][j] <= 32 \
				|| map->map[i][j - 1] <= 32 || map->map[i][j + 1] <= 32 )
				{
					printf("error  0 nieber not expexted");
					exit(1);
				}
			}
			else if (map->map[i][j] == 'S' || map->map[i][j] == 'N' \
				|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
				{
					if (i == 0 || i == map->ln - 1)
					{
					printf("error");
					exit(1);
					}
					else if ((map->map[i - 1][j] != '1' && map->map[i - 1][j] != '0') \
				|| (map->map[i][j - 1] != '1' && map->map[i][j - 1] != '0') \
				|| (map->map[i + 1][j] != '0' && map->map[i + 1][j] != '1') \
				|| (map->map[i][j + 1] != '0' && map->map[i][j + 1] != '1'))
				{
					printf("error");
					exit(1);
				}
				}
			if (map->map[i][j] == 'W')
				w++;
			if (map->map[i][j] == 'S')
				s++;
			if (map->map[i][j] == 'E')
				e++;
			if (map->map[i][j] == 'N')
				n++;
			j++;
		}
		i++;
	}
	somme = n + e + s + w;
	if (somme != 1)
	{
		printf("error element more then expected");
		exit(1);
	}
}