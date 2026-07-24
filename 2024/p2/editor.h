#ifndef Editor_H
#define Editor_H

#include <vector>
#include <string>
#include <tuple>

// 你可以根据需要修改此文件
using namespace std;

class TextEditor
{
private:
    using Position = std::pair<int, int>;
    vector<std::string> data;
    int row;
    Position cursor;
    vector<tuple<vector<string>, Position, int>> history;

public:
    TextEditor();
    void move(Position dest);
    void write(const std::string &str);
    void newline();
    void del();
    void screenShot();
    void undo();
    void apply(const std::string &opt);
};

#endif // Editor_H
