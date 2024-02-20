/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:39:58 by yugao             #+#    #+#             */
/*   Updated: 2024/02/20 02:58:50 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>

# include "./minilibx/mlx.h"
# include "./libft/libft.h"

# define TRUE 1
# define FALSE 0

# define IMAG_WAL "./img/wall.xpm"
# define IMAG_CTR "./img/person.xpm"
# define IMAG_BK "./img/bk.xpm"
# define IMAG_EXIT "./img/sale.xpm"
# define IMAG_COIN "./img/coin.xpm"

# define ERR_IMG 1
# define ERR_FIL 2
# define ERR_ARG 3
# define ERR_RED 4
# define ERR_NOM 5
# define ERR_MAP 6
# define ERR_MEM 7

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
	void	*img_exit;
	void	*img_coin;
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

typedef struct s_pos
{
	int	x;
	int	y;
}					t_pos;

//--------draw---------
t_bool	dw_bk(t_data info, t_ary m);
t_bool	dw_ctr(t_data *info, int x, int y);
t_bool	dw_mov(t_data *i, int x, int y, t_ary m);

//--------matrix-------
t_bool	m_init(t_ary *l, t_data info);
void	m_print(t_ary l, t_data info, t_bool is_obj);
t_bool	m_clr(t_ary *m, t_data info);
t_bool	m_check(t_ary m, t_data *info);
t_pos	*m_grep(t_ary m, t_data info, char c);
//--------error_control-----------
void	e_exit(int tp);

//--------read_file---------------
int		r_fd(char *dir);
t_bool	r_size(t_data *info, int fd);
t_bool	r_to_mrx(t_data *info, int fd, t_ary *m);

//--------main---------
void	info_init(t_data *info);
#endif