//
// Created by illya on 11/14/2018.
//

#include "Headwaiter.h"
#include <iostream>

#include "macros.h"

Headwaiter::Headwaiter() : Human() {
    this->name = "Headwaiter";
}

bool Headwaiter::findTable(Client* client, List<selectionList>& reservedTables, List<selectionList>& occupiedTables) {
    if(client->hasReservation()) {//reservation
        if(reservedTables[client->getReservedTable()].flag) {//actual reservation
            //put him at the table he desires, clear reserved plaque from that table
            occupiedTables[client->getReservedTable()].flag = true;
            reservedTables[client->getReservedTable()].flag = false;
            client->setTableNo(client->getReservedTable());
        } else {//fake reservation
            RL std::cout << client->getName() << " has tried to lie about his reservation. SHAME!" << std::endl;
            goto noReservation;
        }
    } else {//no reservation / fake reservation
        noReservation:
        bool hasFreeTable = false;
        for (int j = 0; j < occupiedTables.length; ++j) {
            if(!occupiedTables[j].flag && !reservedTables[j].flag) {//table not occupied & not reserved
                occupiedTables[j].flag = true;
                client->setTableNo(j);
                hasFreeTable = true;
                break;
            }
        }
        if(!hasFreeTable) return false;//goto noFreeTables;
    }//END: no reservation
//    RL std::cout << "TESTTAWRWRA: " << client->getTableNo() << std::endl;
    return true;
}

void Headwaiter::callWaiter(const Client* client) const {
    RL std::cout << "The waiter was called for " << client->getName() << std::endl;
}

void Headwaiter::bidFarewell(Client *client) {
    RL std::cout << "Thank You for being our guest, " << client->getName() << ", we hope to see You again!" << std::endl;
}
