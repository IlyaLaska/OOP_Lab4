//
// Created by illya on 11/15/2018.
//

#ifndef OOP_LAB4_FOODSupplier_H
#define OOP_LAB4_FOODSupplier_H

#include "List.h"

class FoodSupplier {
private:
    List<priceList> availableFood;
public:
    FoodSupplier();
    ~FoodSupplier() = default;
    const List<priceList> &getAvailableFood() const;
};


#endif //OOP_LAB4_FOODSupplier_H
