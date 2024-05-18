##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## CPool day 10 - Task 01
##

SRC_CSFML = csfml/draw_hover.c \
		csfml/get_pixel.c \
		csfml/hitbox.c \
		csfml/mouse_pos.c \
		csfml/pos.c \
		csfml/rectangle.c \
		csfml/set_invisible.c \
		csfml/sprite.c \
		csfml/vectors.c \
		csfml/display.c \
		csfml/wait.c


SRC_C	=	my/my_compute_power_rec.c \
		my/my_compute_square_root.c \
		my/my_find_prime_sup.c \
		my/my_getnbr.c \
		my/my_isneg.c \
		my/my_is_prime.c \
		my/my_pow.c \
		my/my_putchar.c \
		my/my_put_nbr.c \
		my/my_putstr.c \
		my/my_revstr.c \
		my/my_showmem.c \
		my/my_sort_int_array.c \
		my/my_sort_word_array.c \
		my/my_str_array_len.c \
		my/my_strcapitalize.c \
		my/my_strcat.c \
		my/my_strcmp.c \
		my/my_strcpy.c \
		my/my_str_isalpha.c \
		my/my_str_islower.c \
		my/my_str_isnum.c \
		my/my_str_isprintable.c \
		my/my_str_isupper.c \
		my/my_strlen.c \
		my/my_strlowcase.c \
		my/my_strncmp.c \
		my/my_strncpy.c \
		my/my_strstr.c \
		my/my_strupcase.c \
		my/my_swap.c \
		my/my_str_contains.c \
		my/my_char_contains.c \
		my/my_get_nbr_len.c \
		my/my_int_to_str.c \
		my/my_read_file.c \
		my/my_file_size.c \
		my/my_int_to_bin.c \
		my/my_str_to_word_array.c \
		my/my_put_str_array.c \
		my/my_trim.c \
		my/my_char_isalpha.c \
		my/my_put_error.c \
		my/my_memset.c \
		my/my_file_exists.c \
		my/my_free_array.c \
		my/my_is_a_folder.c \
		my/garbage_collector.c \
		my/garbage_llist.c

SRC = $(SRC_C) $(SRC_CSFML)

OBJ	=	$(SRC:.c=.o)
NAME =	libmy.a
HEADER_NAME	=	my.h lib_csfml.h
HEADER_PATH	=	../include
LDFLAGS =	-L./lib -lmy
CFLAGS	= -I ../include/

all: $(OBJ)
	ar rc ./$(NAME) $(OBJ)
	cp ./$(NAME) ../$(NAME)

debug:
	gcc $(SRC) $(LDFLAGS) $(CFLAGS) -g -c
	ar rc ./$(NAME) $(OBJ)
	cp ./$(NAME) ../$(NAME)

header:
	mkdir "$(HEADER_PATH)" -p
	echo -e "/*\n** EPITECH PROJECT, 2023\n** my.h" > \
	$(HEADER_PATH)/$(HEADER_NAME)
	echo -e "** File description:" >> $(HEADER_PATH)/$(HEADER_NAME)
	echo -e "** Auto generated file\n*/\n" >> $(HEADER_PATH)/$(HEADER_NAME)
	echo -e "#ifndef MY\n    #define MY" >> $(HEADER_PATH)/$(HEADER_NAME)
	find *.c | sed 's/\.[^.]*$$//' | xargs -I {} grep "{}(.*)$$" {}.c | \
	xargs -I {} echo "    {};" >> $(HEADER_PATH)/$(HEADER_NAME)
	echo -e "#endif" >> $(HEADER_PATH)/$(HEADER_NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../$(NAME)
	rm -f ./$(NAME)

re: fclean all

make_and_clean: all clean
