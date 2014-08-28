//
//  AddressManager.cpp
//  AddressBook
//
//  Copyright (c) 2014 jeffreyjurgajtis. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <string>
#include "AddressManager.h"
#include "AddressBook.h"
#include "AddressEntry.h"
#include "Date.h"

AddressManager::AddressManager()
{
    AddressBook _addressBook;
    addressBook = _addressBook;
}

int AddressManager::GetMenuChoice()
{
    int choice;
    cin >> choice;
    return choice;
}

Date AddressManager::GetCurrentDate()
{
    Date today;
    int year, month, day;
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    
    year  = (now->tm_year + 1900);
    month = (now->tm_mon + 1);
    day   = now->tm_mday;
    
    today.Initialize(year, month, day);
    
    return today;
}

void AddressManager::DisplayMainMenu()
{
    cout << "-------Main Menu-------\n";
    cout << "Please make your selection\n";
    cout << "1 - Add address entry\n";
    cout << "2 - Remove address entry\n";
    cout << "3 - Update address entry\n";
    cout << "4 - Generate birthday cards\n";
    cout << "5 - Generate anniversary cards\n";
    cout << "6 - Print address book\n";
    cout << "7 - Quit\n";
    cout << "Selection: ";
}

void AddressManager::DelegateMenuChoice(int menuChoice)
{
    cout << endl;
    
    switch(menuChoice) {
        case 1:
            AddEntry();
            break;
        case 2:
            RemoveEntry();
            break;
        case 3:
            UpdateEntry();
            break;
        case 4:
            PrintBirthdayCards();
            break;
        case 5:
            PrintAnniversaryCards();
            break;
        case 6:
            PrintEntries();
            break;
        case 7:
            cout << "Goodbye!" << endl;
            break;
        default:
            break;
    }
}

void AddressManager::AddEntry()
{
    AddressEntry addressEntry;
    string firstName, lastName, address;
    int aYear, aMonth, aDay, bYear, bMonth, bDay;
    Date birthday, anniversary;
    
    cout << "Adding new entry to address book\n";
    cout << "First Name: ";
    cin >> firstName;
    cout << "Last Name: ";
    cin >> lastName;
    cout << "Address: ";
    cin >> address;
    cout << "Birthday Year (YYYY): ";
    cin >> bYear;
    cout << "Birthday Month (MM): ";
    cin >> bMonth;
    cout << "Birthday Day (DD): ";
    cin >> bDay;
    cout << "Anniversary Year (YYYY): ";
    cin >> aYear;
    cout << "Anniversary Month (MM): ";
    cin >> aMonth;
    cout << "Anniversary Day (DD): ";
    cin >> aDay;
    cout << endl;
    
    birthday.Initialize(bYear, bMonth, bDay);
    anniversary.Initialize(aYear, aMonth, aDay);
    addressEntry.Initialize(firstName, lastName, address, birthday, anniversary);
    
    addressBook.PutEntry(addressEntry);
}

void AddressManager::RemoveEntry()
{
    string lastName;

    bool entryFound;
    
    cout << "Last name of entry to be deleted: \n";
    cin >> lastName;
    
    AddressEntry entry(lastName);
    addressBook.GetEntry(entry, entryFound);
    
    if (entryFound) {
        addressBook.DeleteEntry(entry);
        cout << "Entry deleted!" << endl;
    } else {
        cout << "Entry not found!" << endl;
    }
    
    cout << endl;
}

void AddressManager::UpdateEntry()
{
    string lastName;
    AddressEntry newEntry;
    string newFirstName, newLastName, newAddress;
    Date newBirthday, newAnniversary;
    int newYear, newMonth, newDay;
    int menuChoice;
    bool entryFound = false;
    
    cout << "Last name of entry to be updated: \n";
    cin >> lastName;
    
    AddressEntry entry(lastName);

    addressBook.GetEntry(entry, entryFound);
    
    if (entryFound) {
        
        // set default values for new object
        newFirstName = entry.GetFirstName();
        newLastName = entry.GetLastName();
        newAddress = entry.GetAddress();
        newBirthday = entry.GetBirthday();
        newAnniversary = entry.GetAnniversary();
        
        cout << "What would you like to update?\n";
        cout << "1 - First Name\n";
        cout << "2 - Last Name\n";
        cout << "3 - Address\n";
        cout << "4 - Birthday\n";
        cout << "5 - Annivesary\n";
        cout << "6 - Cancel\n";
        cout << "Selection: ";
        
        cin >> menuChoice;
        
        // override desired attribute value
        switch(menuChoice) {
            case 1:
                cout << "Enter new first name: ";
                cin >> newFirstName;
                cout << "Entry first name updated!" << endl;
                break;
            case 2:
                cout << "Enter new last name: ";
                cin >> newLastName;
                cout << "Entry last name updated!" << endl;
                break;
            case 3:
                cout << "Enter new address: ";
                cin >> newAddress;
                cout << "Entry address updated!" << endl;
                break;
            case 4:
                cout << "Enter new birthday year (YYYY): ";
                cin >> newYear;
                cout << "Enter new birthday month (MM): ";
                cin >> newMonth;
                cout << "Enter new birthday day (DD): ";
                cin >> newDay;
                newBirthday.Initialize(newYear, newMonth, newDay);
                cout << "Entry birthday updated!" << endl;
                break;
            case 5:
                cout << "Enter new anniversary year (YYYY): ";
                cin >> newYear;
                cout << "Enter new anniversary month (MM): ";
                cin >> newMonth;
                cout << "Enter new anniversary day (DD): ";
                cin >> newDay;
                newAnniversary.Initialize(newYear, newMonth, newDay);
                cout << "Entry anniversary updated!" << endl;
                break;
            case 6:
                cout << "Update canceled!" << endl;
                break;
                
            default:
                break;
        }
        
        // replace old entry with new updated entry
        newEntry.Initialize(newFirstName, newLastName, newAddress, newBirthday, newAnniversary);
        addressBook.DeleteEntry(entry);
        addressBook.PutEntry(newEntry);
    } else {
        cout << "Entry not found!" << endl;
    }
    
    cout << endl;
}

void AddressManager::PrintEntries()
{
    addressBook.ResetList();
    AddressEntry entry;
    int length = addressBook.GetLength();

    for (int counter = 1; counter <= length; counter++)
    {
        entry = addressBook.GetNextEntry();
        entry.Print();
    }
    
    cout << endl;
}

void AddressManager::PrintBirthdayCards()
{
    addressBook.ResetList();
    AddressEntry entry;
    int length = addressBook.GetLength();
    Date today = GetCurrentDate();
    
    for (int counter = 1; counter <= length; counter++)
    {
        entry = addressBook.GetNextEntry();
        if (today.ComparedTo(entry.GetBirthday())) {
            cout << "\n";
            cout << "Dear " << entry.GetFirstName() << ",\n";
            cout << "Hope your birthday is really wonderful and this coming year is the best yet!\n";
            cout << "Best\n" << endl;
        }
    }
}

void AddressManager::PrintAnniversaryCards()
{
    addressBook.ResetList();
    AddressEntry entry;
    int length = addressBook.GetLength();
    Date today = GetCurrentDate();
    
    for (int counter = 1; counter <= length; counter++)
    {
        entry = addressBook.GetNextEntry();
        if (today.ComparedTo(entry.GetAnniversary())) {
            cout << "\n";
            cout << "Dear " << entry.GetFirstName() << ",\n";
            cout << "Hope your anniversary is really wonderful and this coming year is the best yet!\n";
            cout << "Best\n" << endl;
        }
    }
}














