/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:15:31 by asalek            #+#    #+#             */
/*   Updated: 2022/07/17 17:15:08 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	esc(int key)
{
	(void)key;
	
	return (exit(0), 0);
}

int	button_press(int key, t_all *al)
{
	if (key == 53)
		exit(0);
	else if (key == 0)
		al->mlx->analog.a = 1;
	else if (key == 1)
		al->mlx->analog.s = 1;
	else if (key == 2)
		al->mlx->analog.d = 1;
	else if (key == 13)
		al->mlx->analog.w = 1;
	else if (key == 123)
		al->mlx->analog.right_arrow = 1;
	else if (key == 124)
		al->mlx->analog.left_arrow = 1;
	return (0);
}
int	button_release(int key, t_all *al)
{
	if (key == 0)
		al->mlx->analog.a = 0;
	if (key == 1)
		al->mlx->analog.s = 0;
	if (key == 2)
		al->mlx->analog.d = 0;
	if (key == 13)
		al->mlx->analog.w = 0;
	if (key == 123)
		al->mlx->analog.right_arrow = 0;
	if (key == 124)
		al->mlx->analog.left_arrow = 0;
	return (0);
}
