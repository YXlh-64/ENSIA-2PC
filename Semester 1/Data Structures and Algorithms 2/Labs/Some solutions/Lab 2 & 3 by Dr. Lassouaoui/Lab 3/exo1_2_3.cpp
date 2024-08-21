#include <iostream>
#include "binarySearchTree1.h"

using namespace std;

int main(){

    BST<int> tree;

    // The start of exercise 1
    for(int i=0, c;i<10;i++)
    {
        c=rand()%100;
        cout << c << "  ";
        tree.insert(c);
    }
    
    cout << endl;
    cout << "Number of nodes      = " << tree.numberNodes() << endl;
    cout << "Number of leaves     = " << tree.numberLeaves() << endl;
    cout << "Number of full nodes = " << tree.numberFullNodes() << endl;
    cout << "Depth of the tree    = " << tree.depthTree() << endl;
    cout << "Print the tree       : " << endl;
    
    tree.printTree();
    // The end of exercise 1

    // The start of exercise 2
    tree.removeLeaves();
    cout << "---> After removing Leaves " << endl;
    cout << "Number of nodes      = " << tree.numberNodes() << endl;
    cout << "Number of leaves     = " << tree.numberLeaves() << endl;
    cout << "Depth of the tree    = " << tree.depthTree() << endl;
    tree.printTree();
    cout << endl;
    // The end of exercise 2
    
    // The start of exercise 3
    //tree.changeValue(9); 
    cout << (tree.isBST()?"The tree is BST":"The tree is not BST") << endl;
    // The end of exercise 3
    return 0;
}