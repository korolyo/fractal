
NAME	=	fractol

SOURCES_LIST	= 	main.c\
					draw.c\
					init_hooks.c\
					fractals.c

CC		= gcc
CFLAGS	=	-Werror -Wall -Wextra
LIBRARIES = -lmlx -lm -lft\
	-L$(LIBFT_DIRECTORY) -L$(MINILIBX_DIRECTORY)\
	-Wno-deprecated-declarations\
	-framework OpenGL -framework AppKit
INCLUDES = -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS) -I$(HEADERS_DIR)

HEADERS_LIST = \
	ft_fractol.h
HEADERS_DIR	=	./includes/
HEADERS =	$(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

LIBFT	=	$(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/

MINILIBX =	$(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_DIRECTORY = ./minilibx_opengl/
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

OBJECTS	=	$(patsubst %.c, %.o, $(SOURCES_LIST))

.PHONY:	all clean fclean re

all	: 	$(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJECTS)
		@$(CC) $(CFLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
		@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(MINILIBX):
		@$(MAKE) -sC $(MINILIBX_DIRECTORY)

clean:
		@$(MAKE) clean -sC $(LIBFT_DIRECTORY)
		@$(MAKE) clean -sC $(MINILIBX_DIRECTORY)
		@rm -f $(OBJECTS)

fclean:	clean
		@rm -f $(NAME)
		@rm -f $(LIBFT)
		@rm -f $(MINILIBX)

re:		fclean all
