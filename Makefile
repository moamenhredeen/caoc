CC = clang
CFLAGS = -Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-unused-label -Wno-unused-value -Wno-unused-attribute -Wno-unused-type -Wno-unused-value-argument -Wno-unused-value-parameter -Wno-unused-value-function -Wno-unused-value-label -Wno-unused-value-attribute -Wno-unused-value-type -Wno-unused-value-type-argument -Wno-unused-value-type-parameter -Wno-unused-value-type-function -Wno-unused-value-type-label -Wno-unused-value-type-attribute -Wno-unused-value-type-type -Wno-unused-value-type-type-argument -Wno-unused-value-type-type-parameter -Wno-unused-value-type-type-function -Wno-unused-value-type-type-label -Wno-unused-value-type-type-attribute -Wno-unused-value-type-type-type
BUILD_DIR = build

# build all and run test
build:
	$(CC) **/solution.c $(CFLAGS) -o $(BUILD_DIR)/build

test:
	$(CC) **/test.c $(CFLAGS) -o $(BUILD_DIR)/test

run_tests: test
	./$(BUILD_DIR)/test

# clean
clean:
	rm -rf $(BUILD_DIR)