//
// Created by illya on 11/14/2018.
//

#ifndef OOP_LAB4_ADMINISTRATOR_H
#define OOP_LAB4_ADMINISTRATOR_H

#pragma once

#include "Human.h"
#include "List.h"
#include "Client.h"

class Administrator: public Human {
public:
    Administrator();
    ~Administrator() = default;
    void formReservedTablesList(List<selectionList>& reservedTables);
    void orderIngredients(List<amountList> &chefDesiredIngredients, List<amountList> &availableIngredients, const List<priceList> &orderableIngredients, int &balance);
    void updateBalance(Client* client, int& dailyProfit, int& balance);
    void coutProfits(int& yesterdaysBalance, int& dailyProfit, int& balance, int& dailyExpenses) const;
    void coutOrders(const List<amountList>& orders) const;
    void updateOrderLogs(const List<priceList>* menu, List<amountList>* orders, List<selectionList>* clientsOrder);
    List<amountList>* updateOrders(const List<priceList>* menu, List<amountList>* orders);
    List<selectionList>* updateClientsOrder(const List<priceList>* menu, List<selectionList>* clientsOrder);
};


#endif //OOP_LAB4_ADMINISTRATOR_H
