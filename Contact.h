#ifndef CONTACT_H_
#define CONTACT_H_

#include "LinkedList.h"

class Contact
{
public:
	string Name;
	LinkedList<string> Phone_Numbers;

public:
	Contact();
	Contact(string name , string phoneN);

	Contact(string name); // Search in the file and find the phone numbers belongs to this Name

	void addPhoneNumber(string number);

	string getName();
	void setName(string);

	bool NumberIsExsit(string number);

	bool operator<(const Contact & c);
	bool operator>(const Contact & c);


	bool operator==(const Contact & c);

	friend ostream& operator<<(ostream& o, Contact c)
	{
	    cout << c.Name << " : ";
	    cout << c.Phone_Numbers << endl;
	    return o;
	}

};

#endif  /* CONTACT_H_ */
