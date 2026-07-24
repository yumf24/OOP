# ArgParser - C++ 命令行参数解析库

## 作者信息

- 姓名：余绵峯
- 班级：计52
- 更新日期：2026.5.16
- 联系电话：17325789551

---

## 项目概述

ArgParser 是一个轻量级的 C++ 命令行参数解析库，采用面向对象设计，支持常见的命令行参数解析需求。

### 主要特性

- 支持 **短参数名** (如 `-v`) 和 **长参数名** (如 `--verbose`)
- 支持 **Flag 参数**（布尔开关）和 **Value 参数**（带值参数）
- **类型安全** 的模板参数设计
- 支持 **默认值** 设置
- **自动生成** 帮助信息
- 完善的 **错误处理** 机制

### 技术栈

- C++17
- 标准库组件：`std::optional`, `std::unique_ptr`, `std::map`, `std::vector`

---

## 架构设计

### 类继承关系

```
         IArgument (抽象基类)
              │
     ┌────────┴────────┐
     │                 │
FlagArgument    ValueArgument<T> (模板类)
```

### 类职责说明

| 类名 | 职责 |
|------|------|
| `IArgument` | 抽象基类，定义参数接口（`parse()`, `get_info()`, `is_flag()`） |
| `FlagArgument` | 布尔开关参数，如 `--verbose`，解析后值为 `true/false` |
| `ValueArgument<T>` | 模板值参数，如 `--file filename.txt`，支持任意类型 |
| `ArgParser` | 主解析器类，管理参数注册、解析、获取和帮助信息输出 |

---

## API 文档

### ArgParser 类

#### 构造函数

```cpp
ArgParser(const std::string& description)
```

创建解析器实例，参数为程序描述信息。

- 自动注册 `-h, --help` 帮助参数

#### 添加参数

```cpp
// 添加 Flag 参数
void addFlag(char short_name, const std::string& long_name, const std::string& description)

// 添加 Value 参数（模板方法）
template<typename T>
void addValue(char short_name, const std::string& long_name, const std::string& description, T default_value)
```

**参数说明：**
- `short_name`: 短参数名，单字符（如 `'v'`）
- `long_name`: 长参数名（如 `"verbose"`）
- `description`: 参数描述信息
- `default_value`: 默认值（仅 `addValue` 需要）

#### 解析参数

```cpp
bool parse(int argc, char* argv[])
```

解析命令行参数，返回 `true` 表示成功，`false` 表示解析失败。

#### 获取参数值

```cpp
template<typename T>
std::optional<T> get(const std::string& name) const
```

根据长参数名获取参数值，返回 `std::optional<T>`。

#### 帮助信息

```cpp
bool wantsHelp() const    // 检查是否请求帮助
void printHelp() const    // 打印帮助信息
```

---

## 使用示例

### 代码示例

```cpp
#include "argparser.h"

int main(int argc, char* argv[]) {
    // 创建解析器
    ArgParser parser("A simple program to demonstrate argument parsing.");

    // 定义参数
    parser.addFlag('v', "verbose", "Enable verbose output.");
    parser.addValue<std::string>('f', "file", "Path to the input file.", "default.txt");
    parser.addValue<int>('l', "level", "Set the logging level.", 5);

    // 解析命令行参数
    bool success = parser.parse(argc, argv);

    if (success) {
        // 处理帮助请求
        if (parser.wantsHelp()) {
            parser.printHelp();
            return 0;
        }

        // 获取参数值
        bool verbose = parser.get<bool>("verbose").value_or(false);
        std::string filename = parser.get<std::string>("file").value();
        int level = parser.get<int>("level").value();

        // 使用参数...
    } else {
        parser.printHelp();
    }
    return 0;
}
```

### 命令行用法

```bash
# 显示帮助
./main -h
./main --help

# 使用 Flag 参数
./main -v
./main --verbose

# 使用 Value 参数
./main -f input.txt -l 3
./main --file data.txt --level 10

# 组合使用
./main -v --file test.txt -l 7
```

### 输出示例

**正常执行：**
```
--- Parsed Arguments ---
Verbose: true
File: test.txt
Level: 7
```

**帮助信息：**
```
A simple program to demonstrate argument parsing.

Usage:
  -h, --help		Show this help message.
  -v, --verbose		Enable verbose output.
  -f, --file=<value>	Path to the input file. (default: default.txt)
  -l, --level=<value>	Set the logging level. (default: 5)
```

---

## 构建说明

### 编译命令

```bash
# 编译发布版本
make

# 编译调试版本
make debug
```

### 输出文件

- `main` - 发布版本可执行文件
- `main_debug` - 调试版本可执行文件

### 依赖要求

- C++17 兼容编译器 (g++ 或 clang++)
- 无外部依赖

---

## 文件结构

```
p4/
├── main.cpp          # 主程序入口
├── iargument.h       # 抽象基类接口
├── flagargument.h    # Flag 参数实现
├── valueargument.h   # Value 参数模板实现
├── argparser.h       # 主解析器类
└── Makefile          # 构建配置
```