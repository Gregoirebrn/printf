# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grebrune <grebrune@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 16:45:45 by grebrune          #+#    #+#              #
#    Updated: 2023/11/15 19:59:24 by grebrune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		:=	\



SRCS_D		:=	#

OBJS_D		:=	objs/

OBJS		:=	$(SRCS:%.c=$(OBJS_D)%.o)

#OBJS_B		:=	$(SRC_B:%.c=$(OBJS_D)%.o)

HEAD		:=	get_next_line.h

HEAD_D		:=	.

CFLAGS		:=	-Wall -Wextra -Werror -g3

CC			:=	cc

NAME		:=	get_next_line

all			:	$(NAME)


$(NAME)		:	$(OBJS_D) $(OBJS) Makefile
				$(CC) $(CLFAGS) -o $(NAME) $(OBJS)

$(OBJS)		:	$(OBJS_D)%.o: $(SRCS_D)%.c $(HEAD)
				$(CC) $(CFLAGS) -I$(HEAD_D) -c $< -o $@

$(OBJS_D)	:
				@mkdir -p $(OBJS_D)

clean		:
				$(RM) -r $(OBJS) $(OBJS_D) $(OBJS_B)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all


.PHONY: all bonus clean fclean re
