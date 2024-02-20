/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 01:06:01 by yugao             #+#    #+#             */
/*   Updated: 2024/02/20 03:06:03 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	dw_wall(t_data info, t_ary m)
{
	int	i;
	int	j;

	if (!info.img_wal)
		return (FALSE);
	i = 0;
	while (i < info.win_y / UNI)
	{
		j = 0;
		while (j < info.win_x / UNI)
		{
			if (m[j][i]->obj == '1')
				mlx_put_image_to_window(info.mlx,
					info.win, info.img_wal, j * UNI, i * UNI);
			if (m[j][i]->obj == 'C')
				mlx_put_image_to_window(info.mlx,
					info.win, info.img_coin, j * UNI, i * UNI);
			j ++;
		}
		printf ("\n");
		i ++;
	}
	mlx_put_image_to_window(info.mlx, info.win, info.img_exit,
		m_grep(m, info, 'E')->x * UNI, m_grep(m, info, 'E')->y * UNI); //将出口画出来
	return (TRUE);
}

t_bool	dw_bk(t_data info, t_ary m) // 画出地图的背景 墙和出口
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!info.img_bk)
		return (FALSE);
	while (i * UNI < info.win_x)
	{
		j = 0;
		while (j * UNI < info.win_y)
		{
			mlx_put_image_to_window(info.mlx,
				info.win, info.img_bk, i * UNI, j * UNI);
			j ++;
		}
		i ++;
	}
	if (!dw_wall (info, m))
		return (FALSE);
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

t_bool	dw_mov(t_data *i, int x, int y, t_ary m) // 目前没有检测机制 比如地图边缘 和 墙 
{
	if (!dw_bk (*i, m))
		return (FALSE);
	if (!dw_ctr (i, x, y))
		return (FALSE);
	i->n_mov ++;
	return (TRUE);
}
