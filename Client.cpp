//
// Created by illya on 11/14/2018.
//

//has hardcoded tablesAmount value

#include <cstdio>
#include "Client.h"

#include <cstring>

#include "macros.h"

#include <iostream>
//using namespace std;

int Client::clientPosition = 0;

Client::Client(): Human() {
    char clientPositionStr[10] = "";
    sprintf(clientPositionStr, "Client %i", clientPosition);
    clientPosition++;
    this->name = strdup(clientPositionStr);
    RL std::cout << name << " has arrived!" << std::endl;
    reservation = static_cast<bool>(rand() % 2);
    if(reservation) {
        reservedTable = rand()%20;
    }
}

void Client::leaveCoat() {
    if(wearingCoat) {
        wearingCoat = false;
        RL std::cout << name << ": I have left my coat at the cloakroom!" << std::endl;
    } else {
        RL std::cout << name << ": I have no coat to leave at the cloakroom!!!" << std::endl;
    }
}

void Client::takeCoat() {
    if(!wearingCoat) {
        wearingCoat = true;
        RL std::cout << this->name << ": I have taken my coat from the cloakroom!" << std::endl;
    } else {
        RL std::cout << name << ": I have no coat to take from the cloakroom!!!" << std::endl;
    }
}

bool Client::hasReservation() const {
    return reservation;
}

int Client::getReservedTable() const {
    return reservedTable;
}

const char *Client::getName() const {
    return name;
}

int Client::getTableNo() const {
    return tableNo;
}

void Client::setTableNo(int tableNo) {
    Client::tableNo = tableNo;
}

int Client::getCheque() const {
    return cheque;
}

void Client::setCheque(int cheque) {
    Client::cheque = cheque;
}
