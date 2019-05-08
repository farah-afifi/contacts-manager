#include <iostream>

#include "ContactManager.h"
using namespace std;

int main()
{

    ContactManager Cs;
    Cs.loadFromFile("ContactsFile.txt");

    cout << "Write new Name and phone number : \n";
    string name , number;
    cin >> name >> number;

    Cs.add(name, number);

    Cs.displayNumber(number);

    //cout << Cs;

    return 0;
}
