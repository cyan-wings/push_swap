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


PSDIR			=	$(SRCDIR)ps/
PSSRC			=		\
						ps_parselst					\
						ps_lstprint					\
						ps_lstperform_operation		\
						ps_sort_three				\
						ps_perform_rotation			\
						ps_sort						\

PSSRCS			=	$(addprefix $(PSDIR), $(PSSRC))


MAIN			=	$(SRCDIR)main/push_swap
SRC_AGG			=	\
					$(CALCSRCS)		\
					$(SORTSRCS)		\
					$(PSSRCS)		\
					
MANDATORY		=	\
					$(SRC_AGG)		\
					$(MAIN)			\

SRCS			=	$(addsuffix .c, $(MANDATORY))



CKDIR			= 	$(SRCDIR)checker/
CKSRC			=		\
						checker						\
						ps_checker_get_next_line	\

BONUSSRCS		=	$(addprefix $(CKDIR), $(CKSRC))

BONUS_AGG		=	\
					$(SRC_AGG)		\
					$(BONUSSRCS)	\
					
BONUS			=	$(addsuffix .c, $(BONUS_AGG))



OBJDIR			=	objs/
OBJS			=	$(subst $(SRCDIR), $(OBJDIR), $(subst .c,.o,$(SRCS)))
OBJDIRS			=	$(sort $(dir $(OBJS)))
B_OBJS			=	$(subst $(SRCDIR), $(OBJDIR), $(subst .c,.o,$(BONUS)))
B_OBJDIRS		=	$(sort $(dir $(B_OBJS)))



NAME			=	push_swap
IFLAGS			=	-I$(HDRDIR)
CC				=	cc
WFLAGS			=	-Wall -Wextra -Werror
CFLAGS 			=	$(WFLAGS) -c
RM				=	rm -rf
MAKE			=	make -C

UP				=	\033[1A
FLUSH			=	\033[2K
SANIT			=	-fsanitize=address -g

BONUS_CHECKER	=	checker



all: $(NAME)

bonus: all $(BONUS_CHECKER)
	
$(BONUS_CHECKER): $(LIBFT) $(B_OBJDIRS) $(B_OBJS)
	$(CC) $(WFLAGS) -o $(BONUS_CHECKER) $(B_OBJS) $(LIBFTINC)

$(NAME): $(LIBFT) $(OBJDIRS) $(OBJS)
	$(CC) $(WFLAGS) -o $(NAME) $(OBJS) $(LIBFTINC)

$(LIBFT):
	$(MAKE) $(LIBFTDIR)

$(OBJDIRS):
	mkdir -p $@

$(B_OBJDIRS):
	mkdir -p $@

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJDIR)
	$(MAKE) $(LIBFTDIR) $@

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS_CHECKER)
	$(MAKE) $(LIBFTDIR) $@

re: fclean all bonus

.PHONY: all bonus main clean fclean re

