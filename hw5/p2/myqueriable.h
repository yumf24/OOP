#pragma once

#include <functional>
#include <vector>
#include <iterator>

using namespace std;


template <typename T>
class MyQueriable {
    vector<T> data;
public:
    MyQueriable(vector<T> _data): data(_data) {}
    MyQueriable where(function<bool(T)> f);
    MyQueriable apply(function<T(T)> f);
    T sum();

    auto begin() {
        return data.begin();
    }
    auto end() {
        return data.end();
    }
};

template <typename T>
MyQueriable<T> MyQueriable<T>::where(function<bool(T)> f) {
    vector<T> result;
    for(auto i : data) {
        if(f(i)) result.push_back(i);
    }
    return MyQueriable(result);
}

template <typename T>
MyQueriable<T> MyQueriable<T>::apply(function<T(T)> f) {
    vector<T> result;
    for(auto i : data) {
        result.push_back(f(i));
    }
    return MyQueriable(result);
}

template <typename T>
T MyQueriable<T>::sum() {
    T result;
    for(auto i : data) {
        result += i;
    }
    return result;
}

// For container
template <typename Container>
MyQueriable<typename Container::value_type> from(const Container &c) {
    vector<typename Container::value_type> temp(begin(c), end(c));
    return MyQueriable<typename Container::value_type>(temp);
}
// For array
template <typename T, size_t N>
MyQueriable<T> from(T (&arr)[N]) {
    vector<T> temp(begin(arr), end(arr));
    return MyQueriable<T>(temp);
}