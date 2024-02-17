# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 21:42:20 by yugao             #+#    #+#              #
#    Updated: 2024/02/17 08:05:43 by yugao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILE = so_long_main.c
OFILE = $(CFILE:.c=.o)
CFLAG = -Wall -Wextra -Werror
LDFLAGS = -framework OpenGL -framework AppKit
LIBS = -L minilibx_opengl_20191021 -lmlx
NAME = so_long

all:mlx $(NAME)

$(NAME):$(OFILE)
#gcc $(CFLAG) $(MCFLAG) -o $@ $(OFILE)
	gcc $(OFILE) $(LIBS) $(LDFLAGS) -o $@

%.o:%.c
	gcc $(CFLAG) -c -Imlx $< -o $@

mlx:
	$(MAKE) -C minilibx_opengl_20191021

clean:
	rm -f $(OFILE)
	$(MAKE) clean -C minilibx_opengl_20191021

fclean: clean
	rm -f $(NAME)

re:fclean all

.PHONY: fclean clean 	