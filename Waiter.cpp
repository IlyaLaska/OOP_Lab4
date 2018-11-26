//
// Created by illya on 11/14/2018.
//

#include "Waiter.h"

#include "macros.h"

#include <iostream>
using namespace std;

Waiter::Waiter() : Human() {
    this->name = "Waiter";

}

List<int> Waiter::takeOrder(const Client *client, const List<priceList>& menu) {
    int dishesAmount = (rand()%3) + 1;//can order 1-3 dishes
    List<int> orderCodes(dishesAmount);
    for (int i = 0; i < dishesAmount; ++i) {
        int dish = rand()%menu.length();//choose one from menu
        orderCodes[i] = dish;
    }
    return orderCodes;
}

void Waiter::takeOrder(const Client *client, List<selectionList>& clientsOrder, const List<priceList>& menu) {
    int dishesAmount = (rand()%menu.length()) + 1;//can order 1 - menu.length( dishes
//    List<int> orderCodes(dishesAmount);
//    cout  << "menu.length(: " << menu.length( << endl;
    for (int i = 0; i < dishesAmount; ++i) {
        int dish = rand()%menu.length();//choose one from menu
//        cout << "DISH: " << dish << " || flag: " << clientsOrder[dish].flag << " || i: " << i << endl;
        if(clientsOrder[dish].flag) {
            i--;
            continue;
        }
        clientsOrder[dish].flag = true;
    }
//    return clientsOrder;
}

void Waiter::fillOrders(List<selectionList> &clientsOrder, List<amountList> &orders) {
    for (int i = 0; i < clientsOrder.length(); ++i) {
        if(clientsOrder[i].flag) orders[i].amount++;
    }
//    return orders;
}

void Waiter::bringOrder(Client *client) {
    RL std::cout << "The waiter brings " << client->getName() << " his order!" << std::endl;
}

int Waiter::bringCheque(List<selectionList>& clientsOrder, List<priceList>& menu) {
    int total = 0;
    for (int i = 0; i < menu.length(); ++i) {
        if(clientsOrder[i].flag) total += menu[i].price;
    }
    int compulsory20PercentTipBecauseWeAreDicks = static_cast<int>(total * 0.2);
    return total+compulsory20PercentTipBecauseWeAreDicks;
}

void Waiter::clearTable(Client* client, List<selectionList>& clientsOrder, List<selectionList>& occupiedTables) {
    for (int i = 0; i < clientsOrder.length(); ++i) {
        clientsOrder[i].flag = false;
    }
    occupiedTables[client->getTableNo()].flag = false;
}
