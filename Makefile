# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: silim <silim@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/30 18:01:17 by silim             #+#    #+#              #
#    Updated: 2021/08/22 17:40:42 by silim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS		=	-Wall -Werror -Wextra

SERVER_SRC	=	minitalk/server.c \
			minitalk/utils.c

CLIENT_SRC	=	minitalk/client.c \
			minitalk/utils.c

BONUS_SERVER_SRC	=	minitalk_bonus/server_bonus.c \
			minitalk_bonus/utils_bonus.c

BONUS_CLIENT_SRC	=	minitalk_bonus/client_bonus.c \
			minitalk_bonus/utils_bonus.c

SERVER_OBJ	=	$(SERVER_SRC:.c=.o)
SERVER		=	server

CLIENT_OBJ	=	$(CLIENT_SRC:.c=.o)
CLIENT		=	client

BONUS_SERVER_OBJ	=	$(BONUS_SERVER_SRC:.c=.o)
BONUS_SERVER		=	bonus_server

BONUS_CLIENT_OBJ	=	$(BONUS_CLIENT_SRC:.c=.o)
BONUS_CLIENT		=	bonus_client

all			:	$(SERVER) $(CLIENT)

bonus		:	$(BONUS_SERVER) $(BONUS_CLIENT)

$(SERVER)	:	$(SERVER_OBJ)
			gcc $(FLAGS) -I. -o $(SERVER) $(SERVER_OBJ)

$(CLIENT)	:	$(CLIENT_OBJ)
			gcc $(FLAGS) -I. -o $(CLIENT) $(CLIENT_OBJ)

$(BONUS_SERVER)	:	$(BONUS_SERVER_OBJ)
			gcc $(FLAGS) -I. -o $(BONUS_SERVER) $(BONUS_SERVER_OBJ)

$(BONUS_CLIENT)	:	$(BONUS_CLIENT_OBJ)
			gcc $(FLAGS) -I. -o $(BONUS_CLIENT) $(BONUS_CLIENT_OBJ)

clean		:
			rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(BONUS_SERVER_OBJ) $(BONUS_CLIENT_OBJ)

fclean		:
			rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(BONUS_SERVER_OBJ) $(BONUS_CLIENT_OBJ)
			rm -f $(SERVER) $(CLIENT) $(BONUS_SERVER) $(BONUS_CLIENT)

re			:	fclean all

bonus_re	:	fclean bonus

.PHONY		:	all clean fclean re
