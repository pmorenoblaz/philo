# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 12:55:30 by pmoreno-          #+#    #+#              #
#    Updated: 2022/08/20 18:07:18 by pmoreno-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED		= '\033[31m'
GREEN	= '\033[1;32m'
YELLOW	= '\033[33m'
BLUE	= '\033[34m'
PURPLE	= '\033[1;35m'
CIAN	= '\033[36m'
WHITE	= '\033[37m'
NONE	= '\033[0m'

SRCS	= main.c ft_atoi.c ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_strdup.c ft_strlcpy.c ft_strlen.c add_values.c \
			time_values.c list_functions.c philos.c print.c routine.c threads.c \
			free_functions.c checker.c forks.c
			
OBJS	= $(SRCS:.c=.o)

NAME	= philo

CFLAGS	= -Wall -Werror -Wextra -g

GCC	= gcc

RM	= rm -f

all:		$(NAME)

.c.o:
	$(GCC) $(CFLAGS) -c $< -o $@ 

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) -o $(NAME) -lpthread  -fsanitize=thread

clean:		
	$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re 