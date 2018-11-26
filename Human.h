//
// Created by illya on 11/14/2018.
//

#ifndef OOP_LAB4_HUMAN_H
#define OOP_LAB4_HUMAN_H


#include "macros.h"

#include <iostream>
using namespace std;

class Human {
protected:
    const char* name;
public:
    Human() { DL cout << "Human created" << endl;};
    ~Human()  {
//        delete name;//TODO should not delete that due to read-only memory?
        DL cout << "Human destroyed" << endl;
    };
};


#endif //OOP_LAB4_HUMAN_H
