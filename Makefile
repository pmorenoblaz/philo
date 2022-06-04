# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 12:55:30 by pmoreno-          #+#    #+#              #
#    Updated: 2022/06/04 15:58:49 by pmoreno-         ###   ########.fr        #
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

SRCS	= main.c
			
OBJS	= $(SRCS:.c=.o)

NAME	= philo

CFLAGS	= -Wall -Werror -Wextra 

GCC	= gcc

RM	= rm -f

all:		$(NAME)

.c.o:
	$(GCC) $(CFLAGS) -c $< -o $@ 

$(NAME):	$(OBJS)
	@make -C $(LIBFT_PATH) --silent
	$(CC) -o $(NAME) $(OBJS) -o $(NAME) -lpthread

clean:		
	$(RM) $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re 