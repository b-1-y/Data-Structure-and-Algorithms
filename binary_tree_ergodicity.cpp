#include <iostream>
using namespace std;

template <typename Type>
class BinaryTreeNode
{
    friend class BinaryTree<Type>;
    friend class BinarySearchTree<Type>;

private:
    Type data;
    BinaryTreeNode<Type> *left;
    BinaryTreeNode<Type> *right;

public:
    BinaryTreeNode();
    ~BinaryTreeNode(){};
    BinaryTreeNode(const Type& elem);
    BinaryTreeNode(const Type& elem,BinaryTreeNode<Type> *l,BinaryTreeNode<Type>*r);
};

template<typename Type>
class BinaryTree{
    protected:
    BinaryTreeNode<Type> *root;
    public:
    BinaryTree(){root=NULL;}
    BinaryTree(BinaryTreeNode<Type>*r){root=r;}
    ~BinaryTree(){delete BinaryTree(root);};
    bool IsEmpty()const;
    void visit(Type data){cout<<data;};
    BinaryTreeNode<Type>* getroot(){return root;};
    void PreOrder(BinaryTreeNode<Type>*root);
    void InOrder(BinaryTreeNode<Type>* root);
    void PostOrder(BinaryTreeNode<Type>* root);
    void CreateTree(int k,string str);
};

template<typename Type>
void BinaryTree<Type>::PreOrder(BinaryTreeNode<Type>* root){
    if(root==NULL)return;
    visit(root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

template<typename Type>
void BinaryTree<Type>::InOrder(BinaryTreeNode<Type> *root){
    if(root==NULL) return;
    InOrder(root->left);
    visit(root->data);
    InOrder(root->right);
}

template<typename Type>
void BinaryTree<Type>::PostOrder(BinaryTreeNode<Type> *root){
    if(root==NULL) return;
    PostOrder(root->left);
    PostOrder(root->right);
    visit(root->data);
}

template<typename Type>
void BinaryTree<Type>::CreateTree(int k,string str){
    if (k>str.size()) return;
    else{
        BinaryTreeNode<Type>* newnode = 
    }
}


int main(){
    string str;
    cin >> str;
    BinaryTree<char> binarytree;
    binarytree.CreateTree(1,str)
    return 0;
}