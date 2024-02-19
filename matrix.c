/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:15:03 by yugao             #+#    #+#             */
/*   Updated: 2024/02/20 00:52:39 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	m_init(t_ary *l, t_data info)
{
	int	i;
	int	j;

	i = 0;
	*l = (t_node ***) malloc (sizeof (t_node **) * info.win_x / UNI);
	if (!(*l))
		return (FALSE);
	while (i < info.win_x / UNI)
	{
		(*l)[i] = (t_node **) malloc (sizeof (t_node *) * info.win_y / UNI);
		if (!(*l)[i])
			return (FALSE);
		j = 0;
		while (j < info.win_y / UNI)
		{
			(*l)[i][j] = (t_node *) malloc (sizeof (t_node));
			if (!(*l)[i][j])
				return (FALSE);
			(*l)[i][j]->stp = 0;
			j ++;
		}
		i ++;
	}
	return (TRUE);
}

void	m_print(t_ary l, t_data info, t_bool is_obj)
{
	int	i;
	int	j;

	i = 0;
	while (i < info.win_y / UNI)
	{
		j = 0;
		while (j < info.win_x / UNI)
		{
			if (is_obj)
				printf ("   %c", l[j][i]->obj);
			else
				printf ("   %d", l[j][i]->stp);
			j ++;
		}
		printf ("\n");
		i ++;
	}
}

t_bool	m_clr(t_ary *m, t_data info)
{
	int	i;
	int	j;

	i = 0;
	if (!m)
		return (FALSE);
	while (i < info.win_x / UNI)
	{
		j = 0;
		while (j < info.win_y / UNI)
		{
			free ((*m)[i][j]);
			j ++;
		}
		i ++;
	}
	i = 0;
	while (i < info.win_x / UNI)
	{
		free ((*m)[i]);
		i ++;
	}
	free (*m);
	return (TRUE);
}

/* int	main(void)
{
	t_ary	l;
	t_data	test;
	int		a;

	test.win_x = 3;
	test.win_y = 8;
	m_init (&l, test);
	m_clr (&l, test);
	//m_print (l, test);
	
	return (0);
} */