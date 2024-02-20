/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:07:16 by yugao             #+#    #+#             */
/*   Updated: 2024/02/20 12:36:11 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	r_fd(char *dir)
{
	int	fd;

	fd = open (dir, O_RDONLY);
	if (fd < 0)
		e_exit(ERR_FIL);
	return (fd);
}

static size_t	r_len(char *str) // +++++++加一个字符判定
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (ft_strlen (str) - 1);
		i ++;
	}
	return (ft_strlen (str));
}

t_bool	r_size(t_data *info, int fd)
{
	static size_t		w;
	static size_t		h;
	char				*line;

	line = get_next_line (fd);
	if (!line)
		e_exit (ERR_RED);
	w = r_len (line);
	h ++;
	while (line)
	{
		line = get_next_line (fd);
		if (!line || *line == '\n')
			break ;
		if (r_len (line) != w)
			e_exit (ERR_NOM);
		free (line);
		h ++;
	}
	info->win_x = w * UNI;
	info->win_y = h * UNI;
	close (fd);
	return (TRUE);
}

t_bool	r_to_mrx(t_data *info, int fd, t_ary *m)
{
	int		x;
	int		y;
	char	*line;

	y = 0;
	while (y < info->win_y / UNI)
	{
		line = get_next_line (fd);
		if (!line)
			e_exit (ERR_RED);
		x = 0;
		while (x < info->win_x / UNI)
		{
			(*m)[x][y]->obj = line[x];
			x ++;
		}
		free (line);
		y ++;
	}
	close (fd);
	m_check (*m, info); // 这里我们检查 四个边是不是都是1 以及是否存在出口和角色 这里也给初始人物位置赋值
	m_can_out (m, info->ctr_x, info->ctr_y);
	m_check_out (*m, *info);
	return (TRUE);
}
