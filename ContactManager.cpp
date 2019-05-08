#include "ContactManager.h"
#include <fstream>

ContactManager::ContactManager()
{

}


bool ContactManager::loadFromFile(string fileName)
{
    ifstream ContactsFile(fileName);//the file that is contain all contacts

    string tempName , tempPhNumber;

    while(ContactsFile >> tempPhNumber)//Read the phone number using (Space) as a delimiter
    {
        getline(ContactsFile , tempName);
        tempName.erase(0 , 1);// delete space (The file contain tab(2 spaces) between the phone number and the contact Name)

        Contact c(tempName); // create a obj. contact that hold all his/her phone numbers..
        LinkedList<Contact>::Node* found = contacts.get(c);//Searching for the contact in the contacts linkedList

        if(found == NULL)// if its a new contact :-
            contacts.addSorted(c);// add it to the LinkedList

        found = contacts.get(c);
        tree.insert(tempPhNumber, &(found->value)); // add it to the Treap

    }

    return true;
}

// add the contact in to both linkedList and Treap
void ContactManager::add(string name, string phone_number)
{
    ///Task 1:
    //add to the linked list :
    Contact c(name , phone_number); // Create a contact has only one phone number
    contacts.addSorted(c);// add it to the LinkedList


    ///-------------------------------------------

    ///Task 2:
    //add to the Treap :

    LinkedList<Contact>::Node* found = contacts.get(c);//Searching for the contact in the contacts linkedList
    tree.insert(phone_number ,&(found->value));// add it to the Treap

}

// print only one Contact info. that has this phone number
void ContactManager::displayNumber(string phone_number)
{
    /// Task 1 :
    // Using linked list :
//    LinkedList<Contact>::iter it = contacts.begin();
//
//    for(it ; it != NULL ; ++it) //Loop over the contacts linkedList
//    {
//        Contact tempC = *it;
//        if(tempC.NumberIsExsit(phone_number)) // if the contact has the phone number print it and end the loop
//        {
//            cout << tempC;
//            return;
//        }
//    }// No contact has this phone number
//    cout << "There is no contact has this phone number" << endl;

    ///---------------------------------------------
    ///Task 2 :-
    // Using Treap :
        if(tree.find(phone_number)==0)
            cout << "There is no contact has this phone number" << endl;
        else
            cout<< *(tree.find(phone_number));
}

