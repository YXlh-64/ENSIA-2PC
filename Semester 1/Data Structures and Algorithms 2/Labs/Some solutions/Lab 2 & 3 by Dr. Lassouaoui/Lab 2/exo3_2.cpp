#include <iostream>
#include "Implementation aid/List.h"

using namespace std;

int main(){
    List<int> L;
    L.push_back(5);
    L.push_back(6);
    L.push_back(7);

    for(auto e:L)
        cout << e << endl;
    List<int>::iterator itr = L.begin();
    L.swapWithTheNext(itr);
cout << "==========" << endl;
    for(auto e:L)
        cout << e << endl;

    return 0;
}