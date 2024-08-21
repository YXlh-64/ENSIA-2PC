#include <iostream>
#include "Implementation aid/Vector.h"

using namespace std;

int main()
{
    Vector<int> V;
    V.push_back(1);
	V.push_back(3);
	V.push_back(5);

    Vector<int>::iterator pos = V.begin();

    //Before insert
    cout << "Array before insertion " << endl;
    for (auto e:V)
        cout << e << endl;

    cout << "Give the value to insert :" << endl;
    int value;
    cin >> value;

    cout << "Give the position of the insertion: ";
    int posi;
    cin >> posi;
    V.insert(pos+posi, value);
    
    //After insert
    cout << "Array After insertion " << endl;
    for (auto e:V)
        cout << e << endl;
    
    V.erase(pos+1);
    //After erase
    cout << "Array after erase " << endl;
    for (auto e:V)
        cout << e << endl;

 return 0;
}