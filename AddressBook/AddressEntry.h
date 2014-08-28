//
//  AddressEntry.h
//  AddressBook
//
//  Copyright (c) 2014 jeffreyjurgajtis. All rights reserved.
//

#ifndef AddressEntry_h
#define AddressEntry_h

#include "Date.h"
#include <fstream>
#include <string>

using namespace std;

enum RelationType  {LESS, GREATER, EQUAL};
const int MAX_ITEMS = 25;

class AddressEntry
{
public:
    AddressEntry(string);
    AddressEntry();         // Class constructor
    ~AddressEntry();        // Class deconstructor
    
    void Print();
    RelationType ComparedTo(AddressEntry) const;
    void Initialize(string, string, string, Date, Date);
    
    string GetFirstName();  // Getters
    string GetLastName();
    string GetAddress();
    Date GetBirthday();
    Date GetAnniversary();

private:
    string firstName;
    string lastName;
    string address;
    Date birthday;
    Date anniversary;
};

#endif
