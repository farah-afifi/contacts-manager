#include "LinkedList.h"
#include "Contact.h"

//-----------------------------------------
template<class T>
LinkedList<T>::Node::Node(T v)
{
    Next = NULL;
    value = v;

}

//-----------------------------------------
template<class T>
LinkedList<T>::Node::Node(T v , Node* next)
{
    Next = next;
    value = v;
}


//-----------------------------------------
template<class T>
LinkedList<T>::iter::iter(Node* node)
{
    currNode = node;
}

//-----------------------------------------
template<class T>
void LinkedList<T>::iter::operator=(const iter &rhs)
{
    currNode = rhs.currNode;
}

//-----------------------------------------
template<class T>
void LinkedList<T>::iter::operator++()
{
    currNode = currNode->Next;
}

//-----------------------------------------
template<class T>
T LinkedList<T>::iter::operator*()
{
    return currNode->value;
}

//-----------------------------------------
template<class T>
bool LinkedList<T>::iter::operator == (const iter rhs)
{
    return (currNode == rhs.currNode);
}

//-----------------------------------------
template<class T>
bool LinkedList<T>::iter::operator != (const iter rhs)
{
    return (currNode != rhs.currNode);
}


//-----------------------------------------
template<class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
}

//-----------------------------------------
template<class T>
LinkedList<T>::~LinkedList()
{
    /*
    Node* current = head;

    while(!IsEmpty())
    {
        current = head->Next;
        delete head;
        head = current;
    }

    delete current;
    */

}
//------------------------------------------
template<class T>
bool LinkedList<T>::IsEmpty()
{
    return (head == NULL);
}

//-----------------------------------------
template<class T>
class LinkedList<T>::Node* LinkedList<T>::addSorted(T v)
{
    if(head == NULL) // Empty List
        head = new Node(v);
    else
    {
        Node* current = head;
        // Add First
        if(head->value > v)
        {
            Node* temp = new Node(v , head);
            head = temp;
            return head;
        }
        // Add at middle or last
        while( current != NULL && current->Next != NULL && current->value < v)
        {
            if(current->Next->value > v)
                break;

            current = current->Next;
        }

        current->Next = new Node(v , current->Next);
    }

    return head;
}

//-----------------------------------------
template<class T>
class LinkedList<T>::Node* LinkedList<T>::get(T v)
{
    Node* current = head;

    while(current != NULL){
        if(current->value == v){
            return current;
        }
        current = current->Next;
    }

    return NULL;

}

template<class T>
class LinkedList<T>::iter LinkedList<T>::begin()
{
    iter at(head);
    return at;
};

template<class T>
class LinkedList<T>::iter LinkedList<T>::end()
{
    Node* current = head;
    while(current->Next != NULL)
    {
        current = current->Next;
    }

    iter at(current);

    return at;
};


//-----------------------------------------
template class LinkedList<string>;
template class LinkedList<int>;
template class LinkedList<Contact>;




