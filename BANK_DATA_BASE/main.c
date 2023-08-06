#include <stdio.h>
#include <stdlib.h>
#include "bank.h"
int counter;
customer1 customer[CUSTOMER_SIZE];
int main()
{
    char choise;
   labell: choise = main_menu();
    switch (choise)
    {
    case 1:
        add_customer ();
        goto labell;
        break;
    case 2:
        edit_customer ();
        goto labell;
        break;
    case 3:
        delete_customer();
        goto labell;
        break;
    case 4:
        print_customer ();
        goto labell;
        break;
     case 5:
        cash_transfer ();
        goto labell;
        break;
     case 6:
        break;
    }

    return 0;
}
