// HALL OF FAME:
/*
    int* a = new int{1};
    using govno  = int;
    a->~govno();
     */
//

#include <iostream>
#include <vector>

#include "List.h"
#include "Chef.h"
#include "Restaurant.h"
#include "Client.h"

#include <cstring>

using namespace std;
//TODO why crash on client 100 code -1073741819 (0xC0000005)
int main() {
    Restaurant rest = Restaurant();
    for (int i = 0; i < 5; ++i) {
        rest.workOneDay();
    }
//    chef.generateDish(rest.getOrderableIngredients());
//    FoodSupplier* test = new FoodSupplier();
//    cout << test->availableFood.list[0].name << endl;
//    cout << arr[1].name << std::endl;
//    List<amountList>* test = new List<amountList>(5);
//    test->list[0] = {"Fish", 2};
//    cout << test->list[0].amount << endl;

//    vector <int> vVec(5,10);
//    for (int x=0;x < 5;x++) cout << vVec[x] << endl;
//    vVec.insert(vVec.begin()+3, 5);
//    for (int x=0;x < 5;x++) cout << vVec[x] << endl;
//    if(!vVec.empty()) cout << "Not empty " << endl;
//    for (int x=0;x < 5;x++) cout << vVec[x] << endl;

//    for (int x=0;x < 5;x++) cout << vVec[x] << endl;
    return 0;
}