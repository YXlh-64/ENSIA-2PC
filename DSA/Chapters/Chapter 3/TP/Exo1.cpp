#include <iostream>
#include <list>

using namespace std;

template <typename T>
// a list in the STL is a doubly linked list with sentinal pointers (head, tail)
// the list class has two subclasses iterator, const_iterator
// *pIter means the data of pIter
//P.end() -> tail
//P.begin() -> head.next
void printLots(list<T> L, list<int> P){ // O(*P.end())
    typename list<int>::const_iterator pIter;
    typename list<T>::const_iterator lIter;
    int pos = 1;
    pIter = P.begin();
    lIter = L.begin();
    while(lIter =! L.end() && pIter != P.end()){
        if(pos == *pIter)
            {
                cout << * pIter << endl;
                pIter++;
            }
        pos++;
        lIter++;
    }

}
int main(){
    list<int> P{1,3,4, 6};
    list <
    return 0;
}