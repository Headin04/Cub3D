# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 13:15:36 by eewu              #+#    #+#              #
#    Updated: 2024/01/15 13:22:11 by eewu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub

SRC				=	$(addprefix $(OBJDIR)/, 	\
					src/utils/cub3d.c			\
					src/utils/cub3d_utils_1.c	\
					src/utils/cub3d_utils_2.c	\
					src/utils/get_next_line.c	\
					src/utils/cub3d_split.c		\
					src/utils/cub3d_lst.c		\
					src/utils/cub3d_free.c		\
					src/utils/ft_strdup.c 		\
					src/check_file.c			\
					src/check_must.c)

INCLS			= 	include/*.h

OBJ				= 	$(SRC:.c=.o)

OBJDIR			= 	obj

CC				= 	cc

FLAGS			= 	-Wall -Wextra -Werror

LIB				=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -o 

RM				= 	rm -rf

# all				: 	$(NAME)

all				: 	lib
					@make $(NAME) --no-print-directory

lib			 	:
					@make -s -C mlx_linux/ --no-print-directory				

$(NAME) 		: 	$(OBJ) $(INCLS)
				  	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o : %.c
					@mkdir -p $(@D)
					$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c -o $@ $^

clean			:
		 			$(RM) $(OBJ) $(OBJDIR)
					@make clean -s -C mlx_linux/ --no-print-directory
					

fclean			:	clean
					$(RM) $(NAME)

re				:	clean
					make all

.PHONY			: 	all clean re