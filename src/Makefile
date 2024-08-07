GCC=g++
CFLAGS= -Wall -Wextra -Werror --std=c++17
TEST_FLAGS = -lgtest -lgtest_main -pthread
DEBUG_FLAGS = -g3

TEST_NAME = all
BUILD = build
PROJECT_NAME = s21_containers
TEST_FOLDER = tests
MAIN_DIR = .

SRCS = $(foreach dir, $(MAIN_DIR), $(wildcard $(dir)/*.cpp))
HEADER_FILES = $(foreach dir, $(MAIN_DIR), $(wildcard $(dir)/*.h))
SRCS_TEST = $(wildcard $(TEST_FOLDER)/*.cpp)

FILE_OBJ = $(SRCS:%.cpp=$(BUILD)/%.o)
# TESTS_OBJ = $(SRCS_TEST:%.cpp=$(BUILD)/%.o)
OBJ = $(FILE_OBJ) # $(TESTS_OBJ)

# LIB = lib$(PROJECT_NAME).a
TEST_TARGET = $(BUILD)/s21_containers_tests

test: test_build
	@$(TEST_TARGET)

all: $(OBJ) test

$(PROJECT_NAME).a: clean $(LIB)

# -L. $(LIB)
test_build: clean $(OBJ)
	@mkdir -p $(BUILD)
	@echo; echo "Running tests... "$(TEST_NAME); echo;
	@$(GCC) $(CFLAGS) $(SRCS_TEST) -o $(TEST_TARGET) $(TEST_FLAGS)

debug: clean
	@$(MAKE) test CFLAGS="$(DEBUG_FLAGS)"
	gdb $(TEST_TARGET)

$(BUILD)/%.o: %.cpp
	@mkdir -p $(@D)
	@$(GCC) $(CFLAGS) -c $< -o $@ $(HEADER_FILES)

$(LIB): $(FILE_OBJ)
	@$(AR) rcs $@ $^
	@ranlib $(MAIN_DIR)/$(LIB)

GCOVR := $(shell command -v gcovr 2> /dev/null)
ifeq ($(GCOVR),)
    GCOVR := ~/.local/bin/gcovr
endif
GCOV_FLAG=--coverage -lgcov
GCOV_REPORT=$(BUILD)/gcov_report/gcov_report.html

gcovr:
	@$(MAKE) test CFLAGS="$(CFLAGS) $(GCOV_FLAG)"
	@mkdir -p $(BUILD)/gcov_report
	gcovr $(TEST_TARGET)
	@gcovr --html-details $(GCOV_REPORT) 2>/dev/null || true
	@ln -s $(GCOV_REPORT) ./gcov_report.html || true
	@echo "Отчет сгенерирован в gcov_report.html"
	@rm -r $(BUILD)/*_t*.gc?? || true

val: clean test_build
	@valgrind -s --tool=memcheck --leak-check=yes $(TEST_FOLDER)/bin

clang-format:
	@clang-format -n $(SRCS) $(SRCS_TEST)
	@clang-format -i $(SRCS) $(SRCS_TEST)
	@clang-format -i $(HEADER_FILES)
	@clang-format -n $(SRCS) $(SRCS_TEST)

.PHONY: clean

clean:
	@$(RM) -f  *.gcda *.gcno $(BUILD)/*.gcda $(BUILD)/*.gcno $(TEST_TARGET)
	@$(RM) -f  $(MAIN_DIR)/*.o
	@$(RM) -f  $(TEST_FOLDER)/*.o
	@$(RM) -f  $(TEST_TARGET)
	@$(RM) -rf tests/gcovr
	@$(RM) -f  *.html
	@$(RM) -rf $(BUILD)
	@$(RM) -f *.dvi *.log *.pdf *.tar.gz
