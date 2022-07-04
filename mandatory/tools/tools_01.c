/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 06:02:14 by yelgharo          #+#    #+#             */
/*   Updated: 2022/07/04 20:51:02 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n > 0)
	{
		*p = 0;
		p++;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
		return (NULL);
	else
		ft_bzero(p, count * size);
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	n;
	char	*ptr;

	i = -1;
	j = 0;
	if (!s1)
		s1 = (char *)ft_calloc(1, 1);
	if (!s1 || !s2)
		return (NULL);
	n = (ft_strlen(s1) + ft_strlen(s2));
	ptr = malloc(sizeof(char ) * (n + 1));
	if (!ptr)
		return (NULL);
	while (s1[++i])
		ptr[i] = s1[i];
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

int	ft_strchrr(char *s)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (1);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*p;

	i = 0;
	len = ft_strlen(s1);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (((char *)s1)[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = 0;
	return (p);
}
