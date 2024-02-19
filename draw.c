/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 01:06:01 by yugao             #+#    #+#             */
/*   Updated: 2024/02/19 01:32:24 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	dw_bk(void *mlx, void *win, int len, int wid)
{
	int		i;
	int		j;
	int		h;
	int		w;
	void	*img;

	i = 0;
	j = 0;
	h = 50;
	w = 50;
	img = mlx_xpm_file_to_image (mlx, IMAG_BK, &h, &w);
	if (!img)
		return (FALSE);
	while (i < len)
	{
		j = 0;
		while (j < wid)
		{
			mlx_put_image_to_window(mlx, win, img, i * UNIDAD, j * UNIDAD);
			j ++;
		}
		i ++;
	}
	mlx_destroy_image (mlx, img);
	return (TRUE);
}
