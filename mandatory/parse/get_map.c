/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelgharo <yelgharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 06:39:33 by yelgharo          #+#    #+#             */
/*   Updated: 2022/09/02 00:32:21 by yelgharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_map(char *s, t_map *map)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	map->tab = (char **)malloc(sizeof(char *) * map->colomn + 1);
	fd = open(s, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map->tab[i] = line;
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	map->tab[i] = NULL;
}

int	read_map_size(char *s)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(s, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		printf("Error:\n\t Map Essue !!");
		exit(1);
	}
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	check_if_func(t_map *map, int i, int j)
{
	if (i == 0 || i == map->ln - 1)
		error_map(2);
	else if (map->map[i - 1][j] <= 32 || map->map[i + 1][j] <= 32 \
		|| map->map[i][j - 1] <= 32 || map->map[i][j + 1] <= 32)
		error_map(2);
}
