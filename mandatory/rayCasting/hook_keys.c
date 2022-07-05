/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalek <asalek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 20:15:31 by asalek            #+#    #+#             */
/*   Updated: 2022/07/05 20:15:50 by asalek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	button_press(int key, t_all *al)
{
	if (key == 53)
		exit(0);
	if (key == 0)
		al->mlx->analog.a = 1;
	if (key == 1)
		al->mlx->analog.s = 1;
	if (key == 2)
		al->mlx->analog.d = 1;
	if (key == 13)
		al->mlx->analog.w = 1;
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
	return (0);
}
