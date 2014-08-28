//
//  Date.cpp
//  AddressBook
//
//  Copyright (c) 2014 jeffreyjurgajtis. All rights reserved.
//

#include "Date.h"
#include <iostream>
#include <string>

using namespace std;
    
bool Date::ComparedTo(Date date) const
{
    return (date.year == year && date.month == month && date.day == day);
};
    
string Date::Format()
{
    return (to_string(year) + '/' + to_string(month) + '/' + to_string(day));
};
    
void Date::Initialize(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
};