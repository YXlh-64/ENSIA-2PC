#include <iostream>
using namespace std;
/*
Exercise 6
An alternative to the deletion strategy is to use lazy deletion. To delete an
element, we merely mark it deleted (using an extra bit field). The number of
deleted and non-deleted elements in the list is kept as part of the data
structure. If there are as many deleted elements as non-deleted elements, we
traverse the entire list, performing the standard deletion algorithm on all
marked nodes.
1. List the advantages and disadvantages of lazy deletion.
2. Write routines to implement the standard linked list operations using lazy
deletion.
*/
template <typename Object>
struct Node{
    Object data;
    Node* next;
    bool to_be_deleted;
};

template <typename Object>
class singlyLinkedList{
    private:
        Node<Object>* head;
        int size;
    public:
        //constructor
        singlyLinkedList():head{nullptr}, size{0}{}
        //destructor

        void deleteNode(const Object)
};

int main(){
    return 0;
}
