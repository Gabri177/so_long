# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 21:42:20 by yugao             #+#    #+#              #
#    Updated: 2024/02/16 21:45:28 by yugao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILE = so_long_main.c
OFILE = $(CFILE: .c=.o)
FLAG = -Wall -Wextra -Werror