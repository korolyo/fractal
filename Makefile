
NAME	=	fractol

LIST	= 	ft_fractol.c

INC_DIR	=	/includes

OBJS	=	$(patsubst %.c, %.o, $(LIST))

CC		= gcc

CFLAGS	=	-Werror -Wall -Wextra

LIBFT	=	libft/libft.a

all	: runlib	$(NAME)

runlib:
	@make -C libft/

$(NAME): $(LIST)
	$(CC) $(CFLAGS) $(LIBFT) $(LIST) -Lmlx -lmlx -framework OpenGL -framework AppKit -I.$(INC_DIR) -o $(NAME)

clean:
		$(MAKE) clean -C libft/
		@rm -f $(OBJS)

fclean:	clean
		@rm -f $(NAME) $(LIBFT)
		$(MAKE) fclean -C libft/

re:		fclean all

.PHONY:	all clean fclean re
