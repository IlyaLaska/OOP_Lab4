//
// Created by illya on 11/14/2018.
//

#ifndef OOP_LAB4_RESTAURANT_H
#define OOP_LAB4_RESTAURANT_H

#pragma once

#include "List.h"
#include "Headwaiter.h"
#include "Waiter.h"
#include "Chef.h"
#include "Administrator.h"
#include "FoodSupplier.h"
#include "Client.h"


class Restaurant {
private:
//    int clientCounter;
    int tablesAmount = 20;
    int balance = 0;

    List<priceList> menu;
    List<priceList> orderableIngredients;

    List<amountList> availableIngredients;
    List<amountList> chefDesiredIngredients;//filled by chef at the end of the day. Administrator copies it to availableIngredients

    List<selectionList> reservedTables;
    List<selectionList> occupiedTables;

    List<amountList> orders;//copy menu here increment amount on order
    List<selectionList> clientsOrder;

    Headwaiter headwaiter;
    Waiter waiter;
    Chef chef;
    Administrator administrator;
    FoodSupplier foodSupplier;
public:
    Restaurant();
    ~Restaurant();
    const List<priceList> &getOrderableIngredients() const;
    void workOneDay();
//    List<amountList> orderIngredients();
};


#endif //OOP_LAB4_RESTAURANT_H
