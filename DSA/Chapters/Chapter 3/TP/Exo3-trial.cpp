#include <iostream>
using namespace std;
// A doubly linked list

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
            tail->previous = head;
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
    copy constructor can be 
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
    void swap_items(Node* first)
    {
        Node* temp = first->nextptr->nextptr;
        first->nextptr->previous = first->previous;
        first->previous = first->next;
        first->nextptr->nextptr = first;
        first->nextptr = temp;
    }
   
   
    private:
        struct Node
        {
            Object data;
            Node* nextptr;
            Node* previous;

            //defining a constructor for the Node struct
            Node(const Object& value = Object(), Node* next = nullptr, Node* prev = nullptr)
            : data{value}, nextptr{next}, previous{prev}
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
Move Constructor (how to call the move constructor singleList is performed through the l1 = std::move(l2))
assignment Copy Constructor (overloading the = operator)=> singleList& operator=(const singleList& rhs)
*/
