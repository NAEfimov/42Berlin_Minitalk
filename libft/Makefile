NAME        = libft.a

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#
# SRCS      source files
#
# OBJS      object files
# DEPS      dependency files
#
# CC        compiler
# CFLAGS    compiler flags
# CPPFLAGS  preprocessor flags

SRCS		:=			\
	ft_atoi.c 			\
	ft_bzero.c 			\
	ft_calloc.c 		\
	ft_isalnum.c 		\
	ft_isalpha.c 		\
	ft_isascii.c		\
	ft_isdigit.c		\
	ft_isprint.c		\
	ft_itoa.c			\
	ft_uitoa.c			\
	ft_memchr.c			\
	ft_memcmp.c			\
	ft_memcpy.c			\
	ft_memmove.c 		\
	ft_memset.c			\
	ft_split.c			\
	ft_strchr.c			\
	ft_strdup.c			\
	ft_strjoin.c 		\
	ft_strlcat.c 		\
	ft_strlcpy.c 		\
	ft_strlen.c 		\
	ft_strcmp.c 		\
	ft_strncmp.c 		\
	ft_strnstr.c 		\
	ft_strrchr.c 		\
	ft_strtrim.c 		\
	ft_substr.c 		\
	ft_tolower.c 		\
	ft_toupper.c 		\
	ft_strmapi.c 		\
	ft_striteri.c 		\
	ft_putchar_fd.c 	\
	ft_putendl_fd.c 	\
	ft_putnbr_fd.c 		\
	ft_putstr_fd.c		\
	ft_lstnew.c			\
	ft_lstadd_front.c	\
	ft_lstsize.c		\
	ft_lstlast.c		\
	ft_lstadd_back.c	\
	ft_lstdelone.c		\
	ft_lstclear.c		\
	ft_lstiter.c		\
	ft_lstmap.c

OBJS		:= $(SRCS:%.c=%.o)
DEPS		:= $(OBJS:.o=.d)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
CPPFLAGS	= -MMD -MP
# add -I _bonus for the bonus part
AR 			= ar
ARFLAGS		= -r -c -s

#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#
# RM        force remove
# MAKEFLAGS make flags

RM			= rm -f
MAKEFLAGS	+= --no-print-directory

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#
# all       default goal
# $(NAME)   link .o -> library
# %.o       compilation .c -> .o
# clean     remove .o
# fclean    remove .o + binary
# re        remake default goal

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(info CREATED $(NAME))

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

-include $(DEPS) $(DEPS_B)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
