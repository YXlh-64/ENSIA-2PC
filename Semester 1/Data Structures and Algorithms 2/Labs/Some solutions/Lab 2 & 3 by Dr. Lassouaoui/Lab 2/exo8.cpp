#include <iostream>
using namespace std;

template<typename Object>
struct node{
    node():next{nullptr}{}
    node(const Object& d, node* ptr = nullptr):data{d}, next{ptr}{}
    Object data;
    node* next;
};

template<typename Object>
class queue{
    public:
        queue():front{nullptr}, rear{nullptr}{}
        ~queue(){
            while(front != nullptr)
                dequeue();
        }
        void dequeue(){
            node<Object>* ptr = front;
            if(front->next == nullptr)
                front = rear = nullptr;
            else
                front = front->next;
            delete ptr;
        }
        void enqueue(const Object& x){
            node<Object>* ptr = new node<Object>(x,nullptr);
            if(front == nullptr)
                front = rear = ptr;
            else
            {
                rear->next = ptr;
                rear = ptr;
                }
        }
        Object peak_front(){return front->data;}
        Object peak_rear(){return rear->data;}
    private:
        node<Object>* front;
        node<Object>* rear;
};

int main(){
    queue<int> q;
    q.enqueue(1);
    q.enqueue(3);
    q.enqueue(5);
    cout << q.peak_front() << endl;
    cout << q.peak_rear() << endl;
    return 0;
}