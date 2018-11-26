//
// Created by illya on 11/14/2018.
//

#ifndef OOP_LAB4_CLIENT_H
#define OOP_LAB4_CLIENT_H

#include "Human.h"
#include "List.h"

#include <iostream>
using namespace std;

class Client: public Human {
private:
    static int clientPosition;
    bool wearingCoat = true;
    bool reservation = false;
    int reservedTable;
    int cheque;
//    List<priceList> order;
    int tableNo;
public:
    Client();
    ~Client() {DL cout << "Client destroyed" << endl;};
    void leaveCoat();
    void takeCoat();
    bool hasReservation() const;
    int getReservedTable() const;
    const char* getName() const;
    int getTableNo() const;
    void setTableNo(int tableNo);
    int getCheque() const;
    void setCheque(int cheque);
};


#endif //OOP_LAB4_CLIENT_H
