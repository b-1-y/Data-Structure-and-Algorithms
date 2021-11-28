#include <iostream>
#include <string>
#include <queue>
using namespace std;

template <typename Type>
class BinaryTreeNode
{
private:
    BinaryTreeNode<Type> *left;
    BinaryTreeNode<Type> *right;
    Type elem;

public:
    BinaryTreeNode();
    BinaryTreeNode(Type elem);
    BinaryTreeNode(BinaryTreeNode<Type> *l, BinaryTreeNode<Type> *right, Type elem);
    ~BinaryTreeNode();
    Type &element() { return elem; };
    bool isleaf() { return !left && !right; };
    void setLeft(BinaryTreeNode<Type> *b) { left = b; };
    void setright(BinaryTreeNode<Type> *b) { right = b; };
    BinaryTreeNode<Type> *Left() const { return left; };
    BinaryTreeNode<Type> *Right() const { return right; };
};

template <class Type>
class BinaryTree
{
    friend class BinaryTreeNode<Type>;

private:
    BinaryTreeNode<Type> *root;

public:
    BinaryTree() { root = NULL; };
    BinaryTree(Type elem);
    BinaryTree(BinaryTree<Type> *l, BinaryTree<Type> *r, Type elem);
    void DeleteTree(BinaryTreeNode<Type> *root);
    ~BinaryTree();
    BinaryTreeNode<Type> *Root() { return root; };
    void LevelOrder(BinaryTreeNode<Type> *root);
};

template<typename Type>
void BinaryTree<Type>::LevelOrder(BinaryTreeNode<Type> *root){
    queue<BinaryTreeNode<Type>*>tQueue;
    BinaryTreeNode<Type> *pointer =root;
    if(pointer) tQueue.push(pointer);
    while(!tQueue.empty()){
        pointer=tQueue.front();
        tQueue.pop();
        cout<<pointer->element()<<" ";
        if(pointer->Left()!=NULL)
            tQueue.push(pointer->Left());
        if(pointer->Right()!=NULL)
            tQueue.push(pointer->Right());
    }
}

template<typename Type>
class BinarySearchTree:public BinaryTree<Type>{
    friend class BinaryTreeNode<Type>;

public:
    BinarySearchTree(){};
    ~BinarySearchTree(){};
    BinaryTreeNode<Type> *Search(BinaryTreeNode<Type> *subroot,const Type& k);
    void Insert(BinaryTreeNode<Type>* &root,const Type& k);
    bool Delete(BinaryTreeNode<Type>* &root,const Type& k);
    void AVLRotate();
};

template<typename Type>
void BinarySearchTree<Type>::Insert(BinaryTreeNode<Type>* &root,const Type& k){
    if(root==NULL){
        root=new BinaryTreeNode<Type>(k);
        return;
    }
    else{
        if(k==root->element()) return;
        else if(k<root->element())
            Insert(root->left,k);
        else Insert(root->right,k);
    }
}

template <typename Type>
void BinarySearchTree<Type>::AVLRotate(){

}

int main(){
    int* a=new int[100];
    int n = 0;
    int tmp = 0;
    string str;
    getline(cin, str);
    for (int i = 0; i < str.size(); i++) {
        a[n]=0;
        if (!(str[i] >='0' && str[i] < 58))
            i++;
        while (str[i] >= '0' && str[i] <= '9') {
            a[n] = 10 * a[n] + str[i] - '0';
            i++;
        }
        n++;
    }
    BinarySearchTree<int> SearchTree;
    BinaryTreeNode<int>* root=SearchTree.Root();
    for (int i=0; i<n; i++){
        SearchTree.Insert(root,a[i]);
    }
    SearchTree.LevelOrder(root);
    return 0;
}