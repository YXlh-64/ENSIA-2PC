#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

template <typename Comparable>
class AvlTree
{
  public:
    AvlTree( ) : root{ nullptr }
    {
	}

    AvlTree( const AvlTree & rhs ) : root{ nullptr }
    {
        root = clone( rhs.root );
    }

    AvlTree( AvlTree && rhs ) : root{ rhs.root }
    {
        rhs.root = nullptr;
    }

    ~AvlTree( )
    {
        makeEmpty( );
    }

    AvlTree & operator=( const AvlTree & rhs )
    {
        AvlTree copy = rhs;
        std::swap( *this, copy );
        return *this;
    }

    AvlTree & operator=( AvlTree && rhs )
    {
        std::swap( root, rhs.root );
        return *this;
    }

    bool isEmpty( ) const
    {
        return root == nullptr;
    }

    /**
     * Print the tree contents in sorted order.
     */
    void printTree( ) const
    {
        if( isEmpty( ) )
            cout << "Empty tree" << endl;
        else
            printTree( root ,0);
    }

    /**
     * Make the tree logically empty.
     */
    void makeEmpty( )
    {
        makeEmpty( root );
    }

    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( const Comparable & x )
    {
        insert( x, root );
    }

    /**
     * Remove x from the tree. Nothing is done if x is not found.
     */
    void remove( const Comparable & x )
    {
        remove( x, root );
    }

    void non_recursive_insert(const Comparable& x){
        if(root == nullptr)
            root = new AvlNode(x, nullptr, nullptr);
        else{
            AvlNode** ptr = &root;
            stack<AvlNode**> s;
            while((*ptr) != nullptr){
                if(x < (*ptr)->element){
                    s.push(ptr);
                    ptr = &((*ptr)->left);
                }
                else if(x > (*ptr)->element){
                    s.push(ptr);
                    ptr = &((*ptr)->right);
                }
                else return;
            }
            (*ptr)= new AvlNode(x, nullptr, nullptr,0);
            while(!s.empty()){
                balance(*(s.top()));
                s.pop();
            }
        }
    }
  private:
    struct AvlNode
    {
        Comparable element;
        AvlNode    *left;
        AvlNode    *right;
        int        height;
        AvlNode(const Comparable& x, AvlNode* lt, AvlNode* rt, int h=0)
        : element{x}, left{lt}, right{rt}, height{h}{}
    };

    AvlNode *root;

    void makeEmpty( AvlNode * & t )
    {
        if( t != nullptr )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = nullptr;
    }

    /**
     * Internal method to print a subtree rooted at t in sorted order.
     */
    void printTree( AvlNode *t, int space ) const
    {
        if(t == nullptr)
            return;
        space+=10;
        printTree(t->right, space);

        cout << endl;
        for(int i= 10; i< space; i++)
            cout << " ";
        cout << t->element << endl;

        printTree(t->left, space);
    }

    /**
     * Internal method to clone subtree.
     */
    AvlNode * clone( AvlNode *t ) const
    {
        if( t == nullptr )
            return nullptr;
        else
            return new AvlNode{ t->element, clone( t->left ), clone( t->right ), t->height };
    }
    AvlNode * findMin( AvlNode *t ) const
    {
        if( t == nullptr )
            return nullptr;

        if( t->left == nullptr )
            return t;

        return findMin( t->left );
    }

    void insert( const Comparable & x, AvlNode * & t )
    {
        if( t == nullptr )
            t = new AvlNode{ x, nullptr, nullptr };

        else if( x < t->element )
            insert( x, t->left );

        else if( t->element < x )
            insert( x, t->right );
        balance(t);
    }

    void remove( const Comparable & x, AvlNode * & t )
    {
        if( t == nullptr )
            return;   // Item not found; do nothing

        if( x < t->element )
            remove( x, t->left );

        else if( t->element < x )
            remove( x, t->right );

        else if( t->left != nullptr && t->right != nullptr ) // Two children
        {
            t->element = findMin( t->right )->element;
            remove( t->element, t->right );
        }
        else
        {
            AvlNode *oldNode = t;
            t = ( t->left != nullptr ) ? t->left : t->right;
            delete oldNode;
        }
        balance(t);
    }
    void balance(AvlNode* &t){
        if(t == nullptr)
            return;
        if(height(t->left) - height(t->right) > 1)
            if(height(t->left->left) > height(t->left->right))
                rotateWithLeftChild(t); // Right rotation
            else 
                doubleWithLeftChild(t);
        else
        if(height(t->right) - height(t->left) > 1)
            if(height(t->right->right) > height(t->right->left))
                rotateWithRightChild(t); // Left Rotation
            else
                doubleWithRightChild(t);
        t->height = max(height(t->left), height(t->right)) + 1;
    }
    int height(AvlNode* t){
        if(t == nullptr) return -1;
        return t->height;
        // return t == nullptr ? -1 : t->height;
    }
    int max(int l, int r){
        return l > r? l: r;
    }

    void rotateWithLeftChild(AvlNode* &k2){
        AvlNode* k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k1->height = max(height(k1->left), k2->height) +1;
        k2 = k1;
    }

    void rotateWithRightChild(AvlNode* &k1){
        AvlNode* k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = max(height(k1->left), height(k1->right)) + 1;
        k2->height = max(height(k2->right), k1->height) +1;
        k1 = k2;
    }

    void doubleWithLeftChild(AvlNode* &k3){
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    } 

    void doubleWithRightChild(AvlNode* &k1){
        rotateWithLeftChild(k1->right);
        rotateWithRightChild(k1);
    }
};

#endif