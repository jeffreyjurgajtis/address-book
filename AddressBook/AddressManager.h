//
//  AddressManager.h
//  AddressBook
//
//  Copyright (c) 2014 jeffreyjurgajtis. All rights reserved.
//

#ifndef AddressManager_h
#define AddressManager_h

#include "AddressBook.h"

class AddressManager
{
public:
    AddressManager();    // Class constructor
    
    int GetMenuChoice();
    Date GetCurrentDate();
    void DisplayMainMenu();
    void DelegateMenuChoice(int);
    void AddEntry();
    void RemoveEntry();
    void UpdateEntry();
    void PrintEntries();
    void PrintBirthdayCards();
    void PrintAnniversaryCards();
    
private:
    AddressBook addressBook;
};

#endif
