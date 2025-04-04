# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qliso <qliso@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/04 18:21:39 by qliso             #+#    #+#              #
#    Updated: 2025/04/04 19:11:00 by qliso            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
NAME	=	cpp06_ex01

SRCS	=	$(addsuffix .cpp, \
			main \
			Serializer \
			)

HEADERS	=	$(addsuffix .hpp, \
			\
			)

OBJS_PATH	=	.objs/

OBJS	=	$(SRCS:%.c=$(OBJS_PATH)%.o)

CC			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98
RM			=	rm -rf

# RULES
all:	$(OBJS_PATH) $(NAME) 

$(NAME):	$(OBJS)
			$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
			@echo "\033[1;32m$(NAME) compiled !\033[0m"

$(OBJS_PATH)%.o:	$(SRCS)%.c $(HEADERS) | $(OBJS_PATH)
					$(CC) $(CPPFLAGS) -c $< -o $@

$(OBJS_PATH):
			@mkdir -p $(OBJS_PATH)

clean:
		$(RM) $(OBJS_PATH)
		@echo "\033[1;31mObject files deleted !\033[0m"

fclean:	clean
		$(RM) $(NAME)
		@echo "\033[1;31m$(NAME) deleted !\033[0m"
		
re:	fclean all

.PHONY:	all clean fclean re