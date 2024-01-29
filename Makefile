# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 13:15:36 by eewu              #+#    #+#              #
#    Updated: 2024/01/29 16:24:40 by eewu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub

INCLS			= 	include/*.h

SRC				=	$(addprefix $(OBJDIR)/, 	\
					src/utils/cub3d.c			\
					src/utils/cub3d_utils_1.c	\
					src/utils/cub3d_utils_2.c	\
					src/utils/get_next_line.c	\
					src/utils/cub3d_split.c		\
					src/utils/cub3d_lst.c		\
					src/utils/cub3d_free.c		\
					src/utils/ft_strdup.c 		\
					src/utils/cub3d_init.c		\
					src/utils/cub3d_keypress.c	\
					src/utils/cub3d_display.c	\
					src/utils/cub3d_ray.c		\
					src/check_file.c			\
					src/check_textures.c 		\
					src/check_color.c 			\
					src/check_must.c			\
					src/check_walls.c 			\
					src/backtracking.c			\
					src/main.c					\
					src/check_map.c)


OBJ				= 	$(SRC:.c=.o)

OBJDIR			= 	obj

CC				= 	cc

FLAGS			= 	-Wall -Wextra -Werror -g

LIB				=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm

RM				= 	rm -rf

# all				: 	$(NAME)

all				: 	lib
					@make $(NAME) --no-print-directory

lib			 	:
					@make -s -C mlx_linux/ --no-print-directory				

$(NAME) 		: 	$(OBJ) $(INCLS)
				  	$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

$(OBJDIR)/%.o : %.c
					@mkdir -p $(@D)
					$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c -o $@ $^

clean			:
		 			$(RM) $(OBJ) $(OBJDIR)
					@make clean -s -C mlx_linux/ --no-print-directory
					

fclean			:	clean
					$(RM) $(NAME)

re				:	fclean
					make all

.PHONY			: 	all clean re