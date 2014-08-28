//
//  AddressEntry.cpp
//  AddressBook
//
//  Copyright (c) 2014 jeffreyjurgajtis. All rights reserved.
//

#include "AddressEntry.h"

#include <iostream>

using namespace std;

AddressEntry::AddressEntry(string _lastName)
{
    lastName = _lastName;
}

AddressEntry::AddressEntry(){};
AddressEntry::~AddressEntry(){};

void AddressEntry::Initialize(string _firstName, string _lastName, string _address, Date _birthday, Date _anniversary)
{
    firstName = _firstName;
    lastName = _lastName;
    address = _address;
    birthday = _birthday;
    anniversary = _anniversary;
}

RelationType AddressEntry::ComparedTo(AddressEntry otherEntry) const
{
    if (lastName < otherEntry.lastName)
        return LESS;
    else if (lastName > otherEntry.lastName)
        return GREATER;
    else return EQUAL;
}

void AddressEntry::Print()
{
    cout << "Address Entry: " << endl;
    cout << " Name: " << lastName << ", " << firstName << endl;
    cout << " Address: " << address << endl;
    cout << " Birthday: " << birthday.Format() << endl;
    cout << " Anniversary: " << anniversary.Format() << endl;
}

string AddressEntry::GetFirstName()
{
    return firstName;
}

string AddressEntry::GetLastName()
{
    return lastName;
}

string AddressEntry::GetAddress()
{
    return address;
}

Date AddressEntry::GetBirthday()
{
    return birthday;
}

Date AddressEntry::GetAnniversary()
{
    return anniversary;
}
