//
// Created by illya on 11/14/2018.
//

#ifndef OOP_LAB4_WAITER_H
#define OOP_LAB4_WAITER_H

#include "Human.h"
#include "Client.h"

class Waiter: public Human {
public:
    Waiter();
    ~Waiter() = default;
    List<int> takeOrder(const Client* client, const List<priceList>& menu);//why do i need 1st const, not second
    void takeOrder(const Client* client, List<selectionList>& clientsOrder, const List<priceList>& menu);//why do i need 1st const, not second
    void fillOrders(List<selectionList>& clientsOrder, List<amountList>& orders);
    void bringOrder(Client* client);
    int bringCheque(List<selectionList>& clientsOrder, List<priceList>& menu);
    void clearTable(Client* client, List<selectionList>& clientsOrder, List<selectionList>& occupiedTables);
};


#endif //OOP_LAB4_WAITER_H
