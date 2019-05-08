#include "Contact.h"
#include <string>
#include <fstream>

Contact::Contact()
{

}

//-----------------------------------------

Contact::Contact(string name , string phoneN)
{
    Name = name;
    Phone_Numbers.addSorted(phoneN);
}

//-----------------------------------------
Contact::Contact(string name)
{
    Name = name;

    ifstream ContactsFile;
    ContactsFile.open("ContactsFile.txt");
    string tempNumber , tempName;

    ContactsFile.seekg(0);

    while(ContactsFile >> tempNumber)
    {
        getline(ContactsFile , tempName);
        tempName.erase(0 , 1);

        if(tempName.compare(name) == 0)
            Phone_Numbers.addSorted(tempNumber);
    }
}

//-----------------------------------------
void Contact::addPhoneNumber(string number)
{
    Phone_Numbers.addSorted(number);
}

//-----------------------------------------
string Contact::getName()
{
    return Name;
}
//-----------------------------------------
void Contact::setName(string name)
{
    Name = name;
}

//----------------------------------------
bool Contact::NumberIsExsit(string number)
{
    LinkedList<string>::Node* found = Phone_Numbers.get(number);

    if(found == NULL)
        return false;
    else
        return true;
}

//-----------------------------------------
bool Contact::operator<(const Contact & c)
{
    return Name < c.Name;
    //return (Name.compare(c.Name) < 0);
}

bool Contact::operator>(const Contact & c)
{
    return Name > c.Name;
    //return (Name.compare(c.Name) > 0);
}

//-----------------------------------------
bool Contact::operator==(const Contact & c)
{
    return Name == c.Name;
//    return (Name.compare(c.Name) == 0);
}
