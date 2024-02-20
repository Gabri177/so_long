/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 01:06:01 by yugao             #+#    #+#             */
/*   Updated: 2024/02/20 20:43:58 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	dw_wall(t_data info, t_ary m) //这里进行墙的绘制出口 和 金币的绘制 都是对matrix进行遍历, 然后进行绘画;
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
					info.win, info.img_wal, j * UNI, i * UNI); //墙
			if (m[j][i]->obj == 'C')
				mlx_put_image_to_window(info.mlx,
					info.win, info.img_coin, j * UNI, i * UNI); //金币
			j ++;
		}
		i ++;
	}
	mlx_put_image_to_window(info.mlx, info.win, info.img_exit,
		m_grep(m, info, 'E')->x * UNI, m_grep(m, info, 'E')->y * UNI); //将出口画出来
	return (TRUE);
}

t_bool	dw_bk(t_data info, t_ary m) // 画出地图的背景 墙和出口和金币
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

t_bool	dw_ctr(t_data *info, int x, int y) //在指定位置绘制出人物
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

// 判断能否移动 参数是下一个想要到达的位置
t_bool	dw_canmov(t_data *i, t_ary m, int x, int y)
{
	if (m[x][y]->obj == '0' || m[x][y]->obj == 'C' || m[x][y]->obj == 'P') // 如果是小人位置 金币位置 空位置 可以以移动
		return (TRUE);
	if (!m_grep(m, *i, 'C') && m[x][y]->obj == 'E') // 如果金币吃光了 可以移动到出口
		return (TRUE);
	return (FALSE);
}

t_bool	dw_mov(t_data *i, int x, int y, t_ary *m) // 目前没有检测机制 比如地图边缘 和 墙 
{
	if (!dw_canmov (i, *m, x, y))
		return (FALSE);
	if ((*m)[x][y]->obj == 'C') // 当遇到金币 上面的判断条件显示可以移动 那我们就将金币换成空白
		(*m)[x][y]->obj = '0';
	if (!dw_bk (*i, *m))
		return (FALSE);
	if (!dw_ctr (i, x, y))
		return (FALSE);
	i->n_mov ++;
	printf("move: %d \n", i->n_mov);
	return (TRUE);
}

