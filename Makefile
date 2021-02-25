# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otaishi <otaishi@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/26 01:40:57 by otaishi           #+#    #+#              #
#    Updated: 2021/01/10 05:59:47 by tchiba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC    = gcc

CFLAGS    = -Wall    -Wextra    -Werror

RM        =    rm -f

INCDIR    =    ./

SRCDIR    =    ./

SRC = ft_printf.c\
ft_info.c\
ft_utils.c\
ft_strutils.c\
ft_process_c.c\
ft_process_d.c\
ft_process_s.c\
ft_process_u.c\
ft_process_x.c\
ft_process_p.c

SRCS    =    $(addprefix $(SRCDIR), $(SRC))

OBJS    =    $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS)    -I $(INCDIR) -c $< -o $(<:.c=.o)

$(NAME):    $(OBJS)
	ar    rcs    $(NAME)    $(OBJS)

all:        $(NAME)

clean:
	$(RM) $(OBJS)

fclean:        clean
	$(RM) $(NAME)

re:            fclean all

.PHONY:    all clean fclean re
