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
TEST_DIR = tests
BUILD_DIR = build
BIN_DIR = bin

# Source files
SRCS = $(SRC_DIR)/tensor.cc
MAIN_SRC = $(SRC_DIR)/main.hip
TEST_SRC = $(TEST_DIR)/test_tensor.cpp
MATMUL_SRC = $(SRC_DIR)/kernels/matmul.hip
OPS_GPU_SRC = $(OPS_DIR)/tensor_ops_gpu.hip
OPS_SRC = $(OPS_DIR)/ops.hip

# Object files
OBJS = $(BUILD_DIR)/tensor.o $(BUILD_DIR)/kernels/matmul.o $(BUILD_DIR)/ops/tensor_ops_gpu.o $(BUILD_DIR)/ops/ops.o
MAIN_OBJ = $(BUILD_DIR)/main.o
TEST_OBJ = $(BUILD_DIR)/test_tensor.o

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

# Build directories
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(BUILD_DIR)/kernels: | $(BUILD_DIR)
	@mkdir -p $@

$(BUILD_DIR)/ops: | $(BUILD_DIR)
	@mkdir -p $@

# Object files
$(BUILD_DIR)/tensor.o: $(SRC_DIR)/tensor.cc $(SRC_DIR)/tensor.h | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.hip $(SRC_DIR)/tensor.h | $(BUILD_DIR)
	$(HIPCC) $(HIPFLAGS) -c $< -o $@

$(BUILD_DIR)/test_tensor.o: $(TEST_DIR)/test_tensor.cpp $(SRC_DIR)/tensor.h | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/kernels/matmul.o: $(MATMUL_SRC) kernels/matmul.h | $(BUILD_DIR)/kernels
	$(HIPCC) $(HIPFLAGS) -c $< -o $@

$(BUILD_DIR)/ops/tensor_ops_gpu.o: $(OPS_GPU_SRC) $(SRC_DIR)/tensor.h ops/ops.h | $(BUILD_DIR)/ops
	$(HIPCC) $(HIPFLAGS) -c $< -o $@

$(BUILD_DIR)/ops/ops.o: $(OPS_SRC) $(SRC_DIR)/tensor.h kernels/matmul.h ops/ops.h | $(BUILD_DIR)/ops
	$(HIPCC) $(HIPFLAGS) -c $< -o $@

# Targets
$(MAIN_TARGET): $(OBJS) $(MAIN_OBJ) | $(BIN_DIR)
	$(HIPCC) $(HIPFLAGS) $^ -o $@ $(LDFLAGS)

$(TEST_TARGET): $(OBJS) $(TEST_OBJ) | $(BIN_DIR)
	$(HIPCC) $(HIPFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR)
