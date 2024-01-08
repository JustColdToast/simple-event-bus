# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++20 -g -Wextra -Wall 
LDFLAGS := -L/opt/homebrew/lib -lssl -lcrypto

# Directories
SRC_DIR := ./src
BUILD_DIR := ./build
BIN_DIR := ./bin

# Find all source files
SRCS := $(wildcard $(SRC_DIR)/**/*.cc $(SRC_DIR)/*.cc)

# Create object file names from source file names
OBJS := $(patsubst $(SRC_DIR)/%.cc,$(BUILD_DIR)/%.o,$(SRCS))

# Create dependency file names from object file names
DEPS := $(OBJS:.o=.d)

# Include paths
INC := -I$(SRC_DIR) -I/opt/homebrew/include # include path

# Compiler flags for dependency generation
DEPFLAGS = -MT $@ -MMD -MP -MF $(BUILD_DIR)/$*.d

# Main target
TARGET := simple-event-bus

# Build rules
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INC) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INC) $(DEPFLAGS) -c -o $@ $<

# Create directories if they don't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Include dependency files
-include $(DEPS)

# Clean rule
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(TARGET)