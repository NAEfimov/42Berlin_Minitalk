NAME		:= server client server_bonus client_bonus
NAME_S		:= server
NAME_SB		:= server_bonus
NAME_C		:= client
NAME_CB		:= client_bonus

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#
#
# INCS        header file locations
#
# SRCS      source files
#
# OBJS      object files
# DEPS      dependency files
#
# CC        compiler
# CFLAGS    compiler flags
# CPPFLAGS  preprocessor flags

LIBS        := ft
LIBS_TARGET := libft/libft.a

INCS		:= include libft

SRC_DIR		:= src

SRCS		:=			\
	server.c			\
	server_msg.c		\
	server_msg_bonus.c	\
	server_sigusr.c		\
	server_utils.c		\
	client.c			\
	client_bonus.c		\
	client_send.c		\
	client_utils.c

SRCS_S		:=			\
	server.c			\
	server_msg.c		\
	server_sigusr.c		\
	server_utils.c

SRCS_SB		:=			\
	server.c			\
	server_msg_bonus.c		\
	server_sigusr.c		\
	server_utils.c

SRCS_C		:=			\
	client.c			\
	client_send.c		\
	client_utils.c

SRCS_CB		:=			\
	client_bonus.c			\
	client_send.c		\
	client_utils.c
	
SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
SRCS_S		:= $(SRCS_S:%=$(SRC_DIR)/%)
SRCS_SB		:= $(SRCS_SB:%=$(SRC_DIR)/%)
SRCS_C		:= $(SRCS_C:%=$(SRC_DIR)/%)
SRCS_CB		:= $(SRCS_CB:%=$(SRC_DIR)/%)

BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS_S		:= $(SRCS_S:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS_SB		:= $(SRCS_SB:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS_C		:= $(SRCS_C:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS_CB		:= $(SRCS_CB:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

DEPS		:= $(OBJS:.o=.d)


CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS     := $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS      := $(addprefix -l,$(LIBS))

#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#
# RM        force remove
# MAKEFLAGS make flags

RM			= rm -f
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D)

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#
# all       default goal
# $(NAME)   link .o -> library
# %.o       compilation .c -> .o
# clean     remove .o
# fclean    remove .o + binary
# re        remake default goal

all: $(NAME_S) $(NAME_C)


$(NAME_S): $(LIBS_TARGET) $(OBJS_S)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $(OBJS_S) $(LDLIBS)
	$(info CREATED $(NAME_S))

$(NAME_C): $(LIBS_TARGET) $(OBJS_C)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $(OBJS_C) $(LDLIBS)
	$(info CREATED $(NAME_C))

bonus: $(NAME_SB) $(NAME_CB)

$(NAME_SB): $(LIBS_TARGET) $(OBJS_SB)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $(OBJS_SB) $(LDLIBS)
	$(info CREATED $(NAME_SB))

$(NAME_CB): $(LIBS_TARGET) $(OBJS_CB)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@ $(OBJS_CB) $(LDLIBS)
	$(info CREATED $(NAME_CB))

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

-include $(DEPS)

clean:
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f clean; done
	$(RM) $(OBJS_S) $(OBJS_SB) $(OBJS_C) $(OBJS_CB) $(DEPS)
fclean: clean
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f fclean; done
	$(RM) $(NAME_S) $(NAME_SB) $(NAME_C) $(NAME_CB)

re:
	$(MAKE) fclean
	$(MAKE) all
