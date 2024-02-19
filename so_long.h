/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:39:58 by yugao             #+#    #+#             */
/*   Updated: 2024/02/19 20:03:01 by yugao            ###   ########.fr       */
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
# include "./libft/libft.h"

# define TRUE 1
# define FALSE 0

# define IMAG_WAL "./img/wall.xpm"
# define IMAG_CTR "./img/person.xpm"
# define IMAG_BK "./img/bk.xpm"

# define UNI 50

typedef int			t_bool;
typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		img_x;
	int		img_y;
	int		win_x;
	int		win_y;
	void	*img_ctr;
	void	*img_wal;
	void	*img_bk;
	int		ctr_x;
	int		ctr_y;
	int		n_mov;
}					t_data;

typedef struct s_node
{
	char			obj;
	int				stp;
}					t_node;

typedef t_node***	t_ary;

t_bool	dw_bk(t_data info);
t_bool	dw_ctr(t_data *info, int x, int y);
t_bool	dw_mov(t_data *i, int x, int y);


t_bool	m_init(t_ary *l, t_data info);
void	m_print(t_ary l, t_data info);
t_bool	m_clr(t_ary *m, t_data info);
#endif