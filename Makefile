# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbouzalm <tbouzalm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 17:15:37 by tbouzalm          #+#    #+#              #
#    Updated: 2022/04/29 17:24:10 by tbouzalm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = so_long
BNS		= so_long_bonus
CC      = gcc  
CFLAGS  = -Wall -Wextra -Werror -Imlx


HEAD    = so_long.h

HEAD_BNS = so_long_bonus.h		

Imlx = -lmlx -framework OpenGL -framework AppKit

SRC = so_long.c utils.c get_next_line.c get_next_line_utils.c ft_check_map.c check_map2.c button.c affichage.c

SRC_BONUS = so_long_bonus.c utils_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c ft_check_map_bonus.c  \
			affichage_bonus.c button_bonus.c check_map2_bonus.c ft_itoa.c les_erreurs.c free.c

OBJS    = ${SRC:.c=.o}

OBJSB = ${SRC_BONUS:.c=.o}

all: $(NAME) $(HEAD)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(BNS) $(HEAD_BNS)

$(BNS) : $(OBJSB)
		$(CC) $(CFLAGS) $(OBJSB) $(Imlx) -o $(BNS)
		
$(OBJS): $(HEAD)

$(OBJSB): $(HEAD_BNS)

clean:
	rm -f $(OBJS) $(OBJSB)

fclean: clean
		rm -f $(NAME) $(BNS)

re: fclean all