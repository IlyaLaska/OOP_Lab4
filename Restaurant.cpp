//
// Created by illya on 11/14/2018.
//

#include "Restaurant.h"
#include <ctime>
#include <cstdlib>
#include <cstring>

#include "macros.h"

#include <iostream>

using namespace std;

Restaurant::Restaurant(): reservedTables(new List<selectionList>(tablesAmount)), occupiedTables(new List<selectionList>(tablesAmount)) {
    srand(static_cast<unsigned int>(time(NULL)));
    //forming reservedTables here since it only has to be done once and only updated every day by administrator
//    reservedTables = new List<selectionList>(tablesAmount);
//    occupiedTables = new List<selectionList>(tablesAmount);
    //filling reservedTables & occupiedTables
    char buffer[6];
    for (int j = 0; j < tablesAmount; ++j) {
        (*reservedTables)[j].flag = false;
        (*occupiedTables)[j].flag = false;
        sprintf(buffer, "%i", j + 1);
        if (j == 0) strcat(buffer, "st");
        if (j == 1) strcat(buffer, "nd");
        if (j == 2) strcat(buffer, "rd");
        if (j > 2) strcat(buffer, "th");
        (*reservedTables)[j].name = strdup(buffer);
        (*occupiedTables)[j].name = strdup(buffer);
    }

//    headwaiter = Headwaiter();
//    waiter = Waiter();
//    chef = Chef();
//    administrator = Administrator();
//    foodSupplier = FoodSupplier();
//    foodSupplier.fillOrederableIngredients(orderableIngredients);
    orderableIngredients = new List<priceList>(foodSupplier.getAvailableFood());
    availableIngredients = new List<amountList>(orderableIngredients->length());
    chefDesiredIngredients = new List<amountList>(orderableIngredients->length());
    for (int l = 0; l < orderableIngredients->length(); ++l) {
        (*availableIngredients)[l].name = strdup((*orderableIngredients)[l].name);
        (*chefDesiredIngredients)[l].name = strdup((*orderableIngredients)[l].name);
        (*availableIngredients)[l].amount = 0;
        (*chefDesiredIngredients)[l].amount = 0;
    }
    chefDesiredIngredients = new List<amountList>(orderableIngredients->length());
    chef.orderIngredients((*chefDesiredIngredients), (*orderableIngredients));

    administrator.orderIngredients((*chefDesiredIngredients), (*availableIngredients), (*orderableIngredients), balance);
    menu = chef.generateMenu((*availableIngredients), (*orderableIngredients));//TODO will this cause memory leaks?
    administrator.formReservedTablesList((*reservedTables));

    orders = new List<amountList>(menu->length());
    clientsOrder = new List<selectionList>(menu->length());
    //filling orders & clientsOrder(template)
    for (int k = 0; k < menu->length(); ++k) {
        (*orders)[k].amount = 0;
        (*clientsOrder)[k].flag = false;
        (*orders)[k].name = strdup((*menu)[k].name);
        (*clientsOrder)[k].name = strdup((*menu)[k].name);
    }

    RL std::cout << "MENU:" << endl;
    for (int i = 0; i < menu->length(); ++i) {
        RL std::cout << menu->list[i].name << ": " << menu->list[i].price << endl;
    }
    RL std::cout << endl << "Balance: " << balance << endl;
}

const List<priceList> &Restaurant::getOrderableIngredients() const {
    return (*orderableIngredients);
}

void Restaurant::workOneDay() {
    int yesterdaysBalance = balance;
    int dailyProfit = 0;
    int dailyExpenses = 0;
    int balanceChange = 0;
    //roll d20, if > 10 new Client arrives
    int roll;
    int clientPossibilities = 15 * 6; //15 working hours * 6 customers per hour max
    int clearTable;//var to simulate the probability of one client leaving
    Client *client;// = new Client();
    for (int i = 0; i < clientPossibilities; ++i) {
        roll = rand() % 20;
        if (roll >= 10) {
            RL cout << endl;
            client = new Client();
            client->leaveCoat();
            bool freeTable = headwaiter.findTable(client, (*reservedTables), (*occupiedTables));
//            RL std::cout << "WAS THERE A TABLE: " << freeTable << std::endl;
            if (!freeTable) {
                RL std::cout << "There was no table for " << client->getName() << ", we are very sorry." << std::endl;
                goto noFreeTables;
            }
            headwaiter.callWaiter(client);
            waiter.takeOrder(client, (*clientsOrder), (*menu));
            waiter.fillOrders((*clientsOrder), (*orders));
            chef.prepareOrder((*clientsOrder), (*availableIngredients), (*menu));
            chef.checkForIngredientShortage((*availableIngredients), (*chefDesiredIngredients));
            balanceChange = balance;
            administrator.orderIngredients((*chefDesiredIngredients), (*availableIngredients), (*orderableIngredients),
                                           balance);
            balanceChange -= balance;
            dailyExpenses += balanceChange;
            waiter.bringOrder(client);
            client->setCheque(waiter.bringCheque((*clientsOrder), (*menu)));
            administrator.updateBalance(client, dailyProfit, balance);
            waiter.clearTable(client, (*clientsOrder), (*occupiedTables));

            //if there were no free tables or after meal
            noFreeTables:
            client->takeCoat();
            headwaiter.bidFarewell(client);
//            cout << "AM HERE" << endl;
            delete client;
            RL cout << endl;
        }//END: roll >= 10 a.k.a. client arrived
    }//END: for i < clientPossibilities - end of the working hours
    administrator.coutOrders((*orders));
    administrator.coutProfits(yesterdaysBalance, dailyProfit, balance, dailyExpenses);
    administrator.formReservedTablesList((*reservedTables));

    //TODO understand if this part is stupid or not (memory leaks - wise)
    delete menu;
    menu = chef.generateMenu((*availableIngredients), (*orderableIngredients));
    orders = administrator.updateOrders(menu, orders);
    clientsOrder = administrator.updateClientsOrder(menu, clientsOrder);
}

Restaurant::~Restaurant() {
//    menu.~List();
//    orderableIngredients.~List();
//
//    availableIngredients.~List();
//    chefDesiredIngredients.~List();//filled by chef at the end of the day. Administrator copies it to availableIngredients
//
//    reservedTables.~List();
//    occupiedTables.~List();
//
//    orders.~List();//copy menu here increment amount on order
//    clientsOrder.~List();

}











//List<amountList> Restaurant::orderIngredients() {
////    srand(static_cast<unsigned int>(time(NULL)));
//    int availableIngredientsAmount = (rand()%10) + 25;
//    List<amountList> availableIngredients(15);
//    for (int j = 0; j < 15; ++j) {
//        availableIngredients.list[j].name = strdup(orderableIngredients.list[j].name);
//    }
//    int ingredientPos = 0;//what position to get from supplier (orderableIngredients)
//    int totalPrice = 0;
//    for (int i = 0; i < availableIngredientsAmount*6; ++i) {
//        ingredientPos = rand()%15;//get value 0-14
//        totalPrice += orderableIngredients.list[ingredientPos].price;
//        availableIngredients.list[ingredientPos].amount++;
//    }
//    balance -= totalPrice;
//    return availableIngredients;
//}



/*/
int usedPos[availableIngredientsAmount];//creating array to store all names to weed out duplicates
for (int k = 0; k < availableIngredientsAmount; ++k) {//filling it with -1 to not get false positives on check
usedPos[k] = -1;
}

for (int j = 0; j < availableIngredientsAmount; ++j) {//go through usedPos, if found same value reroll loop iteration
            if(usedPos[j] == ingredientPos) {
                i--;
                continue;
            }
        }
        usedPos[i] = ingredientPos;
//*/