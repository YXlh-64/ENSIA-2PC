#include <iostream>
#include "Collection.h"
using namespace std;
int main()
{
    collection<int> obj(10);
    cout << obj.isEmpty() << endl;
    obj.insert(12);
    obj.insert(15);
    obj.insert(80);
    obj.insert(560);

    // check if the object contains the elements listed above
    cout << obj.isEmpty() << endl;
    cout << obj.contains(12) << endl;
    cout << obj.contains(15) << endl;
    cout << obj.contains(80) << endl;
    cout << obj.contains(560) << endl;

    // delete some elements in the collection obj
    obj.remove(12);
    obj.remove(15);

    // check if the object contains the elements after the modification
    cout << obj.contains(12) << endl;
    cout << obj.contains(15) << endl;
    cout << obj.contains(80) << endl;
    cout << obj.contains(560) << endl;
    obj.MakeEmpty();
    cout << obj.isEmpty() << endl;

    return 0;
}