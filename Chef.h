//
// Created by illya on 11/14/2018.
//

#ifndef OOP_LAB4_CHEF_H
#define OOP_LAB4_CHEF_H

//#pragma once

#include "Human.h"
#include "List.h"
//#include "Restaurant.h"

//class Restaurant;

class Chef: public Human {
private:

public:
    Chef();
    ~Chef() = default;
    priceList generateDish(List<amountList> availableIngredients, List<priceList> orderableIngredients);
    List<priceList> generateMenu(List<amountList> availableIngredients, List<priceList> orderableIngredients);
    List<amountList> orderIngredients(List<amountList>& chefDesiredIngredients, const List<priceList> orderableIngredients);
    void prepareOrder(List<selectionList> clientsOrder, List<amountList>& availableIngredients, List<priceList> menu);
    List<amountList> checkForIngredientShortage(List<amountList>& availableIngredients, List<amountList> &chefDesiredIngredients);
};


#endif //OOP_LAB4_CHEF_H
