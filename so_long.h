/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:39:58 by yugao             #+#    #+#             */
/*   Updated: 2024/02/19 01:20:47 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include "./minilibx/mlx.h"

# define TRUE 1
# define FALSE 0

# define IMAG_WALL "./img/wall.xpm"
# define IMAG_CARACTER "./img/person.xpm"
# define IMAG_BK "./img/bk.xpm"

# define UNIDAD 50

typedef int	t_bool;

t_bool	dw_bk(void *mlx, void *win, int len, int wid);

#endif