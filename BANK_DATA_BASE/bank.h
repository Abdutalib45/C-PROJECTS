#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED
#define CUSTOMER_SIZE 3

typedef struct customer
    {
        char name[60];
        char type[10];
        int id;
        double cash;
    }customer1;
char main_menu (void);
void add_customer (void);
void edit_customer (void);
void print_customer (void);
void cash_transfer (void);
void delete_customer(void);
#endif // BANK_H_INCLUDED
