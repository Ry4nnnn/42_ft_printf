NAME	= libftprintf.a

LIB		= libft

SRCS	= srcs/ft_printf.c formatting/ft_printf_char.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

RM		= rm -rf

all		: ${NAME}

$(NAME)	: ${OBJS}
		make all -C ${LIB}
		@echo "Making library..."
		@ar rcs ${NAME} ${OBJS} ${LIB}/*.o

%.o : %.c
			@echo "Creating Objects..."
			$(CC) $(CFLAGS) -c $< 

clean	:
			@echo "Cleaning binary files..."
			@rm -f ${OBJS}

fclean	: clean
		@echo "Removing Library..."
		@rm -rf ${NAME}
		make fclean -C ${LIB}

re		: fclean all