CXX = g++
HIPCC = hipcc

# ROCm / HIP includes for LSP (nvim/clangd) and compilation
ROCM_PATH ?= /opt/rocm
ROCM_FLAGS = -I$(ROCM_PATH)/include \
             -D__HIP_PLATFORM_AMD__= \
             -D__HIP_PLATFORM_HCC__=

CXXFLAGS = -std=c++11 -Wall -Wextra -I. $(ROCM_FLAGS)
HIPFLAGS = -std=c++11 -Wall -Wextra -I. $(ROCM_FLAGS)
LDFLAGS  = -L$(ROCM_PATH)/lib -lamdhip64

# Directories
SRC_DIR = .
OPS_DIR = ops
KERNELS_DIR = kernels
TEST_DIR = tests
BUILD_DIR = build
BIN_DIR = bin

# Auto-detect source files
SRCS_CC  := $(wildcard $(SRC_DIR)/*.cc)
SRCS_HIP := $(wildcard $(SRC_DIR)/*.hip) $(wildcard $(SRC_DIR)/$(KERNELS_DIR)/*.hip) $(wildcard $(SRC_DIR)/$(OPS_DIR)/*.hip)
TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)

# Object files (mirror directory structure inside build/)
OBJS_CC  := $(patsubst $(SRC_DIR)/%.cc,$(BUILD_DIR)/%.o,$(SRCS_CC))
OBJS_HIP := $(patsubst $(SRC_DIR)/%.hip,$(BUILD_DIR)/%.o,$(SRCS_HIP))
OBJS     := $(OBJS_CC) $(OBJS_HIP)

MAIN_OBJ  := $(BUILD_DIR)/main.o
TEST_OBJS := $(patsubst $(TEST_DIR)/%.cpp,$(BUILD_DIR)/tests/%.o,$(TEST_SRCS))

# Targets
MAIN_TARGET = $(BIN_DIR)/main
TEST_TARGET = $(BIN_DIR)/test

.PHONY: all main test clean

all: main test

main: $(MAIN_TARGET)
	@echo "Running main..."
	@$(MAIN_TARGET)

test: $(TEST_TARGET)
	@echo "Running tests..."
	@$(TEST_TARGET)

# Build directories (auto-create any needed subdirectory)
$(BUILD_DIR):
	@mkdir -p $@

$(BUILD_DIR)/$(KERNELS_DIR): | $(BUILD_DIR)
	@mkdir -p $@

$(BUILD_DIR)/$(OPS_DIR): | $(BUILD_DIR)
	@mkdir -p $@

$(BUILD_DIR)/$(TEST_DIR): | $(BUILD_DIR)
	@mkdir -p $@

# Pattern rules for .cc files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Pattern rules for .hip files in any subdir
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.hip | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	$(HIPCC) $(HIPFLAGS) -c $< -o $@

# Pattern rules for test files
$(BUILD_DIR)/tests/%.o: $(TEST_DIR)/%.cpp | $(BUILD_DIR)/$(TEST_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Targets
$(MAIN_TARGET): $(filter-out $(MAIN_OBJ),$(OBJS)) $(MAIN_OBJ) | $(BIN_DIR)
	$(HIPCC) $(HIPFLAGS) $^ -o $@ $(LDFLAGS)

# Test target: links all objects (except main.o) with test objects
$(TEST_TARGET): $(filter-out $(MAIN_OBJ),$(OBJS)) $(TEST_OBJS) | $(BIN_DIR)
	$(HIPCC) $(HIPFLAGS) $^ -o $@ $(LDFLAGS)

$(BIN_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR)
