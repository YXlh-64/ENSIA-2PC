#include <iostream>
using namespace std;

//function that takes a pointer to the root of a binary tree T
//and compute the number of nodes in T

template <typename Object>
struct Node{
    Object data;
    Node* firstChild;
    Node* secondChild;
};

template <typename Object>
int calculateNodes(Node<Object>* root){ //O(N)
    //base case
/*     
            optimized code
        if(root->firstChild == nullptr || root->secondChild == nullptr)
        return 1 + ((root->firstChild == nullptr)?calculateNodes(root->secondChild) : 0) +
        ((root->secondChild == nullptr)?calculateNodes(root->firstChild) : 0); */
    if(root->firstChild == nullptr)
        return 1 + calculateNodes(root->secondChild);
    if(root->secondChild == nullptr)
        return 1 + calculateNodes(root->secondChild);
    if(root->firstChild == nullptr && root->secondChild == nullptr)
        return 1;
    
    return 1 + calculateNodes(root->firstChild) + calculateNodes(root->secondChild);
}

//an algorithm that computes the number of leaves in T
template <typename Object>
int calculateLeaves(Node<Object>* root){ //O(N)
    //base case
    if(root->firstChild == nullptr && root->secondChild==nullptr)
        return 1;
    return calculateLeaves(root->firstChild) + calculateLeaves(root->secondChild);
}
// a function to calculate the number of full nodes in T (nodes with left and right child nodes)
template <typename Object>
int calculateFullNodes(Node<Object>* root){
    if(root == nullptr)
        return 0;
    return (root->firstChild && root->secondChild) ? 1 : 0 + calculateFullNodes(root->firstChild) + calculateFullNodes(root->secondChild);
}
//function that calculates the depth of The tree T
template <typename Object>
int calculateDepth(Node<Object>* root){
    //base case
    if(root == nullptr)
        return -1;
    return max(calculateDepth(root->firstChild), calculateDepth(root->secondChild))+1;
}
int main(){
    return 0;
}