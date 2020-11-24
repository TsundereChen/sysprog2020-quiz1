.PHONY: clean
BUILD_DIR = build

all: build
clean:
	rm $(BUILD_DIR)/*.o *.out

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(@D)
	clang $(COPS) -g -c $< -o $@

C_FILES = $(wildcard *.c)
OBJ_FILES = $(C_FILES:%.c=$(BUILD_DIR)/%.o)

build: $(OBJ_FILES)
	clang -o a.out $(OBJ_FILES)
