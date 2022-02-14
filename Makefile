# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tonted <tonted@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 19:36:25 by tonted            #+#    #+#              #
#    Updated: 2022/02/07 19:11:32 by tonted           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Configuration of paths
SRCDIR		= src
OBJDIR		= obj
INCDIR		= include

# Libft
LIBFTDIR	= libft
MAKELIBFT	= @$(MAKE) -C $(LIBFTDIR)

# Name of the final executable
NAME = so_long

# Decide whether the commands will be shwon or not
VERBOSE = TRUE

ENTRYPOINT = src/so_long.c

# Unit Test management
UTEST = .test/_test_main.c
USRCS = $(wildcard .test/*.c)

# Create the list of directories
DIRS = $(shell find $(SRCDIR) -type d | sed 's/$(SRCDIR)\///g' | sed -n '1!p')
SRCDIRS	= $(foreach dir, $(DIRS), $(addprefix $(SRCDIR)/, $(dir)))
OBJDIRS = $(foreach dir, $(DIRS), $(addprefix $(OBJDIR)/, $(dir)))

# Create a list of *.c sources in DIRS
SRCS = $(wildcard src/*.c)
SRCS += $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))
# SRCS := $(filter-out $(ENTRYPOINT), $(SRCS))

# Define objects for all sources
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# Name the compiler & flags
CC = clang
# CFLAGS = -Wall -Wextra -Werror -g

MLXLIB = -Lmlx -lmlx -framework OpenGL -framework AppKit

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(HIDE)$(CC) $(CFLAGS) -iquote$(INCDIR) -iquote$(LIBFTDIR) -c  $< -o $@

all			: buildrepo $(NAME)

$(NAME)		: $(OBJS)
	$(MAKE) -C $(LIBFTDIR)
	$(HIDE)$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft $(MLXLIB) -o $(NAME)
	@printf $(GREEN)"[$@] program created\n"$(RESET)
	
clean		:
	$(HIDE)rm -rf $(OBJDIR)
	$(HIDE)$(MAKE) clean -C $(LIBFTDIR)
	@printf $(YELLOW)"[$(NAME)] objects removed\n"$(RESET)

fclean		: clean
	$(HIDE)rm -f $(NAME)
	$(HIDE)$(MAKE) fclean -C $(LIBFTDIR)

re			: fclean all

buildrepo	:
	$(HIDE)$(call make-repo)

print	:
	@echo $(DIRS)
	@echo $(SRCS)

utest	: buildrepo $(OBJS)
	$(HIDE)$(MAKE) -C $(LIBFTDIR)
	$(HIDE)$(CC) $(CFLAGS) $(OBJS) $(USRCS) -L./libft -lft -o utest
	@printf $(BLUE)"[$@] unit_test \n"$(RESET)
	./utest && rm -rf utest

test	: all

.PHONY		: clean fclean all re $(OBJDIR) buildrepo print

# Create 
define make-repo
	$(HIDE)mkdir -p $(OBJDIR)
	$(HIDE)for dir in $(DIRS); \
   	do \
	mkdir -p $(OBJDIR)/$$dir; \
   	done
endef

# Color
BLACK := "\e[0;30m"
RED := "\e[0;31m"
GREEN := "\e[0;32m"
YELLOW := "\e[0;33m"
BLUE := "\e[0;34m"
MAGENTA := "\e[0;35m"
CYAN := "\e[0;36m"
RESET :="\e[0m"

# Hide or not the calls depending of VERBOSE
ifeq ($(VERBOSE),TRUE)
    HIDE =  
else
    HIDE = @
endif