#ifndef EXO8H
#define EXO8h

/*Efficiently implement a Queue class using a singly linked list, with no header or tail nodes.*/

// Start by defining a struct node to represent a single item in the queue
template <typename Object>
struct Node
{
    Object data;
    Node *next;
    Node() : next{nullptr} {};
    Node(const Object &data_input, Node *nextptr = nullptr) : data{data_input}, next{nextptr} {};
};

template <typename Object>
class Queue
{
public:
    // constructor
    Queue()
        : head{h}, tail{t} {}
    ~Queue()
    {
        while (head)
            dequeue();
    }

    // enqueue function implementation
    void enqueue(const Object &x)
    {
        Node<Object> *newNode = new Node<Object>(x);
        if (tail != nullptr)
            tail = tail->next = newNode;
        else
            head = tail = newNode;
    }

    // dequeue function implementation
    Object &dequeue()
    {
        if (head == nullptr)
            throw out_of_range("Queue is empty!");

        Node<Object> *ptr = head;
        Object d = front->data;
        if (head->next == nullptr)
            head = tail = nullptr else head = head->next;
        delete ptr;
        return d;
    }
    Object peak_front() { return head->data; }
    Object peak_rear() { return tail->data; }

private:
    Node<Object> *head;
    Node<Object> *tail;
};
#endif