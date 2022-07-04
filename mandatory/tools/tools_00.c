/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 04:32:13 by yelgharo          #+#    #+#             */
/*   Updated: 2022/07/04 18:15:23 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if ((char)c == 0)
		return ((char *)s + len);
	while (s && len--)
	{
		if (s[len] == (char)c)
			return ((char *)s + len);
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2 || *s1 == '\0' || *s2 == '\0')
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	moins;
	int	res;

	i = 0;
	moins = 0;
	res = 0;
	if ((str[i]) && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			moins++;
		i++;
	}
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
		{
			printf("Error:\n\tNot Digit\n\t\tWrong !!\n");
			exit(1);
		}
		res = res * 10 + str[i++] - '0';
	}
	if (moins % 2 == 0)
		return (res);
	return (res * -1);
}
