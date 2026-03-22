CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC_DIR = src
BIN_DIR = bin

PROGRAMS = cat echo grep wc

SRCS = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(PROGRAMS)))
BINS = $(addprefix $(BIN_DIR)/, $(PROGRAMS))

all: $(BIN_DIR) $(BINS)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(BIN_DIR)/%: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(BIN_DIR)

.PHONY: all clean