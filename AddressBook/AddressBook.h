//
//  AddressBook.h
//  AddressBook
//
//  Copyright (c) 2014 jeffreyjurgajtis. All rights reserved.
//

#ifndef AddressBook_h
#define AddressBook_h

#include "AddressEntry.h"

struct NodeType;

class AddressBook
{
public:
    AddressBook();     // Class constructor
    ~AddressBook();    // Class destructor
    
    bool IsFull() const;
    int  GetLength() const;
    void MakeEmpty();
    AddressEntry GetEntry(AddressEntry& entry, bool& found);
    void PutEntry(AddressEntry item);
    void DeleteEntry(AddressEntry item);
    void ResetList();
    AddressEntry GetNextEntry();
    
private:
    NodeType* listData;
    int length;
    NodeType* currentPos;
};

#endif
