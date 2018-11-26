//
// Created by illya on 11/14/2018.
//

#include "Chef.h"

#include <cstdlib>
#include <ctime>
#include <cstring>

#include <iostream>
using namespace std;


Chef::Chef(): Human() {
    this->name = "Chef";
}


priceList Chef::generateDish(List<amountList>& availableIngredients, List<priceList>& orderableIngredients) {
    priceList dish = {new char[100], 0};
    int ingredientsAmount = (rand()%5) + 2;
    int ingredientPos = 0;
    char buffer[200] = "";
    for (int i = 0; i < ingredientsAmount; ++i) {
//        strcpy(buffer, "");
        ingredientPos = (rand()%15);
//        DL cout << availableIngredients.list[ingredientPos].name << endl;
        strcat(buffer, availableIngredients.list[ingredientPos].name);
        if(i < ingredientsAmount-1) strcat(buffer, " and ");
        dish.price += orderableIngredients.list[ingredientPos].price;
    }
//    cout << "Buffer:" << availableIngredients.list[ingredientPos].name << endl;
    dish.price += ingredientsAmount*10;//random price increase specifier
    dish.name = strdup(buffer);
//    cout << "DISH:" << dish.name << ": " << dish.price << endl;
    return dish;
}

List<priceList>* Chef::generateMenu(List<amountList>& availableIngredients, List<priceList>& orderableIngredients) {//TODO this sucks
    int dishesAmount = (rand()%14) + 2;
    List<priceList>* menu = new List<priceList>(dishesAmount);
    for (int i = 0; i < dishesAmount; ++i) {
        menu->list[i] = generateDish(availableIngredients, orderableIngredients);
    }
    return menu;
}

void Chef::orderIngredients(List<amountList>& chefDesiredIngredients, const List<priceList>& orderableIngredients) {
    int availableIngredientsAmount = (rand()%10) + 25;
    int ingredientPos = 0;//what position to get from supplier (orderableIngredients)
    for (int i = 0; i < availableIngredientsAmount*6; ++i) {
        ingredientPos = rand()%chefDesiredIngredients.length();//get value 0-14
        chefDesiredIngredients[ingredientPos].amount++;
    }
//    return chefDesiredIngredients;
}

void Chef::prepareOrder(List<selectionList>& clientsOrder, List<amountList>& availableIngredients, List<priceList>& menu) {
    char delim[2] = " ";
    char* token;
    char buffer[200];
    for (int i = 0; i < clientsOrder.length(); ++i) {
        strcpy(buffer, menu[i].name);
        token = strtok(buffer, delim);
        while (token != nullptr) {
            if(strcmp(token, "and") != 0) {//token is an ingredient name
                for (int j = 0; j < availableIngredients.length(); ++j) {
                    if(strcmp(token, availableIngredients[j].name) == 0) {//token is THE ingredient
                        availableIngredients[j].amount--;
                        break;
                    }
                }
            }
            token = strtok(nullptr, delim);
        }
    }
}

void Chef::checkForIngredientShortage(List<amountList> &availableIngredients, List<amountList> &chefDesiredIngredients) {
    for (int i = 0; i < availableIngredients.length(); ++i) {
        if(availableIngredients[i].amount < 5) {//need to order more
            chefDesiredIngredients[i].amount += 10;
        }
    }
//    return chefDesiredIngredients;
}

