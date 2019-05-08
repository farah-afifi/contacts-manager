#ifndef TREAP_H_
#define TREAP_H_
#include "Contact.h"

#include <iostream>
using namespace std;

template<class T, class V>
class Treap {
public:
	class Node {
	public:
		Node *left, *right;
		T key;
		V value;
		int Height;
		int priority;

		Node(T k, V v);
		friend ostream& operator<<(ostream &o, Treap<T, V>::Node* root){
           o <<root->key<<" Belongs to : "<< *(root->value) <<endl;

            return o;
		}

	};
    int height(Node *N);
    int balanceFactor(Node* n1 );
    void inOrderTraverse(Node* root);

private:
	Node* root;

	Node* rotateRight(Node* root);
	Node* rotateLeft(Node* root);
	Node* Balance(Node* root , T k);
	Node* insert(Node* root, T k, V v);
	V find(Node* root, T k);

public:
	Treap();
	void insert(T k, V v);
	V find(T k);
	friend ostream& operator<<(ostream &o, Treap<T, V> tree)
	{
        tree.inOrderTraverse(tree.root);
        return o;
	}
};

#endif /* TREAP_H_ */
