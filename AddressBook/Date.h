//
//  Date.h
//  AddressBook
//
//  Copyright (c) 2014 jeffreyjurgajtis. All rights reserved.
//

#ifndef Date_h
#define Date_h
#include <string>

using namespace std;

class Date
{
public:
    bool ComparedTo(Date) const;
    string Format();
    void Initialize(int, int, int);
    
private:
    int day;
    int month;
    int year;
};

#endif
