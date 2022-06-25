/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelgharo <yelgharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 06:39:33 by yelgharo          #+#    #+#             */
/*   Updated: 2022/06/15 11:46:36 by yelgharo         ###   ########.fr       */
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
