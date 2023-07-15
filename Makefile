# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 20:58:45 by ogregoir          #+#    #+#              #
#    Updated: 2023/02/06 21:19:41 by ogregoir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	pipex.c \
			pipex2.c \

OBJS	=	$(SRCS:.c=.o)

NAME	=	pipex

RM		=	rm -f

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LIBFT	=	libft/libft.a

#-----------------------------------------------#

all	:	$(NAME)

$(NAME)	: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean	:
	$(RM) $(OBJS)
	make clean -C libft

fclean : clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

$(LIBFT) :
	make -C libft

re	: fclean all

