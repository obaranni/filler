cmake_minimum_required(VERSION 3.9)
project(filler)

set(CMAKE_C_STANDARD 99)

add_executable(filler
        libft/src/ft_absolute_val.c
        libft/src/ft_atoi.c
        libft/src/ft_bzero.c
        libft/src/ft_isalnum.c
        libft/src/ft_isalpha.c
        libft/src/ft_isascii.c
        libft/src/ft_isdigit.c
        libft/src/ft_isprint.c
        libft/src/ft_itoa.c
        libft/src/ft_lstadd.c
        libft/src/ft_lstdel.c
        libft/src/ft_lstdelone.c
        libft/src/ft_lstiter.c
        libft/src/ft_lstlast.c
        libft/src/ft_lstmap.c
        libft/src/ft_lstnew.c
        libft/src/ft_memalloc.c
        libft/src/ft_memccpy.c
        libft/src/ft_memchr.c
        libft/src/ft_memcmp.c
        libft/src/ft_memcpy.c
        libft/src/ft_memdel.c
        libft/src/ft_memmove.c
        libft/src/ft_memset.c
        libft/src/ft_putchar.c
        libft/src/ft_putchar_fd.c
        libft/src/ft_putendl.c
        libft/src/ft_putendl_fd.c
        libft/src/ft_putnbr.c
        libft/src/ft_putnbr_fd.c
        libft/src/ft_putstr.c
        libft/src/ft_putstr_fd.c
        libft/src/ft_strbyte.c
        libft/src/ft_strcat.c
        libft/src/ft_strchr.c
        libft/src/ft_strclr.c
        libft/src/ft_strcmp.c
        libft/src/ft_strcpy.c
        libft/src/ft_strdel.c
        libft/src/ft_strdup.c
        libft/src/ft_strequ.c
        libft/src/ft_striter.c
        libft/src/ft_striteri.c
        libft/src/ft_strjoin.c
        libft/src/ft_strlcat.c
        libft/src/ft_strlen.c
        libft/src/ft_strmap.c
        libft/src/ft_strmapi.c
        libft/src/ft_strncat.c
        libft/src/ft_strncmp.c
        libft/src/ft_strncpy.c
        libft/src/ft_strnequ.c
        libft/src/ft_strnew.c
        libft/src/ft_strnstr.c
        libft/src/ft_strrchr.c
        libft/src/ft_strrev.c
        libft/src/ft_strsplit.c
        libft/src/ft_strstr.c
        libft/src/ft_strsub.c
        libft/src/ft_strtrim.c
        libft/src/ft_swap.c
        libft/src/ft_tolower.c
        libft/src/ft_toupper.c
        libft/inc/libft.h
        src/filler_main.c
        inc/filler.h
        src/reader/reader.c
        libft/src/get_next_line.c
        src/validator/validator.c src/analizer/analizer.c src/responder/responder.c src/visualizer/visualizer.c src/parser/parser.c src/parser/parse_map.c src/parser/parse_figure.c src/analizer/set_priorities.c)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -framework OpenGL -framework AppKit" )

#target_link_libraries(filler /Users/apietush/rt/minilibx_macos/libmlx.a)
target_link_libraries(filler /Users/obaranni/projects/filler/libft/libft.a)
