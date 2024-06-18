# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 19:20:29 by lnicolau          #+#    #+#              #
#    Updated: 2024/03/26 14:49:03 by lnicolau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

FILES_C = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c\
		ft_isdigit.c ft_memchr.c ft_memcmp.c\
		ft_memcpy.c ft_memmove.c ft_memset.c\
		ft_strchr.c ft_strlcpy.c ft_strlcat.c\
		ft_strncmp.c  ft_strrchr.c\
		ft_tolower.c ft_toupper.c ft_calloc.c\
		ft_isascii.c ft_isprint.c ft_strlen.c\
		ft_strdup.c ft_substr.c ft_strjoin.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
		ft_strmapi.c ft_putnbr_fd.c ft_split.c ft_striteri.c\
		ft_itoa.c ft_strtrim.c ft_strnstr.c ft_p.c ft_printf.c\
		ft_putchar.c ft_putnbr_he.c ft_putnbr_unsigned.c ft_putnbr_x.c\
		ft_putnbr.c ft_putstr.c get_next_line.c get_next_line_utils.c\

FILES_O = $(FILES_C:.c=.o)

all: $(NAME)

$(NAME): $(FILES_O)
	ar rcs $(NAME) $(FILES_O)

clean:
	rm -rf $(FILES_O)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re