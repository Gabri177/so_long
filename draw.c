/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 01:06:01 by yugao             #+#    #+#             */
/*   Updated: 2024/02/19 02:27:37 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	dw_bk(t_data info)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!info.img_bk)
		return (FALSE);
	while (i < info.win_x)
	{
		j = 0;
		while (j < info.win_y)
		{
			mlx_put_image_to_window(info.mlx,
				info.win, info.img_bk, i * UNI, j * UNI);
			j ++;
		}
		i ++;
	}
	return (TRUE);
}

t_bool	dw_ctr(t_data *info, int x, int y)
{
	if (!info->img_ctr)
		return (FALSE);
	if (!mlx_put_image_to_window (info->mlx, info->win, info->img_ctr,
			x * UNI, y * UNI))
		return (FALSE);
	info->ctr_x = x;
	info->ctr_y = y;
	return (TRUE);
}

t_bool	dw_mov(t_data *i, int x, int y) // 目前没有检测机制 比如地图边缘 和 墙 
{
	if (!dw_bk (*i))
		return (FALSE);
	if (!dw_ctr (i, x, y))
		return (FALSE);
	i->n_mov ++;
	return (TRUE);
}
