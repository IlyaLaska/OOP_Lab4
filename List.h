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
    const char* name;
    int amount = 0;
};

struct priceList {
    const char* name;
    int price = 0;
};

struct selectionList {
    const char* name;
    bool flag = false;
};

template <class T>
class List {
private:
    int arrLength = 0;//total elements
    int size = 0;//elements in use
public:
    T* list = new T[arrLength];
    List() = delete;
//    {DL std::cout << "Default List created" << std:: endl;};
    explicit List(int length);
    List(List& other);//copy constructor
//    List(List&& other) noexcept;//move constructor
    ~List();

    const T operator[](int pos) const;
    T& operator[](int pos);

    void push(T value);
    inline const int length() const {return arrLength;};
};

template<class T>
List<T>::List(int len): arrLength(len), size(0) {
    DL std::cout << "Param List created with length: " << arrLength << std::endl;
//    this->arrLength = len;
//    this->size = 0;
//    delete[] list;
    list = new T[arrLength];
}


template<class T>
const T List<T>::operator[](int pos) const {
//    cout << "[] operator called!" << endl;
    if(pos < 0) {
        throw std::out_of_range("Keep your dirty hands off of negative indexes, git!");
    } else if(pos >= arrLength) {
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
    } else if(pos >= arrLength) {
        int newLength = pos+arrLength;
        T* newList = new T[newLength];
        for (int i = 0; i < arrLength; ++i) {
            newList[i] = list[i];
        }
//        for (int j = length; j < newLength; ++j) {
//            newList[j] = T{};
//        }
        this->arrLength = newLength;
        this->list = newList;
    }
    if(size <= pos) {
        size = pos+1;
    }
    return this->list[pos];
}

template<class T>
void List<T>::push(T value) {
    if(size >= arrLength) {
        int newLength = arrLength*2;
        T* newList = new T[newLength];
        for (int i = 0; i < arrLength; ++i) {
            newList[i] = list[i];
        }
        this->arrLength = newLength;
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

template<class T>
List<T>::List(List &other) {
    DL std::cout << "Copy constructor called" << std::endl;
    delete[] this->list;
    this->arrLength = other.arrLength;
    this->size = other.size;
//    T* newList = new T[arrLength];
    list = new T[arrLength];//TODO where does current list container go - memory leak?
    memcpy(list, other.list, (sizeof (T) * arrLength) );
//    for (int i = 0; i < arrLength; ++i) {
//        list[i] = other.list[i];
//    }
//    this->list = newList;
}

//template<class T>
//List<T>::List(List &&other) noexcept {
//    DL std::cout << "Move constructor called" << std::endl;
//    delete[] this->list;
//    this->arrLength = other.arrLength;
//    this->size = other.size;
////    T* newList = new T[arrLength];
//    list = new T[arrLength];//TODO where does current list container go - memory leak?
//    memcpy(list, other.list, (sizeof (T) * arrLength) );
////    for (int i = 0; i < arrLength; ++i) {
////        list[i] = other.list[i];
////    }
////    this->list = newList;
//}

//constexpr List<priceList>& List<priceList>::operator=(const List<priceList>&)

#endif //OOP_LAB4_LIST_H

