/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:07:16 by yugao             #+#    #+#             */
/*   Updated: 2024/02/19 22:51:18 by yugao            ###   ########.fr       */
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

static size_t	r_len(char *str)
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
		if (!line)
			break ;
		if (r_len (line) != w)
			e_exit (ERR_NOM);
		h ++;
	}
	info->win_x = w * UNI;
	info->win_y = h * UNI;
	close (fd);
	return (TRUE);
}

