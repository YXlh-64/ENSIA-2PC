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
class stack{
    public:
        stack():head{nullptr}{}
        ~stack(){
            while(head!=nullptr)
                pop();
        }
        void pop(){
            node<Object>*ptr = head;
            head=head->next;
            delete ptr;
        }
        void push(const Object& x){
            node<Object>* ptr = new node<Object>(x,head);
            head = ptr;
        }
        Object top(){
            return head->data;
        }
    private:
        node<Object>* head;
};

int main(){
    stack<int> s;
    s.push(5);
    s.push(4);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    return 0;
}