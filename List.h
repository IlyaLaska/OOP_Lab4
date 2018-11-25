//
// Created by illya on 11/14/2018.
//

#ifndef OOP_LAB4_LIST_H
#define OOP_LAB4_LIST_H

#include <stdexcept>

#include "macros.h"

#include <iostream>
using namespace std;

struct amountList {
    const char* name{};
    int amount = 0;
};

struct priceList {
    const char* name{};
    int price = 0;
};

struct selectionList {
    const char* name{};
    bool flag = false;
};

template <class T>
class List {
private:
public:
    int length = 0;//total elements
    int size = 0;//elements in use
    T* list = new T[length];
    List() {
        DL std::cout << "Default List created" << std:: endl;
    };
    explicit List(int length);
//    List(List& other);
    ~List();
    const T operator[](int pos) const;
    T& operator[](int pos);
    void push(T value);

};

template<class T>
List<T>::List(int length): length(length) {
    DL std::cout << "Param List created with length: " << length << std::endl;
//    this->length = length;
    this->size = 0;
    this->list = new T[length];
}


template<class T>
const T List<T>::operator[](int pos) const {
//    cout << "[] operator called!" << endl;
    if(pos < 0) {
        throw std::out_of_range("Keep your dirty hands off of negative indexes, git!");
    } else if(pos >= length) {
        throw std::out_of_range("Keep your dirty hands off of excessively large indexes, git!");
    }
    return this->list[pos];
}

template<class T>
T& List<T>::operator[](int pos) {
//    cout << "[] operator called!" << endl;
    if(pos < 0) {
//        std::cout << "Keep your dirty hands off of negative elements, git!" << std::endl;
        throw std::out_of_range("Keep your dirty hands off of negative elements, git!");
//        T temp = T{};
//        cout << temp << endl;
//        return temp;
    } else if(pos >= length) {
        int newLength = pos+length;
        T* newList = new T[newLength];
        for (int i = 0; i < length; ++i) {
            newList[i] = list[i];
        }
//        for (int j = length; j < newLength; ++j) {
//            newList[j] = T{};
//        }
        this->length = newLength;
        this->list = newList;
    }
    if(size <= pos) {
        size = pos+1;
    }
    return this->list[pos];
}

template<class T>
void List<T>::push(T value) {
    if(size >= length) {
        int newLength = length*2;
        T* newList = new T[newLength];
        for (int i = 0; i < length; ++i) {
            newList[i] = list[i];
        }
        this->length = newLength;
        this->list = newList;

    }
    list[size] = value;
    size++;
}

template<class T>
List<T>::~List() {
    DL std::cout << "List deleted" << std::endl;
    delete[] this->list;
}

//template<class T>
//List<T>::List(List &other) {
//    DL std::cout << "Copy constructor called" << std::endl;
//    delete this->list;
//    this->length = other.length;
//    this->size = other.size;
//    T* newList = new T[length];
//    for (int i = 0; i < length; ++i) {
//        newList[i] = other.list[i];
//    }
//    this->list = newList;
//    other.~List();
//}


#endif //OOP_LAB4_LIST_H

