//
//  AddressBook.cpp
//  AddressBook
//
//  Copyright (c) 2014 jeffreyjurgajtis. All rights reserved.
//

#include "AddressBook.h"

struct NodeType
{
    AddressEntry info;
    NodeType* next;
};

AddressBook::AddressBook() // Class constructor
{
    length = 0;
    listData = NULL;
}

bool AddressBook::IsFull() const
{
    NodeType* location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
}

int AddressBook::GetLength() const
{
    return length;
}

void AddressBook::MakeEmpty()
{
    NodeType* tempPtr;
    
    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}

AddressEntry AddressBook::GetEntry(AddressEntry& entry, bool& found)
{
    bool moreToSearch;
    NodeType* location;
    
    location = listData;
    found = false;
    moreToSearch = (location != NULL);
    
    while (moreToSearch && !found)
    {
        switch(entry.ComparedTo(location->info))
        {
            case GREATER: location = location->next;
                moreToSearch = (location != NULL);
                break;
            case EQUAL:   found = true;
                entry = location->info;
                break;
            case LESS:    moreToSearch = false;
                break;
        }
    }
    return entry;
}

void AddressBook::PutEntry(AddressEntry entry)
{
    NodeType* newNode;  	// pointer to node being inserted
    NodeType* predLoc;  	// trailing pointer
    NodeType* location; 	// traveling pointer
    bool moreToSearch;
    
    location = listData;
    predLoc = NULL;
    moreToSearch = (location != NULL);
    
    // Find insertion point.
    while (moreToSearch)
    {
        switch(entry.ComparedTo(location->info))
        {
            case GREATER:
                predLoc = location;
                location = location->next;
                moreToSearch = (location != NULL);
                break;
            case LESS:
                moreToSearch = false;
                break;
            case EQUAL:
                moreToSearch = false;
                break;
        }
        
    }
    
    // Prepare node for insertion
    newNode = new NodeType;
    newNode->info = entry;
    // Insert node into list.
    if (predLoc == NULL)         // Insert as first
    {
        newNode->next = listData;
        listData = newNode;
    }
    else
    {
        newNode->next = location;
        predLoc->next = newNode;
    }
    length++;
}

void AddressBook::DeleteEntry(AddressEntry entry)
{
    NodeType* location = listData;
    NodeType* tempLocation;
    
    // Locate node to be deleted.
    if (entry.ComparedTo(listData->info) == EQUAL)
    {
        tempLocation = location;
        listData = listData->next;	// Delete first node.
    }
    else
    {
        while (entry.ComparedTo((location->next)->info) != EQUAL)
            location = location->next;
        
        // Delete node at location->next
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}

void AddressBook::ResetList()
{
    currentPos = NULL;
}

AddressEntry AddressBook::GetNextEntry()
{
    AddressEntry entry;
    if (currentPos == NULL)
        currentPos = listData;
    entry = currentPos->info;
    currentPos = currentPos->next;
    return entry;
    
}

AddressBook::~AddressBook()
{
    NodeType* tempPtr;
    
    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
}