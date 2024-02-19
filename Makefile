# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/16 21:42:20 by yugao             #+#    #+#              #
#    Updated: 2024/02/19 20:04:08 by yugao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILE = so_long_main.c draw.c matrix.c
OFILE = $(CFILE:.c=.o)
CFLAG = -Wall -Wextra -Werror
LDFLAGS = -framework OpenGL -framework AppKit
LIBS = -L minilibx -lmlx
NAME = so_long

all:mlx $(NAME)

$(NAME):$(OFILE)
	gcc $(OFILE) $(LIBS) $(LDFLAGS) -o $@

%.o:%.c
	gcc $(CFLAG) -c -Imlx $< -o $@

mlx:
	$(MAKE) -C libft

clean:
	rm -f $(OFILE)
	$(MAKE) fclean -C libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) clean -C libft

re:fclean all

.PHONY: fclean clean 	