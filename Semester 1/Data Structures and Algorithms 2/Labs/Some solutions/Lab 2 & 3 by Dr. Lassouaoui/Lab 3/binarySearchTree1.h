#ifndef BST1_H
#define BST1_H

#include <iostream>
#include <algorithm>
using namespace std;

template <typename Comparable>
class BST{
    public:
        BST():root{nullptr}{}
        ~BST(){
            makeEmpty(root);
        }
        bool isEmpty(){return root == nullptr;}
        void insert(const Comparable& x){
            insert(x, root);
        }
        void remove(){
        }
        void makeEmpty(){
            makeEmpty(root);
        }
        void printTree(){
            if(isEmpty())
                cout << "The tree is empty!";
            else printTree(root);
        }
        int numberNodes(){
            return numberNodes(root);
        }
        int numberLeaves(){
            return numberLeaves(root);
        }
        int numberFullNodes(){
            return numberFullNodes(root);
        }
        int depthTree(){ 
            return depthTree(root);
        } 

        void removeLeaves(){
            root = removeLeaves(root);
        }

        bool isBST(){
            BinaryNode* prevL=nullptr, *prevR = nullptr;
            return isBST(root, prevL, prevR);
        }
        void changeValue(Comparable x){
            root->right->left->element = x;
        }
    private:
        struct BinaryNode{
            Comparable element;
            BinaryNode* left;
            BinaryNode* right;
            BinaryNode(const Comparable &d, BinaryNode *lt, BinaryNode *rt)
                :element{d},left{lt}, right{rt}{}
        };
        BinaryNode* root;

        void insert(const Comparable& x, BinaryNode* &t){
            if(t==nullptr)
                t= new BinaryNode(x,nullptr, nullptr);
            else if(x < t->element)
                    insert(x, t->left);
                else if(x > t->element)
                    insert(x, t->right);
        }

        BinaryNode* findMin(const BinaryNode*&t){
            if(t==nullptr) return nullptr;
            else if(t->left == nullptr) return t;
            else return findMin(t->left);
        }
        void remove(const Comparable& x,BinaryNode* &t){
            if(t==nullptr)return;
            else if(x < t->element)
                remove(x, t->left);
                else if(x > t->element)
                        remove(x, t->right);
                    else if(t->left != nullptr && t->right!=nullptr){
                        t->element= findMin(t->right)->element;
                        remove(t->element, t->right);
                    }
                    else{
                        BinaryNode* oldNode = t;
                        t = (t->left!=nullptr)?t->left: t->right;
                        delete oldNode;
                    }
        }

        void makeEmpty(BinaryNode* &t){
            if(t!=nullptr){
                makeEmpty(t->left);
                makeEmpty(t->right);
                delete t;
            }
            t=nullptr;
        }
        void printTree(BinaryNode* &t) const{
            if(t != nullptr){
                printTree(t->left);
                cout << t->element << "  ";
                printTree(t->right);
            }
        }
        int numberNodes(BinaryNode* &t){
            if(t==nullptr)
                return 0;
            else return 1 + numberNodes(t->left) + numberNodes(t->right);
        }

        int numberLeaves(BinaryNode* &t){
            if(t==nullptr) return 0;
            else if(t->left == nullptr && t->right== nullptr)
                return 1;
                else 
                    return numberLeaves(t->left) + numberLeaves(t->right);
        }
        int numberFullNodes(BinaryNode* &t){
            if(t==nullptr) return 0;
            else if(t->left != nullptr && t->right != nullptr)
                return 1 + numberFullNodes(t->left) + numberFullNodes(t->right);
                else return numberFullNodes(t->left) + numberFullNodes(t->right);
        }

        int depthTree(BinaryNode* &t){
            if(t== nullptr)
                return -1;
            else{
                int depthLeft = depthTree(t->left);
                int depthRight = depthTree(t->right);
                return max(depthLeft, depthRight) +1;
            }
        }

        BinaryNode* removeLeaves(BinaryNode* t){
            if(t==nullptr)
                return nullptr;
            else if(t->left == nullptr && t->right == nullptr){
                delete t;
                t = nullptr;
                return t;
            }
            else {
                t->left = removeLeaves(t->left);
                t->right = removeLeaves(t->right);
                return t;
            }
        }
        bool isBST(BinaryNode* &t,BinaryNode* &prevLeft, BinaryNode* &prevRight)
        {
            if(t==nullptr) 
                return true;
            
            if(prevLeft !=nullptr && t->element <= prevLeft->element) return false;
            if(prevRight != nullptr && t->element >= prevRight->element) return false;

            return isBST(t->left,prevLeft,t) && isBST(t->right,t,prevRight);
        }
        
};
#endif
