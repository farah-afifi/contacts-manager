#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <iostream>
using namespace std;


template<class T>
class LinkedList
{
public:
	struct Node
	{
		T value;
		Node* Next;
		Node();
		Node(T v);
		Node(T v , Node* next);

    };
	struct iter
    {
        Node* currNode;
        iter(Node* node);
        void operator=(const iter &rhs);
        void operator++();
        T operator*();
        bool operator == (const iter rhs);
        bool operator != (const iter rhs);
    };

	LinkedList();
	~LinkedList();

	Node* addSorted(T v);
	Node* get(T v);
	iter begin();
	iter end();
	bool IsEmpty();

    // operator overloading for printing
	friend ostream& operator<<(ostream& o, LinkedList<T> & c)
	{
	    Node* current = c.head;
	    if(c.head == NULL){
            cout << "Empty List";
            return o;
	    }

	    cout <<" " <<current->value;///CHANGE+++++++++++++++++++++
        current = current->Next;

        while(current != NULL){
            cout << " - " << current->value;///CHANGE+++++++++++++++++++++
            current = current->Next;

        }
        return o;
	}

private:
	Node* head;
};

#endif  /* LINKED_LIST_H_ */
