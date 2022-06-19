/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelgharo <yelgharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:21:15 by yelgharo          #+#    #+#             */
/*   Updated: 2022/06/19 20:20:36 by yelgharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_count(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'W')
		map->w++;
	if (map->map[i][j] == 'S')
		map->s++;
	if (map->map[i][j] == 'E')
		map->e++;
	if (map->map[i][j] == 'N')
		map->n++;
}

void	error_map(int num)
{
	if (num == 0)
		printf("Error:\n\tVide Line\n\t   Wrong !!\n");
	else if (num == 1)
		printf("Error:\n\tElement Not Expected\n\t\tWrong !!\n");
	else if (num == 2)
		printf("Error:\n\tVide Space Not In Place\n\t\tWrong !!\n");
	else if (num == 3)
		printf("Error:\n\tPlayer Not In Place\n\t\tWrong !!\n");
	else if (num == 4)
		printf("Error:\n\tExtra Vide Lines\n\t  Wrong !!\n");
	else if (num == 5)
		printf("Error:\n\tOnly One Player Valid\n\t\tWrong !!\n");
	else if (num == 6)
		printf("Error:\n\tOnly One Path Valid\n\t\tWrong !!\n");
	exit (1);
}

void	ft_conditions_check(t_map *map, int i, int j)
{
	if (map->map[i][j] != '0' && map->map[i][j] != '1' \
		&& map->map[i][j] != 'N' && map->map[i][j] != 'S' \
		&& map->map[i][j] != 'W' && map->map[i][j] != 'E' \
		&& map->map[i][j] != ' ')
		error_map(1);
	if (map->map[i][j] == '0')
	{
		if (i == 0 || i == map->ln - 1)
			error_map(2);
		else if (map->map[i - 1][j] <= 32 || map->map[i + 1][j] <= 32 \
			|| map->map[i][j - 1] <= 32 || map->map[i][j + 1] <= 32)
			error_map(2);
	}
	else if (map->map[i][j] == 'S' || map->map[i][j] == 'N' \
		|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
	{
		if (i == 0 || i == map->ln - 1)
			error_map(3);
		else if ((map->map[i - 1][j] != '1' && map->map[i - 1][j] != '0') \
			|| (map->map[i][j - 1] != '1' && map->map[i][j - 1] != '0') \
			|| (map->map[i + 1][j] != '0' && map->map[i + 1][j] != '1') \
			|| (map->map[i][j + 1] != '0' && map->map[i][j + 1] != '1'))
			error_map(3);
	}
}

void	ft_somme(t_map *map)
{
	int	somme;

	somme = map->n + map->e + map->s + map->w;
	if (somme != 1)
		error_map(5);
}

void	map_check(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			while (map->map[i][j] && map->map[i][j] == 32)
			{
				j++;
				if (map->map[i][j] == '\0')
					error_map(0);
			}
			ft_conditions_check(map, i, j);
			player_count(map, i, j);
			j++;
		}
		if (map->map[i][0] == '\0' || map->map[i][0] == '\n')
			error_map(4);
		i++;
	}
	ft_somme(map);
}
