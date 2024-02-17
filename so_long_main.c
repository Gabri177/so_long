/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:42:17 by yugao             #+#    #+#             */
/*   Updated: 2024/02/17 08:04:29 by yugao            ###   ########.fr       */
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
    char *img_data;
    int bits_per_pixel, size_line, endian;
    int width = 800;
    int height = 600;

    // 初始化MinilibX并创建窗口
    mlx = mlx_init();
    win = mlx_new_window(mlx, width, height, "MinilibX Window");

    // 创建图像
    img = mlx_new_image(mlx, width, height);

    // 获取图像数据地址
    img_data = mlx_get_data_addr(img, &bits_per_pixel, &size_line, &endian);

    // 在这里修改图像数据...
    // 例如：设置图像中心的一个像素为红色
    int x = width / 2;
    int y = height / 2;
    int color = 0xFF0000; // 红色
    *(int*)(img_data + (x + y * size_line / (bits_per_pixel / 8))) = color;

    // 将图像放置到窗口中
    mlx_put_image_to_window(mlx, win, img, 0, 0);

    // 进入事件循环
    mlx_loop(mlx);

    return 0;
}