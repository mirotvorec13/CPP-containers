GCC=g++ --std=c++17
CFLAGS= -Wall -Wextra -Werror

TEST_NAME = all

PROJECT_NAME = s21_containers
TEST_FOLDER = tests
MAIN_DIR = .
SRCS = $(foreach dir, $(MAIN_DIR), $(wildcard $(dir)/*.cpp))
HEADER_FILES = $(foreach dir, $(MAIN_DIR), $(wildcard $(dir)/*.h))
SRCS_TEST = $(wildcard $(TEST_FOLDER)/*.cpp)
TEST_TARGET = $(TEST_FOLDER)/test_containers
TEST_FLAGS = -lgtest -lgtest_main -pthread -g3
FILE_OBJ = $(SRC:.cpp=.o)
TESTS_OBJ = $(SRCS_TEST:.cpp=.o)

LIB = lib$(PROJECT_NAME).a

test: test_build
	@$(TEST_TARGET)

all: $(PROJECT_NAME).a test


$(PROJECT_NAME).a: clean $(LIB)


test_build: $(TESTS_OBJ) $(LIB)
	@echo; echo "Running tests... "$(TEST_NAME); echo;
	@$(GCC) $(CFLAGS) -L. $(LIB) $^ -o $(TEST_TARGET) $(TEST_FLAGS)

%.o: %.cpp
	@$(GCC) -c $< -o $@

$(LIB): $(FILE_OBJ)
	@$(AR) rcs $@ $^
	@ranlib $(MAIN_DIR)/$(LIB)

val: test_build
	@valgrind -s --tool=memcheck --leak-check=yes $(TEST_TARGET)

clang-format:
	@clang-format -n $(SRCS) $(SRCS_TEST)
	@clang-format -i $(SRCS) $(SRCS_TEST)
	@clang-format -n $(SRCS) $(SRCS_TEST)

.PHONY: clean

clean:
	@$(RM) $(MAIN_DIR)/*.o
	@$(RM) $(TEST_FOLDER)/*.o
	@$(RM) $(TEST_TARGET)
	@$(RM) $(LIB)