#ifndef EXO7H
#define EXO7H
//Efficiently implement a Stack class using a singly linked list,
//with no header or tail nodes.

//Start by defining a struct node to represent a single item in the stack
template<typename Object>
struct Node
{
    Object data;
    Node* next;
    Node(): next{nullptr}{};
    Node(const Object& data_input, Node* nextptr = nullptr):data{data_input}, next{nextptr}{};
};

template <typename Object>
class Stack{
    public:
    //constructor
    Stack()
    :head{nullptr}{}
    //destructor
    ~Stack(){
        while (head!=nullptr)
        {
            pop()
        }
    }
    void push(const Object& value){ //O(1)
        Node<Object>* newNode = new Node(value, head);
        head = newNode;
    }

    void pop(){ //O(N)
        if(head == nullptr) return;
        Node<Object>* current = head->next;
        delete head;
        head = current;
    }
    Object top(){return head->data;}
    private:
        Node<Object>* head;
};
#endif