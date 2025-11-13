# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allefran <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 15:15:38 by fdeleard          #+#    #+#              #
#    Updated: 2025/11/13 14:24:37 by fdeleard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
#
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
NAME					:=				libft.a


#	COMPILERS
CC						:=				cc


#	PROJECT DIRECTORIES
DIR_SRCS				:=				srcs
DIR_INCS				:=				include
DIR_OBJS				:=				.objs
DIR_DEPS				:=				.deps


#	FLAGS
FLAGS					:=				-Wall -Wextra -Werror -I$(DIR_INCS)
BUFFER_FLAG				:=				-D BUFFER_SIZE=42
DEPFLAGS				:=				-MMD -MP
CFLAGS					:=				$(FLAGS) $(DEPFLAGS) $(BUFFER_FLAG)


#	DEBUG FLAGS
ifeq ($(MODE),debug)
	CFLAGS				+=				-g3
else
	CFLAGS				+=				-O3
endif


#	SOURCES AND HEADERS
SRCS					:=				$(DIR_SRCS)/ctype/ft_isalpha.c \
										$(DIR_SRCS)/ctype/ft_isascii.c \
										$(DIR_SRCS)/ctype/ft_isdigit.c \
										$(DIR_SRCS)/ctype/ft_isprint.c \
										$(DIR_SRCS)/ctype/ft_isspace.c \
										$(DIR_SRCS)/ctype/ft_tolower.c \
										$(DIR_SRCS)/ctype/ft_toupper.c \
										$(DIR_SRCS)/ctype/ft_isalnum.c \
										$(DIR_SRCS)/io/ft_printf/utils/ft_fprint_hex.c \
										$(DIR_SRCS)/io/ft_printf/utils/ft_fprint_ptr.c \
										$(DIR_SRCS)/io/ft_printf/utils/ft_fprint_unsigned.c \
										$(DIR_SRCS)/io/ft_printf/utils/ft_fprint_utils.c \
										$(DIR_SRCS)/io/ft_printf/ft_fprintf.c \
										$(DIR_SRCS)/io/ft_printf/ft_printf.c \
										$(DIR_SRCS)/io/ft_putstr_fd.c \
										$(DIR_SRCS)/io/ft_putchar_fd.c \
										$(DIR_SRCS)/io/ft_putendl_fd.c \
										$(DIR_SRCS)/io/ft_putnbr_fd.c \
										$(DIR_SRCS)/io/get_next_line.c \
										$(DIR_SRCS)/lst/ft_lstadd_back.c \
										$(DIR_SRCS)/lst/ft_lstadd_front.c \
										$(DIR_SRCS)/lst/ft_lstclear.c \
										$(DIR_SRCS)/lst/ft_lstdelone.c \
										$(DIR_SRCS)/lst/ft_lstiter.c \
										$(DIR_SRCS)/lst/ft_lstlast.c \
										$(DIR_SRCS)/lst/ft_lstmap.c \
										$(DIR_SRCS)/lst/ft_lstsize.c \
										$(DIR_SRCS)/lst/ft_lstnew.c \
										$(DIR_SRCS)/mem/ft_bzero.c \
										$(DIR_SRCS)/mem/ft_memchr.c \
										$(DIR_SRCS)/mem/ft_memcmp.c \
										$(DIR_SRCS)/mem/ft_memcpy.c \
										$(DIR_SRCS)/mem/ft_memmove.c \
										$(DIR_SRCS)/mem/ft_memset.c \
										$(DIR_SRCS)/mem/ft_calloc.c \
										$(DIR_SRCS)/str/ft_striteri.c \
										$(DIR_SRCS)/str/ft_atoi.c \
										$(DIR_SRCS)/str/ft_itoa.c \
										$(DIR_SRCS)/str/ft_split.c \
										$(DIR_SRCS)/str/ft_strcmp.c \
										$(DIR_SRCS)/str/ft_strlcpy.c \
										$(DIR_SRCS)/str/ft_strlen.c \
										$(DIR_SRCS)/str/ft_strncmp.c \
										$(DIR_SRCS)/str/ft_strnstr.c \
										$(DIR_SRCS)/str/ft_strtrim.c \
										$(DIR_SRCS)/str/ft_strjoin.c \
										$(DIR_SRCS)/str/ft_strndup.c \
										$(DIR_SRCS)/str/ft_strrchr.c \
										$(DIR_SRCS)/str/ft_strnchr.c \
										$(DIR_SRCS)/str/ft_strtok.c \
										$(DIR_SRCS)/str/ft_strmapi.c \
										$(DIR_SRCS)/str/ft_strdup.c \
										$(DIR_SRCS)/str/ft_strjoin_free.c \
										$(DIR_SRCS)/str/ft_strchr.c \
										$(DIR_SRCS)/str/ft_strlcat.c \
										$(DIR_SRCS)/str/ft_substr.c \
										$(DIR_SRCS)/util/ft_free_tab.c \
										$(DIR_SRCS)/util/ft_swap_int.c \
										$(DIR_SRCS)/util/ft_char_in_set.c \
										$(DIR_SRCS)/vec/ft_vecdestroy.c \
										$(DIR_SRCS)/vec/ft_vecinsert.c \
										$(DIR_SRCS)/vec/ft_veciter.c \
										$(DIR_SRCS)/vec/ft_vecpush.c \
										$(DIR_SRCS)/vec/ft_vecnew.c \
										$(DIR_SRCS)/vec/ft_vecgrow.c \
										$(DIR_SRCS)/ht/ft_htiterator.c \
										$(DIR_SRCS)/ht/ft_htnext.c \
										$(DIR_SRCS)/ht/ft_htunset.c \
										$(DIR_SRCS)/ht/ft_htlenght.c \
										$(DIR_SRCS)/ht/ft_htdestroy.c \
										$(DIR_SRCS)/ht/ft_htget.c \
										$(DIR_SRCS)/ht/ft_htset.c \
										$(DIR_SRCS)/ht/ft_htnew.c

INCS					:=				$(DIR_INCS)/ft_printf/ft_printf.h \
										$(DIR_INCS)/libft_ctype.h \
										$(DIR_INCS)/libft_mem.h \
										$(DIR_INCS)/libft_vec.h \
										$(DIR_INCS)/libft_ht.h \
										$(DIR_INCS)/libft_lst.h \
										$(DIR_INCS)/libft_utils.h \
										$(DIR_INCS)/libft_io.h \
										$(DIR_INCS)/libft_str.h


#	OBJECTS AND DEPENDENCIES
OBJS					:=				$(SRCS:$(DIR_SRCS)/%.c=$(DIR_OBJS)/%.o)
DEPS					:=				$(SRCS:$(DIR_SRCS)/%.c=$(DIR_DEPS)/%.d)


#	ALL RULE
.PHONY:			all
all:
											@if $(MAKE) -q $(NAME); then \
												printf "$(YELLOW)$(NAME) > Nothing to be done$(END)\n"; \
											else \
												$(MAKE) ${NAME}; \
											fi; 


#	COMPILE SRCS FILES RULE
$(DIR_OBJS)/%.o:						$(DIR_SRCS)/%.c Makefile
											@mkdir -p $(DIR_OBJS) $(DIR_DEPS)
											@mkdir -p $(dir $@)
											@${CC} ${CFLAGS} -c $< -o $@
											@src_rel=$(<:$(DIR_SRCS)/%.c=%.d); \
											dep_file=$(DIR_OBJS)/$$src_rel; \
											dep_dir=$(DIR_DEPS)/$$(dirname $$src_rel); \
											mkdir -p $$dep_dir; \
											mv $$dep_file $$dep_dir; \
											printf "$(BLUE)$(NAME) > Compiling : $(END)$<\n"

#	LINKING
${NAME}:								${OBJS}
											@ar -rcs $@ $^
											@printf "$(GREEN)$(NAME) > Done Compiling : $(END)$@\n"


#	INCLUDE DEPENDENCIES FILES
-include	$(DEPS)


#	CLEAN RULE
.PHONY:			clean
clean:
											@if [ ! -d $(DIR_OBJS) ] && [ ! -d $(DIR_DEPS) ]; then \
												printf "$(RED)$(NAME) > Nothing to clean $(END)\n"; \
											else \
												[ -d $(DIR_OBJS) ] && \
													rm -rf $(DIR_OBJS) && \
													printf "$(RED)$(NAME) > Done deleting : $(END)$(DIR_OBJS)\n"; \
												[ -d $(DIR_DEPS) ] && \
													rm -rf $(DIR_DEPS) && \
													printf "$(RED)$(NAME) > Done deleting : $(END)$(DIR_DEPS)\n"; \
											fi; true

#	FCLEAN RULE
.PHONY:			fclean
fclean:			clean
											@if [ -f $(NAME) ]; then \
												rm -rdf $(NAME); \
												printf "$(RED)$(NAME) > Done deleting : $(END)$(NAME)\n"; \
											fi;


#	REBUILD RULE
.PHONY:			re
re:				fclean	all
