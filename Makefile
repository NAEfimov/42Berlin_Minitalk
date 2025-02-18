NAME		:= server client
NAME_S		:= server
NAME_C		:= client

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
	client_send.c		\
	client_utils.c

SRCS_S		:=			\
	server.c			\
	server_msg.c		\
	server_sigusr.c		\
	server_utils.c

SRCS_C		:=			\
	client.c			\
	client_send.c		\
	client_utils.c
	
SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
SRCS_S		:= $(SRCS_S:%=$(SRC_DIR)/%)
SRCS_C		:= $(SRCS_C:%=$(SRC_DIR)/%)

BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS_S		:= $(SRCS_S:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS_C		:= $(SRCS_C:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

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

bonus: $(OBJS_S) $(OBJS_C) $(LIBS_TARGET) bonus_srcs
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $(NAME_S) $(OBJS_S) $(LDLIBS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $(NAME_C) $(OBJS_C) $(LDLIBS)
#	$(eval SRCS_S := $(patsubst $(SRC_DIR)/server_msg.c, $(SRC_DIR)/server_msg_bonus.c, $(SRCS_S)))
#	@echo "Bonus sources: $(SRCS_S)"
#	$(MAKE) -C $(dir $(LIBS_TARGET))
#	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $(NAME_S) $(SRCS_S) $(LDLIBS)
#	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $(NAME_C) $(SRCS_C) $(LDLIBS)

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

-include $(DEPS)

bonus_srcs:
	$(eval SRCS_S := $(patsubst $(SRC_DIR)/server_msg.c, $(SRC_DIR)/server_msg_bonus.c, $(SRCS_S)))
	$(eval OBJS_S := $(patsubst $(BUILD_DIR)/server_msg.o, $(BUILD_DIR)/server_msg_bonus.c, $(SRCS_S)))
	@echo "Bonus sources: $(SRCS_S)"

clean:
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f clean; done
	$(RM) $(OBJS) $(DEPS)
fclean: clean
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f fclean; done
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
