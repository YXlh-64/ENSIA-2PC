#include <iostream>
#include "singleList.h"
using namespace std;

int main(){
    singleList<int> L1;
    L1.add_end(5);
    L1.add_end(6);
    L1.add_end(7);
    L1.printList();
    L1.swapWithTheNext(L1.begin());
    L1.printList();
    return 0;
}