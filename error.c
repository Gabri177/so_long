/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:24:36 by yugao             #+#    #+#             */
/*   Updated: 2024/02/20 02:26:53 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	e_exit(int tp)
{
	if (tp == ERR_IMG)
		perror ("Error: Load IMG error!\n");
	else if (tp == ERR_FIL)
		perror ("Error: Please cheack if exist the file! \n");
	else if (tp == ERR_ARG)
		perror ("Error: You have passed an argument invalid!\n");
	else if (tp == ERR_RED)
		perror ("Error:Sorry, Read file failed! \n");
	else if (tp == ERR_NOM)
		perror ("Error: The map is nos a square!\n");
	else if (tp == ERR_MAP)
		perror ("Error: The map is ilegal!\n");
	else if (tp == ERR_MEM)
		perror ("Error: Malloc unsuccessfully!\n");
	exit (1);
}
