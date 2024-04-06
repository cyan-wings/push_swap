LIBFTDIR		=	libft
LIBFT			= 	$(LIBFTDIR)/libft.a
LIBFTINC		=	-L$(LIBFTDIR) -lft
HDRDIR			=	includes/

SRCDIR			=	srcs/

CALCDIR			=	$(SRCDIR)calc_utils/
CALCSRC			=		\
						calc_push_index			\
						calc_rotate_options		\
						calc_lowest_push		\

CALCSRCS		=	$(addprefix $(CALCDIR), $(CALCSRC))


SORTDIR			=	$(SRCDIR)sort_utils/
SORTSRC			=		\
						ft_lstissorted	\

SORTSRCS		=	$(addprefix $(SORTDIR), $(SORTSRC))



MAINDIR			=	$(SRCDIR)main/
MAINSRC			=		\
						ps_parselst					\
						ps_lstprint					\
						ps_lstperform_operation		\
						ps_sort_three				\
						ps_perform_rotation			\
						ps_sort						\
						push_swap					\

MAINSRCS		=	$(addprefix $(MAINDIR), $(MAINSRC))



SRC_AGG			=	\
					$(CALCSRCS)		\
					$(SORTSRCS)		\
					$(MAINSRCS)		\

SRCS			=	$(addsuffix .c, $(SRC_AGG))


OBJDIR			=	objs/
OBJS			=	$(subst $(SRCDIR), $(OBJDIR), $(subst .c,.o,$(SRCS)))
OBJDIRS			=	$(sort $(dir $(OBJS)))


NAME			=	push_swap
IFLAGS			=	-I$(HDRDIR)
CC				=	cc
WFLAGS			=	-Wall -Wextra -Werror
CFLAGS 			=	$(WFLAGS) -c
RM				=	rm -rf
MAKE			=	make -C

UP				=	\033[1A
FLUSH			=	\033[2K
SANIT			=	-fsanitize=address

CHECKER			=	./checker_Mac

all: $(NAME)

bonus: all

$(NAME): $(LIBFT) $(OBJDIRS) $(OBJS)
	$(CC) $(WFLAGS) -o $(NAME) $(OBJS) $(LIBFTINC)

$(LIBFT):
	$(MAKE) $(LIBFTDIR)

$(OBJDIRS):
	mkdir -p $@

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJDIR)
	$(MAKE) $(LIBFTDIR) $@

fclean: clean
	$(RM) $(NAME)
	$(MAKE) $(LIBFTDIR) $@

re: fclean all

.PHONY: all bonus main clean fclean re

