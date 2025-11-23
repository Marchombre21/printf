NAME=libftprintf.a

CC=cc

HEADERS=printf.h

LIBFT=libft/libft.a

LIBFT_DIR=libft/

CFLAGS=-Wall -Werror -Wextra -I.

CDEPFLAGS=-MMD -MP

BONUS=.bonus

SRC_FILES=ft_printf.c\
	check_type.c\
	ft_ltoa.c\
	ft_ltoa_hexa.c\
	ft_extra_signs.c

BONUS_FILES=ft_printf_bonus.c\
	check_type_bonus.c\
	ft_ltoa_bonus.c\
	ft_ltoa_hexa_bonus.c\
	ft_extra_signs_bonus.c

OBJ=$(SRC_FILES:.c=.o)

BONUS_OBJ=$(BONUS_FILES:.c=.o)

DEPS=$(OBJ:.o=.d)

BONUS_DEPS=$(BONUS_OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(CDEPFLAGS) -c $< -o $@

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR) bonus

$(BONUS):$(BONUS_OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(BONUS_OBJ)
	touch $@

bonus: $(BONUS)

clean: 
	rm -f $(OBJ) $(DEPS) $(BONUS_OBJ) $(BONUS_DEPS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re test bonus

-include $(DEPS)

-include $(BONUS_DEPS)