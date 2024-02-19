/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:42:17 by yugao             #+#    #+#             */
/*   Updated: 2024/02/20 00:53:33 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//info_init使用前必须运行r_size使得窗口大小能够更新到info变量中 否则会出错
void	info_init(t_data *info)
{
	info->mlx = mlx_init();
	//info->win_x = wx * UNI;
	//info->win_y = wy * UNI;
	info->win = mlx_new_window(info->mlx, info->win_x,
			info->win_y, "MinilibX Window");
	info->ctr_x = 0;
	info->ctr_y = 0;
	info->img_x = 50;
	info->img_y = 50;
	info->img_bk = mlx_xpm_file_to_image (info->mlx,
			IMAG_BK, &info->img_x, &info->img_y);
	info->img_ctr = mlx_xpm_file_to_image (info->mlx,
			IMAG_CTR, &info->img_x, &info->img_y);
	info->img_wal = mlx_xpm_file_to_image (info->mlx,
			IMAG_WAL, &info->img_x, &info->img_y);
	if (!info->img_bk || !info->img_ctr || !info->img_wal)
	{
		perror("Error: xpm no abre");
		exit (0);
	}
	info->n_mov = 0;
}

int	main(void)
{
	t_data	info;
	t_ary	mrx;
	char	dir[] = "./maps/map2.ber";

	r_size (&info, r_fd (dir)); //获取窗口大小将窗口大小数据更新到info中  先检查这玩意是不是方的
	info_init (&info); // 初始化info变量中的其他内容
	m_init (&mrx, info); // 创建一个横纵坐标的二位nodo的变量
	r_to_mrx (info, r_fd (dir), &mrx);
	m_print (mrx, info, TRUE);
	dw_bk (info); // 画背景, 里面自动换算长度和位置 就是已经和UNIDAD进行过运算了;
	//mlx_loop_hook(info.mlx, (int (*)())timer_handler, &info);
	dw_mov(&info, 0, 1);
	//dw_mov(&info, 1, 1);
	/* for (int i = 0; i < 6; i++)
	{
	 	usleep (1000000);
	 	dw_mov(&info, 0, i);
	 	mlx_loop (info.mlx);
	 	//mlx_do_sync (info.mlx);
	 	if (i == 5)
	 		i = 0;
	} */
	m_clr (&mrx, info);
	mlx_loop (info.mlx);
	
	return (0);
}
