/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:42:17 by yugao             #+#    #+#             */
/*   Updated: 2024/02/19 19:57:54 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	info_init(t_data *info, int wx, int wy)
{
	info->mlx = mlx_init();
	info->win_x = wx * UNI;
	info->win_y = wy * UNI;
	info->win = mlx_new_window(info->mlx, wx * UNI,
			wy * UNI, "MinilibX Window");
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

// int	timer_handler(t_data *info)
// {
// 	int	g_i = 0;
	
// 	dw_mov(info, 1, g_i); // 更新窗口内容
// 	g_i++;
// 	if (g_i > 6)
// 		g_i = 0;
// 	return (0);
// }

int	main(void)
{
	t_data	info;

	info_init (&info, 5, 6);
	dw_bk (info); // 画背景, 里面自动换算长度和位置 就是已经和UNIDAD进行过运算了;
	//mlx_loop_hook(info.mlx, (int (*)())timer_handler, &info);
	
	dw_mov(&info, 0, 1);
	/* for (int i = 0; i < 6; i++)
	{
	 	usleep (1000000);
	 	dw_mov(&info, 0, i);
	 	mlx_loop (info.mlx);
	 	//mlx_do_sync (info.mlx);
	 	if (i == 5)
	 		i = 0;
	} */
	mlx_loop (info.mlx);
	dw_ctr (&info, 1, 1);
	return (0);
}
