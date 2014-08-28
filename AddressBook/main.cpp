//
//  AddressBook
//
//  Created by Jeffrey Jurgajtis.
//  Copyright (c) 2014 jeffreyjurgajtis. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include "AddressManager.h"

using namespace std;

int main()
{
    
    AddressManager addressManager;
    int menuChoice;
    
    do {
        
        addressManager.DisplayMainMenu();
        menuChoice = addressManager.GetMenuChoice();
        addressManager.DelegateMenuChoice(menuChoice);
        
    } while(menuChoice!=7);

    return EXIT_SUCCESS;

    return 0;
}
