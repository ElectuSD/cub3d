# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allefran <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 15:15:38 by fdeleard          #+#    #+#              #
#    Updated: 2025/08/07 11:19:25 by fdeleard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS 				+=		 		--no-print-directory

ERASE					:=				\033[2K\r
BLUE					:=				\033[34m
YELLOW					:=				\033[33m
GREEN					:=				\033[32m
RED						:=				\033[31m
END						:=				\033[0m


NAME					:=				cub3d
CC						:=				cc


DIR_SRCS				:=				srcs
DIR_INCS				:=				include
DIR_OBJS				:=				.objs


LIBFT_NAME				:=				libft.a
DIR_LIBFT				:=				libft
LIBFT					:=				$(DIR_LIBFT)/$(LIBFT_NAME)


SRCS					:=				srcs/main.c \
										srcs/io/open_file.c \
										srcs/parsing/colors_parsing.c \
										srcs/parsing/colors_utils.c \
										srcs/parsing/map_parsing.c \
										srcs/parsing/map_utils.c \
										srcs/parsing/parsing.c \
										srcs/parsing/parsing_utils.c \
										srcs/parsing/textures_parsing.c \
										srcs/parsing/textures_utils.c

INCS					:=				include/cub3d_parsing.h \
										include/cub3d_colors.h \
										include/cub3d_map.h \
										include/cub3d_player.h \
										include/cub3d_texture.h \
										include/cub3d_utils.h

OBJS					:=				$(SRCS:$(DIR_SRCS)/%.c=$(DIR_OBJS)/%.o)


CFLAGS					:=				-Wall -Wextra -Werror -I$(DIR_INCS) -I$(DIR_LIBFT)/include -g3


.PHONY:			all
all:			libft
											@if $(MAKE) -q $(NAME); then \
												printf "$(YELLOW)$(NAME) > Nothing to be done$(END)\n"; \
											else \
												$(MAKE) ${NAME}; \
											fi; 


$(DIR_OBJS)/%.o:						$(DIR_SRCS)/%.c	${INCS} $(LIBFT) Makefile
											@mkdir -p $(dir $@)
											@${CC} ${CFLAGS} -c $< -o $@
											@printf "$(BLUE)$(NAME) > Compiling : $(END)$<\n"


${NAME}:								${OBJS}
											@$(CC) $(CFLAGS) $(OBJS) $(RLFLAGS) $(LIBFT) -o $@
											@printf "$(GREEN)$(NAME) > Done Compiling : $(END)$@\n"

.PHONY:			libft
libft:
											@if ! $(MAKE) -C $(DIR_LIBFT) -q; then \
												$(MAKE) -C $(DIR_LIBFT); \
											fi; 


.PHONY:			clean
clean:
											@make clean -C ${DIR_LIBFT}
											@if [ ! -d $(DIR_OBJS) ]; then \
												printf "$(RED)$(NAME) > Nothing to clean $(END)\n"; \
											else \
												rm -rdf $(DIR_OBJS); \
												printf "$(RED)$(NAME) > Done deleting : $(END)$(DIR_OBJS)\n"; \
											fi;

.PHONY:			fclean
fclean:			clean
											@if [ -f $(LIBFT) ]; then \
												rm -rdf $(LIBFT); \
												printf "$(RED)$(LIBFT) > Done deleting : $(END)$(LIBFT)\n"; \
											fi;
											@if [ -f $(NAME) ]; then \
												rm -rdf $(NAME); \
												printf "$(RED)$(NAME) > Done deleting : $(END)$(NAME)\n"; \
											fi;
.PHONY:			re
re:				fclean	all
