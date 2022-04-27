NAME	= libftprintf.a
LIB		= ./libft
SRCS	= srcs/ft_printf.c formatting/ft_printf_char.c formatting/ft_printf_int.c 
OBJS	= $(SRCS:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -rf

all		: ${NAME}

$(NAME)	: ${OBJS}
		make re -C ${LIB}
		ar rcs ${NAME} ${OBJS} ${LIB}/*.o

%.o : %.c
			@echo "Creating Objects..."
			$(CC) $(CFLAGS) -c $< -o $@

clean	:
			@echo "Cleaning binary files..."
			make clean -C ${LIB}
			${RM} ${OBJS}

fclean	: clean
		@echo "Removing Library..."
		make fclean -C ${LIB}
		${RM} ${NAME}

re		: fclean all

.PHONY: all clean fclean re
