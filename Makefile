NAME = Cub3d

		#COMMAND#

CC				= cc
MKDIR			= mkdir -p
RM				= rm -rf

		#SOURCES#./	

C_DIR			= src
C_FILES			= check_file.c check_must.c
					
# C_FILES_BONUS	= 

SRCS			= $(patsubst %, $(C_DIR)/%, $(C_FILES))
# SRCS_BONUS		= $(patsubst %, $(C_DIR)/%, $(C_FILES_BONUS))

		#OBJECTS#

O_DIR			= objs
O_FILES			= $(C_FILES:.c=.o)
# O_FILES_BONUS	= $(C_FILES_BONUS:.c=.o)
OBJS			= $(patsubst %, $(O_DIR)/%, $(O_FILES))
# OBJS_BONUS		= $(patsubst %, $(O_DIR)/%, $(O_FILES_BONUS))

		#FLAGS#

FLAGS			= -Wall -Wextra -g3 -MMD

ifeq ($(debug), true)
	FLAGS += -fsanitize=address,undefined -g3
endif

# MFLAGS			= -lXext -lX11

		#INCLUDES#

INCLUDES		= -I ./libft -I ./include
LIBFTPRINTF			= ./Ft_printf/libftprintf.a
# MLX				= ./minilibx-linux/libmlx.a ./minilibx-linux/libmlx_Linux.a

		#RULES#

all: ${NAME}

$(O_DIR):
				$(MKDIR) $(O_DIR)

$(O_DIR)/%.o: $(C_DIR)/%.c
				$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(LIBFTPRINTF):
				make -C ./Ft_printf all

# $(MLX):
#make -C ./minilibx-linux all

$(NAME): $(O_DIR) $(OBJS) $(LIBFTPRINTF) #$(MLX)
				$(CC) $(OBJS) $(FLAGS) $(MFLAGS) $(LIBFTPRINTF) -o $@ 
#$(MLX) 

# bonus: $(O_DIR) $(OBJS_BONUS) $(LIBFTPRINTF) $(MLX)
# $(CC) $(OBJS_BONUS) $(FLAGS) $(MFLAGS) $(LIBFTPRINTF) $(MLX) -o $@

clean :
				make -C ./Ft_printf clean
				$(RM) $(O_DIR)
# make -C ./minilibx-linux clean

fclean :
				$(RM) $(O_DIR)
				make -C ./Ft_printf fclean
				$(RM) $(NAME)
# $(RM) bonus
#make -C ./minilibx-linux clean

re : fclean all

.PHONY: all clean fclean re 