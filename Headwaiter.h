//
// Created by illya on 11/14/2018.
//

#ifndef OOP_LAB4_HEADWAITER_H
#define OOP_LAB4_HEADWAITER_H

#include "Human.h"
#include "Client.h"

class Headwaiter: public Human {
public:
    Headwaiter();
    ~Headwaiter() = default;
    bool findTable(Client* client, List<selectionList>& reservedTables, List<selectionList>& occupiedTables);
    void callWaiter(const Client* client) const;
    void bidFarewell(Client* client);
};


#endif //OOP_LAB4_HEADWAITER_H
