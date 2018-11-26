//
// Created by illya on 11/15/2018.
//

#include "FoodSupplier.h"
#include <iostream>

FoodSupplier::FoodSupplier() {
    int ingredientsForSale = 15;
    availableFood = new List<priceList>(ingredientsForSale);
    bool spam = false;
    if(!spam) availableFood->list = new priceList[availableFood->length()] {{"Fish", 14}, {"Beef", 17}, {"Pork", 15},
    {"Chicken", 12}, {"Venison", 20}, {"Lamb", 14}, {"Tomatoes", 8}, {"Cucumbers", 6}, {"Cabbages", 4},
    {"Apples", 10}, {"Bread", 5}, {"Cheese", 11}, {"Rice", 8}, {"Potatoes", 4}, {"Noodles", 6}};

    if(spam) availableFood->list = new priceList[availableFood->length()] {{"Spam", 14}, {"Spam", 17}, {"Spam", 15},
    {"Spam", 12}, {"Spam", 20}, {"Spam", 14}, {"Spam", 8}, {"Spam", 6}, {"Spam", 4},
    {"Spam", 10}, {"Spam", 5}, {"Eggs", 11}, {"Bacon", 8}, {"Spam", 4}, {"Spam", 6}};
}

List<priceList>& FoodSupplier::getAvailableFood() const {
    return (*availableFood);
}

void FoodSupplier::fillOrederableIngredients(List<priceList> *orderableIngredients) {
    orderableIngredients = new List<priceList>(availableFood->length());
    memcpy(orderableIngredients->list, availableFood->list, (sizeof (priceList) * availableFood->length()) );
}
