#include <iostream>
#include "OrderedCollection.h"
using std::cin;
using std::cout;
using std::endl;
int main(){
    orderedCollection<int> obj(10);

    cout << obj.isEmpty() << endl;
    obj.insert(12);
    obj.insert(15);
    obj.insert(80);
    obj.insert(560);

    // check if the object is empty
    cout << obj.isEmpty() << endl;

    // delete some elements in the collection obj
    obj.remove(12);
    obj.remove(15);

    obj.MakeEmpty();
    cout << obj.isEmpty() << endl;

    return 0;
}