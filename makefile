LIBFT_PATH = lib/libft
LIBFT = $(LIBFT_PATH)/libft.a
PRINTF_PATH = lib/ft_printf
PRINTF = $(PRINTF_PATH)/ft_printf.a

SRC_FILES = src/server.c
SOURCES = $(SRC_FILES)
OBJECTS = $(SOURCES:.c=.o)

CLIENT_SRC_FILES = src/client.c
CLIENT_SOURCES = $(CLIENT_SRC_FILES)
CLIENT_OBJECTS = $(CLIENT_SOURCES:.c=.o)

HEADER = src/minitalk.h
SERVER_NAME = server
CLIENT_NAME = client
CC = cc
RM = rm -f
CFLAGS = -g -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(LIBFT) $(PRINTF) $(OBJECTS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(PRINTF) -o $(SERVER_NAME)
	
$(CLIENT_NAME): $(LIBFT) $(PRINTF) $(CLIENT_OBJECTS) $(HEADER)	
	$(CC) $(CFLAGS) $(CLIENT_OBJECTS) $(LIBFT) $(PRINTF) -o $(CLIENT_NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(PRINTF):
	$(MAKE) -C $(PRINTF_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(PRINTF_PATH) clean
	$(RM) $(OBJECTS) $(CLIENT_OBJECTS)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(PRINTF_PATH) fclean
	$(RM) $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: all clean fclean re libft printf
