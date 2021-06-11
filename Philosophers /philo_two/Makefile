NAME	=	philo_two

SRCS	:=	$(addprefix srcs/,\
			control.c\
			eat.c\
			ft_atoi.c\
			ft_eror.c\
			ft_valid.c\
			get_time.c\
			init.c\
			main.c\
			print.c)

INC_D	:=	includes/

ALLOBJS	=	${SRCS}

CC		=	gcc -Wall -Wextra -Werror -I include -I includes

all		:	$(NAME)

$(NAME)	:	${ALLOBJS} ${INC_D}
			$(CC) -o ${NAME} ${ALLOBJS} 
clean:


fclean:		clean
			rm -f ${NAME}
re:			fclean all

.PHONY:		all clean fclean re