#include <iostream>
using namespace std;
/*For a vending machine to return the change to the customer, it must return a
minimal number of coins. Write a recursive function to determine the number
of each type of coin to give back to the customer as part of the change.
(For example: 290 → 1x200DA + 1x50DA + 2x20DA)*/
void return_coins(int money){
    if(money == 5)
    {
        cout << "5 ";
        return;
    }
    if(money == 0) return;
    int coins[8] = {2000, 1000, 500, 200, 100, 50, 20, 10};
    for(int i=0; i<8; ++i)
        if(money >= coins[i])
        {
            cout << coins[i] << " + ";
            return_coins(money - coins[i]);
            return;
        }
}
int main(){

    return_coins(7360);
    cout << endl;
    cout << endl;
    return_coins(4560);
    cout << endl;

    return 0;
}