/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:42:17 by yugao             #+#    #+#             */
/*   Updated: 2024/02/19 00:11:12 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	main(void)
// {
// 	void	*mlx;
// 	void	*img;
// 	t_data	test;

// 	mlx = mlx_init();
// 	mlx_new_window (mlx, 300, 300, "Hello world!");
// 	mlx_loop (mlx);
// 	return (0);
// }


int main(void)
{
    void *mlx;
    void *win;
    void *img;
	int  width = 100;
	int  height = 100; 

    // 初始化MinilibX并创建窗口
    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "MinilibX Window");

    // 加载图片
    // 确保图片路径正确，且图片格式为XPM
    img = mlx_xpm_file_to_image(mlx, "/Users/yugao/Desktop/download.xpm", &width, &height);

    // 如果加载成功，将图片放置到窗口中
    if (img != NULL) {
        mlx_put_image_to_window(mlx, win, img, 700, 500);
    }

    // 进入事件循环
    mlx_loop(mlx);

    return 0;
}
