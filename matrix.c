#include "so_long.h"

t_bool	l_init(t_ary *l, t_data info)
{
	int	i;
	int	j;

	i = 0;
	*l = (t_node***) malloc (sizeof (t_node**) * info.win_x);
	if (!*l)
		return (FALSE);
	while (i < info.win_x)
	{
		(*l)[i] = (t_node**) malloc (sizeof (t_node*) * info.win_y);
		if (!(*l)[i])
			return (FALSE);
		j = 0;
		while (j < info.win_y)
		{
			(*l)[i][j] = (t_node*) malloc (sizeof (t_node));
			if (!*l[i][j])
				return (FALSE);
			(*l)[i][j]->stp = 0;
			j ++;
		}
		i ++;
	}
	return (TRUE);
}

void	l_print(t_ary l, t_data info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info.win_x)
	{
		j = 0;
		while (j < info.win_y)
		{
			printf ("  %d", l[i][j]->stp);
			j ++;
		}
		printf ("\n");
		i ++;
	}
}

int	main(void)
{
	t_ary	l;
	t_data	test;
	int	a;

	test.win_x = 3;
	test.win_y = 8;
	a = l_init (&l, test);
	printf ("%d\n", a);
	//l_print (l, test);
	return (0);
}