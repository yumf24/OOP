# 1. 基础配置
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGET = main

# 2. 定义源文件和目标文件
SRCS = main.cpp normal_smithing_stone.cpp somber_smithing_stone.cpp normal_weapon.cpp somber_weapon.cpp tarnished.cpp weapon.cpp smithing_stone.cpp
# 自动生成依赖文件（追踪 .h 文件的变化）
DEP_FLAGS = -MMD -MP

# 3. 定义不同模式的路径
BUILD_DIR = build
DEBUG_DIR = $(BUILD_DIR)/debug
RELEASE_DIR = $(BUILD_DIR)/release

# 4. 根据模式设置变量
# 默认模式是 Release
OBJ_DIR = $(RELEASE_DIR)
OBJS = $(SRCS:%.cpp=$(RELEASE_DIR)/%.o)

# 如果执行的是 make debug
ifeq ($(firstword $(MAKECMDGOALS)), debug)
	OBJ_DIR = $(DEBUG_DIR)
	CXXFLAGS += -g
	TARGET = main_debug
	OBJS = $(SRCS:%.cpp=$(DEBUG_DIR)/%.o)
endif
 
# 5. 主要规则
.PHONY: all debug clean

all: $(TARGET)

debug: $(TARGET)

# 链接
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(DEP_FLAGS) -c $< -o $@

# 引入自动生成的 .d 依赖文件
-include $(OBJS:.o=.d)

# 6. 清理
clean:
	rm -rf $(BUILD_DIR) $(TARGET) main_dnormal_smithing_stoneesomberrmal_smithing_stonein_dnormal_smithing_stoneesomberrmal_smithing_stonee