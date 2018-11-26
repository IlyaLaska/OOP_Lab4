//
// Created by illya on 11/15/2018.
//

#ifndef OOP_LAB4_FOODSupplier_H
#define OOP_LAB4_FOODSupplier_H

#include "List.h"

class FoodSupplier {
private:
    List<priceList>* availableFood;
//    List<priceList> &availableFood = *availableFoodPtr;
public:
    FoodSupplier();
    ~FoodSupplier() = default;
    List<priceList>& getAvailableFood() const;
    void fillOrederableIngredients(List<priceList>* orderableIngredients);
};


#endif //OOP_LAB4_FOODSupplier_H
