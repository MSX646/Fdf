# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kezekiel <kezekiel@student.21-schoo>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 18:06:13 by kezekiel          #+#    #+#              #
#    Updated: 2022/02/11 18:06:14 by kezekiel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf

AR= ar rc
RM= rm -rf

CC= gcc
CFLAGS= -Wall -Werror -Wextra -c 
MFLAGS=  -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz
INC=	fdf.h

ODIR= objects

SRCS=	fdf.c dot.c key.c misc.c parse.c plot.c 

OBJS= $(SRCS:.c=.o)

SFIX= $(addprefix $(SDIR)/, $(SRCS))
OFIX= $(addprefix $(ODIR)/, $(OBJS)) 

$(ODIR)/%.o: %.c $(INC)
	$(CC) $(CFLAGS)  -I/usr/include -Imlx_linux $< -o $@

$(NAME): $(ODIR) $(OFIX)
	$(MAKE) -C ./libft
	$(CC) $(OFIX) $(MFLAGS) -lft -L./libft -o $(NAME)

all:	$(NAME)

$(ODIR):
		mkdir -p $(ODIR)

bonus: all

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(NAME) $(ODIR)

fclean: clean
	$(MAKE) fclean -C ./libft
	
re:	clean all

.PHONY: all bonus clean flcean re
