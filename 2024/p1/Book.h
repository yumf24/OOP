#pragma once

#include <string>
#include <iostream>

using namespace std;

template<class T>
class Book {
private:
    string book_name, author;
    T pages;
public:
    Book(string _book_name, string _author, T _pages): book_name(_book_name), author(_author), pages(_pages) {}

    void show() {
        cout << "Book name: " << book_name << ", Author: " << author << ", Pages: " << pages << endl;
    }

    bool operator<(const Book<T>& other) {
        return (pages < other.pages);
    }

    string getTitle() {
        return book_name;
    }
};