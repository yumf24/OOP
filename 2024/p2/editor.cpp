#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include<tuple>

#include "editor.h"

using namespace std;

TextEditor::TextEditor() {
    data.resize(400);
    cursor = make_pair(0,0);
    row = 0;
}

void TextEditor::move(Position dest) {
    if(dest.first < 0) {
        dest.first = cursor.first + dest.first;
    }
    if(dest.second < 0) {
        dest.second = cursor.second + dest.second;
    }
    if(dest.first > row) {
        cursor.first = row;
    }
    else {
        cursor.first = dest.first;
    }

    if(dest.second >= data[cursor.first].size()) {
        cursor.second = data[cursor.first].size();
    }
    else {
        cursor.second = dest.second;
    }
}

void TextEditor::write(const string& str) {
    tuple<vector<string>, Position, int> oldstate;
    oldstate = make_tuple(data, cursor, row);
    history.push_back(oldstate);

    string new_string = "";
    string raw_string = data[cursor.first];
    new_string += raw_string.substr(0, cursor.second);
    new_string += str;
    new_string += raw_string.substr(cursor.second);
    data[cursor.first] = new_string;
    cursor.second += str.size();
}

void TextEditor::newline() {
    string curr_row = data[cursor.first];
    tuple<vector<string>, Position, int> oldstate;
    oldstate = make_tuple(data, cursor, row);
    history.push_back(oldstate);

    if(cursor.second < curr_row.size()) {
        // 行中
        //全体下移
        for(int i = row; i > cursor.first; --i) {
            data[i+1] = data[i];
        }

        string new_string = curr_row.substr(0, cursor.second);
        string l_string = curr_row.substr(cursor.second);
        data[cursor.first] = new_string;
        data[cursor.first+1] = l_string;
        row++;
        cursor.first++;
        cursor.second = 0;
    }
    else if (cursor.second == 0) {
        for(int i = row; i >= cursor.first; --i) {
            data[i+1] = data[i];
        }
        row++;
        data[cursor.first] = "";
        cursor.first++;
    }
    else {
        for(int i = row; i > cursor.first; --i) {
            data[i+1] = data[i];
        }
        data[cursor.first+1] = "";
        row++;
        cursor = make_pair(cursor.first+1, 0);
    }
}

void TextEditor::del() {
    tuple<vector<string>, Position, int> oldstate;
    oldstate = make_tuple(data, cursor, row);
    history.push_back(oldstate);
    if(cursor.second == 0) {
        // 行开头
        if(cursor.first != 0) {
            cursor.second = data[cursor.first-1].size();
            data[cursor.first-1] += data[cursor.first];
            // 全体上移
            for(int i = cursor.first; i < row; i++) {
                data[i] = data[i+1];
            }
            row--;
            cursor.first--;
        }
    }
    else {
        string new_string = "";
        string raw_string = data[cursor.first];
        new_string += raw_string.substr(0, cursor.second-1);
        new_string += raw_string.substr(cursor.second);
        data[cursor.first] = new_string;
        cursor.second--;
    }
}

void TextEditor::screenShot() {
    cout << "### SCREENSHOT BEGIN ###" << endl;
    for(int i = 0; i <= row; ++i) {
        if(i != cursor.first) {
            cout << data[i] << endl;
        }
        else {
            string raw_string = data[i];
            string new_string = raw_string.substr(0, cursor.second);
            new_string += "*";
            new_string += raw_string.substr(cursor.second);
            cout << new_string << endl;
        }
    }
    cout << "### SCREENSHOT END ###" << endl;

}
void TextEditor::undo() {
    if(history.size() != 0) {
        auto old = history.back();
        history.pop_back();
        data = get<0>(old);
        cursor = get<1>(old);
        row = get<2>(old);
    }

}

void TextEditor::apply(const std::string &opt) {
    istringstream iss(opt);
    string str;
    iss >> str;
    if(str == "SCREEN") {
        this->screenShot();
    }
    else if(str == "WRITE") {
        string write_str;
        iss >> write_str;
        this->write(write_str);
    }
    else if(str == "MOVE") {
        int r,c;
        iss >> r >> c;
        this->move(make_pair(r,c));
    }
    else if(str == "DELETE") {
        this->del();
    }
    else if(str == "NEWLINE") {
        this->newline();
    }
    else if(str == "UNDO") {
        this->undo();
    }

}