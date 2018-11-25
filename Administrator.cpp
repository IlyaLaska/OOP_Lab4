//
// Created by illya on 11/14/2018.
//

#include "Administrator.h"
#include <cstring>
#include <iostream>
#include <iomanip>

#include "macros.h"

Administrator::Administrator(): Human() {
    this->name = "Administrator";
}

List<selectionList> Administrator::formReservedTablesList(List<selectionList>& reservedTables) {
//    int totalTablesAmount = reservedTables.length;
//    List<char*> reservedTables;
        //clearing old flags
    for (int j = 0; j < reservedTables.length; ++j) {
        reservedTables[j].flag = false;
    }
        //setting new flags
    int reservation;
    for (int i = 0; i < reservedTables.length; ++i) {
        reservation = rand()%10;
        if(!reservation) reservedTables[i].flag = true;
    }
    return reservedTables;
}

List<amountList> Administrator::orderIngredients(List<amountList> &chefDesiredIngredients, List<amountList> &availableIngredients, const List<priceList> &orderableIngredients, int &balance) {
//    availableIngredients = List<amountList>(chefDesiredIngredients.length);//initialised in constructor
    for (int i = 0; i < chefDesiredIngredients.length; ++i) {
//        availableIngredients[i].name = strdup(chefDesiredIngredients[i].name);//done in constructor
        availableIngredients[i].amount += chefDesiredIngredients[i].amount;
        balance -= chefDesiredIngredients[i].amount * orderableIngredients[i].price;
        chefDesiredIngredients[i].amount = 0;
    }
    return availableIngredients;
}

void Administrator::updateBalance(Client *client, int &dailyProfit, int &balance) {
    dailyProfit += client->getCheque();
    balance += client->getCheque();
}

void Administrator::coutProfits(int& yesterdaysBalance, int &dailyProfit, int &balance, int& dailyExpenses) const {
    RL std::cout  << std::setw(70) << "Daily profits: " << std::endl;
    RL std::cout << "Balance at the start of the day: " << yesterdaysBalance << std::endl;
    RL std::cout << "Daily Income: " << dailyProfit << std::endl;
    RL std::cout << "Daily Expenses: " << dailyExpenses << std::endl;
    RL std::cout << "Daily Profit: " << dailyProfit - dailyExpenses << std::endl;
    RL std::cout << "Balance at the end of the day: " << balance << std::endl;
}

void Administrator::coutOrders(const List<amountList>& orders) const {
    RL std::cout << std::setw(70) << "Orders taken during the day:" << std::endl;
    for (int i = 0; i < orders.length; ++i) {
        RL std::cout << orders[i].name << ": " << orders[i].amount << std::endl;
    }
}

void Administrator::updateOrderLogs(const List<priceList>& menu, List<amountList> &orders, List<selectionList> &clientsOrder) {
    orders = List<amountList>(menu.length);
    clientsOrder = List<selectionList>(menu.length);
    for (int k = 0; k < menu.length; ++k) {
        orders[k].amount = 0;
        clientsOrder[k].flag = false;
        orders[k].name = strdup(menu[k].name);
        clientsOrder[k].name = strdup(menu[k].name);
    }
}
