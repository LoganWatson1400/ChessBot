CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Isrc/board/templechess-main/src

SRC_DIR = board/templechess-main/src
OBJ_DIR = obj

SRCS = rand_play.c \
       $(SRC_DIR)/BitBoard.c \
       $(SRC_DIR)/LookupTable.c \
       $(SRC_DIR)/ChessBoard.c \
       $(SRC_DIR)/MoveSet.c

OBJS = $(patsubst %.c,$(OBJ_DIR)/%.o,$(notdir $(SRCS)))

TARGET = rand_play

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

$(OBJ_DIR)/rand_play.o: rand_play.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

