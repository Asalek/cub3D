/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 06:04:57 by yelgharo          #+#    #+#             */
/*   Updated: 2022/07/04 18:09:23 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_read(int fd, char *out)
{
	int		i;
	char	*str;

	if (!out)
		out = ft_strdup("");
	while (!ft_strchrr(out))
	{
		str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		i = read(fd, str, BUFFER_SIZE);
		if (i < 0)
		{
			free (str);
			return (NULL);
		}
		if (i == 0)
		{
			free(str);
			break ;
		}
		str[i] = '\0';
		out = ft_strjoin(out, str);
		free(str);
	}
	return (out);
}

char	*get_line(char *str)
{
	char	*out;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	out = (char *)malloc(i + 1);
	if (!out)
		return (NULL);
	while (str[j] && str[j] != '\n')
	{
		out[j] = str[j];
		j++;
	}
	out[j] = '\0';
	return (out);
}

char	*ft_update(char *str)
{
	int		l;
	int		i;
	int		j;
	char	*out;

	i = 0;
	l = 0;
	while (str[l] && str[l] != '\n')
		l++;
	if (!str[l])
		return (free (str), NULL);
	if (str[l] == '\n')
		l++;
	j = l;
	while (str[l] != '\0')
		l++;
	out = (char *)malloc((l - j) + 1);
	if (!out)
		return (NULL);
	while (str[j])
		out[i++] = str[j++];
	out[i] = '\0';
	free (str);
	return (out);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*out;

	if (fd < 0 || BUFFER_SIZE == 0 || read(fd, 0, 0) < 0)
		return (NULL);
	str = ft_read(fd, str);
	out = get_line(str);
	str = ft_update(str);
	return (out);
}
