CC 		=	cc
CFLAGS	=	-Wall -Wextra -Werror
MFLAGS	=	-framework OpenGL -framework Appkit

NAME	= 	so_long
NAME_B	=	so_long_bonus

MLX_DIR	=	./mlx
MLX		=	mlx

INC_DIR	=	-I./inc

INC		=	$(INC_DIR)/so_long.h \
			$(INC_DIR)/get_next_line.h
SRC		=	src/main.c \
            src/read_map.c \
            src/check_map.c \
            src/init.c \
            src/draw_map.c \
            src/key.c \
            src/get_next_line.c \
            src/get_next_line_utils.c

INC_B	=	$(INC_DIR)/so_long_bonus.h \
			$(INC_DIR)/get_next_line_bonus.h
SRC_B	=	src/main_bonus.c \
            src/read_map_bonus.c \
            src/check_map_bonus.c \
            src/init_bonus.c \
            src/draw_map_bonus.c \
            src/key_bonus.c \
            src/enemy_bonus.c \
            src/get_next_line_bonus.c \
            src/get_next_line_utils_bonus.c

OBJ		=	$(SRC:%.c=%.o)
OBJ_B	=	$(SRC_B:%.c=%.o)
RM		=	rm -f

all		:	$(NAME)

bonus	:	$(NAME_B)

%.o : %.c
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

$(NAME)	:	$(OBJ)
	$(CC) $(CFLAGS) -L$(MLX_DIR) -l$(MLX) $(MFLAGS) -o $@ $(OBJ)


$(NAME_B)	:	$(OBJ_B)
	$(CC) $(CFLAGS) -L$(MLX_DIR) -l$(MLX) $(MFLAGS) -o $@ $(OBJ_B)

clean	:
	$(RM) $(OBJ) $(OBJ_B)

fclean	: clean
	$(RM) $(NAME) $(NAME_B)

re : fclean all

.PHONY : all clean fclean re