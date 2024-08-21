#include <iostream>
#include "AvlTreeExercise7_2.h"

using namespace std;

int main()
{
    AvlTree<int> tree;/*

    for(int i=0, c;i<10;i++)
    {
        c=rand()%100;
        cout << c << "  ";
        tree.insert(c); 
    }
    //cout << endl;*/
    tree.insert(5);
    tree.insert(2);
    tree.insert(8);
    tree.insert(1);
    tree.insert(7);
    tree.insert(4);
    tree.insert(3);
    tree.non_recursive_insert(6);

    //tree.insert(6);
    tree.printTree();


    return 0;
}
