/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:42:17 by yugao             #+#    #+#             */
/*   Updated: 2024/02/17 07:24:46 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*wdo;

	wdo = mlx_init();
	mlx_new_window (wdo, 300, 300, "Hello world!");
	mlx_loop (wdo);
	return (0);
}
