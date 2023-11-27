# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 16:45:45 by grebrune          #+#    #+#              #
#    Updated: 2023/11/27 15:00:51 by grebrune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		:=	ft_printf.c\
				ft_printf_utils.c\
				ft_putnbr_base.c\

SRCS_D		:=	src/

OBJS_D		:=	objs/

OBJS		:=	$(SRCS:%.c=$(OBJS_D)%.o)

#OBJS_B		:=	$(SRC_B:%.c=$(OBJS_D)%.o)

HEAD		:=	ft_printf.h

HEAD_D		:=	head/

CFLAGS		:=	-Wall -Wextra -Werror -g3

CC			:=	cc

NAME		:=	libftprintf.a

all			:	$(NAME)


$(NAME)		:	$(OBJS_D) $(OBJS) Makefile
				$(CC) $(CLFAGS) -o $(NAME) $(OBJS)

$(OBJS)		:	$(OBJS_D)%.o: $(SRCS_D)%.c $(HEAD_D)
				$(CC) $(CFLAGS) -I$(HEAD_D) -c $< -o $@

$(OBJS_D)	:
				@mkdir -p $(OBJS_D)

clean		:
				$(RM) -r $(OBJS) $(OBJS_D) $(OBJS_B)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all


.PHONY: all bonus clean fclean re
