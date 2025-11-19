NAME=libftprintf.a
CC=cc
HEADERS=printf.h
LIBFT=libft.a
LIBFT_DIR=libft/
CFLAGS=-Wall -Werror -Wextra -I. -g
SRC_FILES=ft_printf.c\
	check_type.c\
	ft_ltoa.c\
	ft_ltoa_hexa.c\
	ft_print_padding.c

# BONUS_FILES=

OBJ=$(SRC_FILES:.c=.o)

# OBJ_BONUS=$(BONUS_FILES:.c=.o)

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT_DIR)$(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR) bonus

all: $(NAME)

clean: 
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

test: all clean
	$(CC) -Wall -Werror -Wextra -g3 main.c $(NAME) -lbsd

.PHONY: all clean fclean re