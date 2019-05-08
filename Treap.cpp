#include "Treap.h"


template<class T, class V>
int Treap<T,V>::height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->Height;
}

//-----------------------------------------
template<class T, class V>
int Treap<T,V>::balanceFactor(Node* n1 )
{
    if(n1==NULL)
        return 0;
    return height(n1->left) - height(n1->right);
}

//-----------------------------------------
template<class T, class V>
void Treap<T,V>::inOrderTraverse(Node* root){ //prints the data in a sorted manner
    if(root == NULL){
        return;
    }
    inOrderTraverse(root->left);
    cout << root ;
    inOrderTraverse(root->right);

}

//-----------------------------------------
template<class T, class V>
Treap<T,V>::Node::Node(T k, V v)
{
    left = NULL;
    right = NULL;
    priority = rand() % 100;
    Height = 0;
    key = k;
    value = v;
}

//-----------------------------------------
template<class T, class V>
class Treap<T,V>::Node* Treap<T,V>::rotateRight(Node* root)
{

	Node* leftChild = root->left;
	Node* rightGrandChild = root->left->right;

	// rotate
	leftChild->right = root;
	root->left = rightGrandChild;

	// set new root
	root = leftChild;

    root->Height = max(height(root->left) ,height( root->right))+ 1;
    leftChild->Height = max(height(leftChild->left),height(leftChild->right)) + 1;

    return leftChild;
}

//-----------------------------------------
template<class T, class V>
class Treap<T,V>::Node* Treap<T,V>::rotateLeft(Node* root)
{
 Node* rightchild = root->right;
    Node* leftgrandchild = root->right->left;

    rightchild->left = root;
    root->right = leftgrandchild;

    root = rightchild ;

    root->Height = max(height(root->left),height( root->right)) + 1;
    rightchild->Height = max(height(rightchild->left) ,height( rightchild->right)) + 1;
    return rightchild;

}

//-----------------------------------------
template<class T, class V>
class Treap<T,V>::Node* Treap<T,V>::Balance(Node* root , T val)
{
    int balance = balanceFactor(root);
    //left left case
    if(balance > 1 && val < root->left->key )
        return rotateRight(root);

    //right right case
    else if(balance < -1 && val > root->right->key)
        return rotateLeft(root);

    // left right case
    else if(balance > 1 && val > root->left->key){
        root->left= rotateLeft(root->left);
        return rotateRight(root);
    }

    else if(balance < -1 && val < root->right->key ){
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

//-----------------------------------------
template<class T, class V>
class Treap<T,V>::Node* Treap<T,V>:: insert(Node* root, T k, V v)
{
   if(root == NULL){
        Node* n = new Node(k , v);
        return n;
    }

    if(k == root->key)
        return root;

    else if (k < root->key){
        root->left = insert(root->left, k , v);
        if (root->left != nullptr&&root->left->priority > root->priority)
             root = rotateRight(root);

    }
    else{
        root->right = insert(root->right , k ,v);

        if (root->right != nullptr && root->right->priority > root->priority)
             root = rotateLeft(root);
        }

     root->Height = max(height(root->left) ,height( root->right)) + 1;
     //Balance(root , k);
     return root;

}

//-----------------------------------------
template<class T, class V>
V Treap<T,V>::find(Node* root, T k)
{
    if(root == NULL)
        return NULL;
    else{
        if(root ->key == k){
            return root->value;
        }
        else if(root ->key < k)
             return find(root->right ,k);
        else
             return find(root->left ,k);
    }
}

//-----------------------------------------
template<class T, class V>
Treap<T,V>::Treap(){
        root = NULL;
}

//-----------------------------------------
template<class T, class V>
void Treap<T,V>::insert(T k, V v)
{
    root = insert(root ,k , v);
}

//-----------------------------------------
template<class T, class V>
V Treap<T,V>::find(T k)
{
    return find(root ,k);
}

//-----------------------------------------
//template class Treap<int , int>;
template class Treap<string , Contact*>;
//template class Treap<string , string>;
