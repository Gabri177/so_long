/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:42:17 by yugao             #+#    #+#             */
/*   Updated: 2024/02/17 08:11:17 by yugao            ###   ########.fr       */
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

#include <mlx.h>

int main(void)
{
    void *mlx;
    void *win;
    void *img;
    int img_width, img_height;

    // 初始化MinilibX并创建窗口
    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "MinilibX Window");

    // 加载图片
    // 确保图片路径正确，且图片格式为XPM
    img = mlx_xpm_file_to_image(mlx, "path/to/your/image.xpm", &img_width, &img_height);

    // 如果加载成功，将图片放置到窗口中
    if (img != NULL) {
        mlx_put_image_to_window(mlx, win, img, 0, 0);
    }

    // 进入事件循环
    mlx_loop(mlx);

    return 0;
}
