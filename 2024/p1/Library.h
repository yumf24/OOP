#pragma once
#include <string>
#include <iostream>
#include <vector>

#include "Book.h"

using namespace std;



template<class T>
class Library {
private:
    vector<Book<T>> books;

public:
    void addBook(const Book<T>& book) {
        books.push_back(book);
    }

    void show() {
        for(auto i : books) {
            i.show();
        }
    }

    void borrowBook(const std::string& title) {
        for(auto i : books) {
            if(i.getTitle() == title) {
                cout << "Books Checked out " << title << "." << endl;
                return ;
            }
        }
        cout << "Book " << title << " does not exist." << endl;
    }
};