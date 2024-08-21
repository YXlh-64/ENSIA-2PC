#include <iostream>
using namespace std;
// A singly linked list

template <typename Object>
class SLL{
    public:
        //the big five
        //1. constructor
        SLL()
        {
            size = 0;
            head = new Node;
            head->nextptr = tail;
            tail = new Node;
        }
        //2. Copy constructor
        SLL(const SLL<Object>& oldList): size{oldList.size}{
            head = new Node;
            tail = new Node;

            //a pointer which moves throughout the list
            Node* hold=head;
            // a pointer which moves throughout the oldList
            Node* curr=oldList.head;

            while(curr != oldList.tail)
            {
                Node* newNode = new Node;
                newNode->data = curr->data;
                newNode->nextptr = hold->nexptr;
                hold->nextptr = newNode;
                hold = hold->nextptr;
                curr = curr->nextptr;
            }
        }
        //3. Move construtctor
        SLL(SLL&& right_hand_side)
        : head{move(right_hand_side.head)}, tail{move(right_hand_side.tail)}, size{right_hand_side.size}
        {

        }
        //4. Copy assignment constructor
        SLL & operator= (const SLL& rhs)
        {
            SLL copy = rhs;
            swap(copy, *this);
            return *this;
        }
        //5. Move assignment constructir
        SLL & operator= (SLL && rhs)
        {
            swap(head, rhs.head);
            swap(tail, rhs.tail);
            return *this;
        }
/*the assignment operator is called when = is 
applied to two objects of the same type
lhs=rhs is intended to copy the state of rhs into lhs. If rhs is an
lvalue, this is done by using the copy assignment operator;
if rhs is an rvalue (i.e., a temporary that is about 
to be destroyed anyway), this is done by using the move assignment
operator.*/
//copy assignment operator is implemented by applying the copy assignment operator to each data member
    /*
    Here is the difference between the copy cosntructor and the asssignment operator:
    SLL NewList = oldLIst; => this can be achieved using copy constructor if oldList is an lvalue, and through move constructor if oldList is an rvalue
    SLL NewList{oldList} => this will use copy constructor if oldList is an lvalue, and move constructor if oldList is an rvalue
    objects called or returned by value (which should be rarely done) use copy constructor
    */
        //2. Destructor
        ~SLL(){
            Node* curr = head;
            while (curr != nullptr)
            {
                Node* hold = curr->nextptr;
                delete curr;
                curr = hold;
            }
        }

    //function to swap two adjacent elements in a linked list
    void swap_items(Node*& first)
    {
        Node* second = first->nextptr;
        Node temp = new Node(first->data, second->nextptr);
        delete first;
        first = second;
        second->nextptr = temp;
    }
    
    private:
        struct Node
        {
            Object data;
            Node* nextptr;

            //defining a constructor for the Node struct
            Node(const Object& value = Object(), Node* next = nullptr)
            : data{value}, nextptr{next}
            {/*empty body*/}
        };
        Node* head;
        Node* tail;
        int size;
        
};

/*Big Five:
Constructor
Destructor
Copy Constructor
Move Constructor
Copy assignment Constructor
*/




//professor's solution
/*
singleList(const singleList& other){

}
bool contains (const Object &x){
    Node<Object>* ptr = head;
    while(ptr != nullptr){
        if(ptr->data == x) return true;
        ptr = ptr->next;
    }s
    return false;
}
//the reasin 
bool add_begin(const Object& x){
    if(contains(x)) return false;
    Node<Object>* ptr = new Node<Object> (x,head);
    head = ptr;
    theSize++;
    return true;
}

bool add_end(const Object& x){
    if(contains(x)) return false;
    if(theSize == 0) head= new Node<Object>(x);
    else if(theSize == 1) head->next = new Node<object>(x);
    else{
        //loop to reach the last element of the linked list and insert the last node
    }

    theSize++;
    return true;
}
//copy assignment constructor

*/