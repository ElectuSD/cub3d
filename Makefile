# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allefran <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 15:15:38 by fdeleard          #+#    #+#              #
#    Updated: 2025/11/13 11:35:27 by fdeleard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#	MAKEFLAGS
MAKEFLAGS 				+=		 		--no-print-directory


#	COLORS
ERASE					:=				\033[2K\r
BLUE					:=				\033[34m
YELLOW					:=				\033[33m
GREEN					:=				\033[32m
RED						:=				\033[31m
END						:=				\033[0m


#	EXECUTABLE
NAME					:=				cub3D


#	COMPILERS
CC						:=				cc


#	PROJECT DIRECTORIES
DIR_SRCS				:=				srcs
DIR_INCS				:=				include
DIR_OBJS				:=				.objs
DIR_DEPS				:=				.deps
DIR_MLX					:=				mlx_linux
DIR_LIBFT				:=				libft


#	LIBRAIRIES
LIBFT_NAME				:=				libft.a
MLX_NAME				:=				libmlx_Linux.a
MLX						:=				$(DIR_MLX)/$(MLX_NAME)
LIBFT					:=				$(DIR_LIBFT)/$(LIBFT_NAME)


#	FLAGS
FLAGS					:=				-Wall -Wextra -Werror -I$(DIR_INCS)
DEPFLAGS				:=				-MMD -MP
MLX_FLAGS				:=				-I$(DIR_MLX)
LIBFT_FLAGS				:=				-I$(DIR_LIBFT)/include
CFLAGS					:=				$(FLAGS) $(DEPFLAGS) $(MLX_FLAGS) $(LIBFT_FLAGS) -std=gnu11
LDFLAGS					:=				$(MLX) $(LIBFT) -L/usr/lib -lXext -lX11 -lm -lz


#	DEBUG FLAGS
ifeq ($(MODE),debug)
	CFLAGS				+=				-g3
else
	CFLAGS				+=				-O3
endif


#	SOURCES AND HEADERS
SRCS					:=				$(DIR_SRCS)/main.c \
										$(DIR_SRCS)/init.c \
										$(DIR_SRCS)/free.c \
										$(DIR_SRCS)/check_filename.c \
										$(DIR_SRCS)/color/color.c \
										$(DIR_SRCS)/render/time.c \
										$(DIR_SRCS)/render/utils.c \
										$(DIR_SRCS)/render/game_loop.c \
										$(DIR_SRCS)/player/player_utils.c \
										$(DIR_SRCS)/player/player_controls.c \
										$(DIR_SRCS)/player/player_movements.c \
										$(DIR_SRCS)/player/player_strafe.c \
										$(DIR_SRCS)/raycast/raycast_drawing_setters.c \
										$(DIR_SRCS)/raycast/raycast.c \
										$(DIR_SRCS)/raycast/raycast_getters.c \
										$(DIR_SRCS)/raycast/raycast_drawing_utils.c \
										$(DIR_SRCS)/raycast/raycast_setters.c \
										$(DIR_SRCS)/raycast/raycast_drawing_getters.c \
										$(DIR_SRCS)/raycast/raycast_drawing.c \
										$(DIR_SRCS)/print/print_error.c \
										$(DIR_SRCS)/print/print_error_utils.c \
										$(DIR_SRCS)/textures/load_textures.c \
										$(DIR_SRCS)/parsing/parsing_utils.c \
										$(DIR_SRCS)/parsing/textures_parsing.c \
										$(DIR_SRCS)/parsing/colors_utils.c \
										$(DIR_SRCS)/parsing/map_parsing.c \
										$(DIR_SRCS)/parsing/map_utils.c \
										$(DIR_SRCS)/parsing/textures_utils.c \
										$(DIR_SRCS)/parsing/parsing.c \
										$(DIR_SRCS)/parsing/colors_parsing.c \
										$(DIR_SRCS)/input/hooks.c \
										$(DIR_SRCS)/draw/draw_player.c \
										$(DIR_SRCS)/draw/draw_minimap_grid.c \
										$(DIR_SRCS)/draw/draw_line.c \
										$(DIR_SRCS)/draw/create_img.c \
										$(DIR_SRCS)/draw/draw_pixel.c \
										$(DIR_SRCS)/draw/draw_minimap.c \
										$(DIR_SRCS)/draw/draw_crosshair.c \
										$(DIR_SRCS)/draw/draw_rectangle.c \
										$(DIR_SRCS)/draw/draw_floor_ceilling.c \
										$(DIR_SRCS)/maths/new_dpoint2d.c \
										$(DIR_SRCS)/maths/new_rectangle.c \
										$(DIR_SRCS)/maths/convert_d2d_to_i2d.c \
										$(DIR_SRCS)/maths/new_ipoint2d.c \
										$(DIR_SRCS)/map/map_check.c \
										$(DIR_SRCS)/map/map_init.c \
										$(DIR_SRCS)/map/map_check_wall.c

INCS					:=				$(DIR_INCS)/cub3d.h \
										$(DIR_INCS)/cub3d_colors.h \
										$(DIR_INCS)/cub3d_draw.h \
										$(DIR_INCS)/cub3d_input.h \
										$(DIR_INCS)/cub3d_map.h \
										$(DIR_INCS)/cub3d_maths.h \
										$(DIR_INCS)/cub3d_parsing.h \
										$(DIR_INCS)/cub3d_player.h \
										$(DIR_INCS)/cub3d_raycast.h \
										$(DIR_INCS)/cub3d_textures.h \
										$(DIR_INCS)/cub3d_render.h
										

#	OBJECTS AND DEPENDENCIES
OBJS					:=				$(SRCS:$(DIR_SRCS)/%.c=$(DIR_OBJS)/%.o)
DEPS					:=				$(SRCS:$(DIR_SRCS)/%.c=$(DIR_DEPS)/%.d)


#	ALL RULE
.PHONY:			all
all:			libft mlx
											@if $(MAKE) -q $(NAME); then \
												printf "$(YELLOW)$(NAME) > Nothing to be done$(END)\n"; \
											else \
												$(MAKE) ${NAME}; \
											fi; 

#	COMPILE SRCS FILES RULE
$(DIR_OBJS)/%.o:						$(DIR_SRCS)/%.c	$(LIBFT) $(MLX) Makefile
											@mkdir -p $(dir $@)
											@mkdir -p $(DIR_OBJS) $(DIR_DEPS)
											@${CC} ${CFLAGS} -c $< -o $@
											@mv $(DIR_OBJS)/$(notdir $(basename $@)).d $(DIR_DEPS)/ 2>/dev/null || true
											@printf "$(BLUE)$(NAME) > Compiling : $(END)$<\n"


#	LINKING
${NAME}:								${OBJS}
											@$(CC) $(OBJS) -o $@ $(LDFLAGS)
											@printf "$(GREEN)$(NAME) > Done Compiling : $(END)$@\n"


#	INCLUDE DEPENDENCIES FILES
-include	$(DEPS)


#	CLEAN RULE
.PHONY:			libft
libft:
											@if ! $(MAKE) -C $(DIR_LIBFT) -q; then \
												$(MAKE) -C $(DIR_LIBFT); \
											fi; 


.PHONY:			mlx
mlx:
											@if ! $(MAKE) -C $(DIR_MLX) -q; then \
												$(MAKE) -C $(DIR_MLX); \
											else \
												printf "$(YELLOW)$(DIR_MLX) > Nothing to be done $(END)\n"; \
											fi; 


.PHONY:			clean
clean:
											@make clean -C ${DIR_LIBFT}
											@if [ -d $(DIR_MLX)/obj ]; then \
												rm -rdf $(DIR_MLX)/obj; \
												printf "$(RED)$(DIR_MLX) > Done deleting $(END)$(DIR_MLX)/obj\n"; \
												else \
												printf "$(RED)$(DIR_MLX) > Nothing to clean $(END)\n"; \
												fi;
											@if [ ! -d $(DIR_OBJS) ]; then \
												printf "$(RED)$(NAME) > Nothing to clean $(END)\n"; \
											else \
												rm -rdf $(DIR_OBJS); \
												printf "$(RED)$(NAME) > Done deleting : $(END)$(DIR_OBJS)\n"; \
											fi;


.PHONY:			fclean
fclean:			clean
											@if [ -f $(MLX) ]; then \
												make clean -C $(DIR_MLX); \
												printf "$(RED)$(DIR_MLX) > Done deleting : $(END)$(MLX)\n"; \
											fi;
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


.PHONY:			debug
debug:			fclean
											@$(MAKE) MODE=debug all
