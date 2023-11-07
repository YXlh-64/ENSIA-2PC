#include <iostream>

using namespace std;

template <typename Object>
struct Node{
    Object data;
    Node *next;
    Node(const Object &d=Object(), Node *n=nullptr):data{d},next{n}{}
};

template <typename Object>
class singleList{
    private:
        Node<Object> *head;
        int theSize;
    public:
        singleList():head{nullptr}, theSize{0}{} 
        ~singleList(){
            eraseList(head);
        }
        singleList(const singleList &other):head{nullptr}, theSize{0}{ // copy constructor singleList<object> l1(l2);
            Node<Object>* ptr = other.head;
            while(ptr!=nullptr){
                add_end(ptr->data);
                ptr= ptr->next;
            }
        }
        singleList& operator=(const singleList &rhs){ // copy assignment constructor
            if(this!=&rhs)
            {
                singleList<Object> copy=rhs;
                swap(copy, *this);
            }
            return *this;
        }
        
        singleList(singleList &&other):head{other.head},theSize{other.theSize}{ // move constructor
            other.head = nullptr;
            other.theSize = 0;
        }
        bool contains(const Object &x){
            Node<Object>*ptr =head;
            while(ptr != nullptr){
                if(ptr->data == x) return true;
                ptr = ptr->next;
            }
            return false;
        }

        bool add_begin(const Object &x){
            if(contains(x)) return false;
            Node<Object>* ptr = new Node<Object>(x, head);
            head = ptr;
            theSize++;
            return true;
        }

        bool add_end(const Object &x){
            if(contains(x)) return false;
            if(theSize == 0) head = new Node<Object>(x);
            else if(theSize == 1) head->next = new Node<Object>(x);
                else{
                    Node<Object>* ptr = head ->next;
                    while(ptr->next !=nullptr)
                        ptr = ptr->next;
                    ptr->next= new Node<Object>(x);
                }
            theSize++;
            return true;
        }
        void eraseList(Node<Object>*h){
            Node<Object>* ptr = h, *nextPtr;
            if(h == head)
                head = nullptr;
            else{
                Node<Object>* beforeH = head;
                while(beforeH -> next != h)
                    beforeH = beforeH->next;
                beforeH ->next = nullptr;
            }
            while(ptr != nullptr){
                nextPtr = ptr->next;
                delete ptr;
                ptr = nextPtr;
                theSize--;
            }
        }
        void printList(){
            Node<Object> *ptr=head;
            while(ptr!= nullptr){
                cout << ptr->data << "  " ;
                ptr=ptr->next;
            }
            cout << endl;
        }
        
        Node<Object>* begin(){
            return head;
        }
        
        void swapWithTheNext(Node<Object>*beforep){
            Node<Object> *p, *afterp;
            p = beforep->next;
            afterp= p->next;
            p->next = afterp ->next;
            afterp ->next = p;
            beforep->next = afterp;
        }
};