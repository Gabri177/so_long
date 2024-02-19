/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:42:17 by yugao             #+#    #+#             */
/*   Updated: 2024/02/19 01:33:27 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*win;
	int		len;
	int		high;

	len = 10;
	high = 3;
	mlx = mlx_init();
	win = mlx_new_window(mlx, len * UNIDAD, high * UNIDAD, "MinilibX Window");
	dw_bk (mlx, win, len, high);
	mlx_loop(mlx);
	return (0);
}
