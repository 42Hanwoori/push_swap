NAME = push_swap

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -f

LIBFT = libft.a
LIBFT_DIR = ./libft
#INCLUDE = -I./include -I./libft

SRCS_FILE = main.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILE))

SRCS_DIR = ./src

OBJS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILE:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT_DIR)/$(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/$(LIBFT) -o $@

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_DIR)/$(LIBFT) :
	@$(MAKE) all -C $(LIBFT_DIR)

$(SRCS_DIR)/%.o : $(SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	@$(MAKE) -C $(LIBFT_DIR) clean;
	@$(RM) $(SRCS_DIR)/*.o

fclean : clean
	@$(MAKE) -C $(LIBFT_DIR) fclean;
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re