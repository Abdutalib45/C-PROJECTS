#define CUSTOMER_SIZE 3
#include <stdio.h>
typedef struct customer
    {
        char name[60];
        char type[10];
        int id;
        float cash;
    }customer1;
   extern int counter;
   extern customer1 customer[CUSTOMER_SIZE];
   char main_menu (void)
   {
       unsigned char choice=100;
       printf ("1-Add new customer (press 1 to this choice )\n");
       printf ("2-Edit customer data (press 2 to this choice )\n");
       printf ("3-Delete customer (press 3 to this choice )\n");
       printf ("4-Print customer data (press 4 to this choice )\n");
       printf ("5-Cash transfer from customer to another (press 5 to this choice )\n");
       printf ("6-Exit to main menu (press 6 to this choice )\n");
       scanf("%i",&choice);
       return choice;
   }
   void add_customer (void)
   {
       if (counter<CUSTOMER_SIZE)
       {
            printf ("customer name : \n");
            fflush(stdin);
            gets(customer[counter].name);
            printf ("customer id : \n");
            scanf("%i",&customer[counter].id);
            printf ("customer type : \n");
            fflush(stdin);
            gets(customer[counter].type);
            printf ("customer cash : \n");
            scanf("%f",&customer[counter].cash);
            counter++;
       }
       else
       {
            printf ("sorry,bank have no space.\n");
       }
   }
   void edit_customer (void)
   {
       int id,i;
       label: printf ("Customer id : \n");
       scanf ("%i",&id);
       for (i=0;i<counter;i++)
       {
           if (id==customer[i].id)
           {
               id=i;
               break;
           }
       }
    if (id==i)
    {
            printf ("customer name : \n");
            fflush(stdin);
            gets(customer[i].name);
            printf ("customer id : \n");
            scanf("%i",&customer[i].id);
            printf ("customer type : \n");
            fflush(stdin);
            gets(customer[i].type);
            printf ("customer cash : \n");
            scanf("%f",&customer[i].cash);

    }
    else
    {
        printf("Wrong id\n");
        goto label;

    }
   }
   void print_customer (void)
   {
       int id,i;
       label2: printf ("Customer id : \n");
       scanf ("%i",&id);
       for (i=0;i<counter;i++)
       {
           if (id==customer[i].id)
           {
               id=i;
               break;
           }
       }
    if (id==i)
    {
            printf ("customer name : %s \n",customer[i].name);
            printf ("customer id : %i\n",customer[i].id);
            printf ("customer type : %s\n",customer[i].type);
            printf ("customer cash : %.2f\n",customer[i].cash);

    }
    else
    {
        printf("Wrong id\n");
        goto label2;

    }
   }
   void cash_transfer (void)
   {
       int id1,id2,i;
       float cash;
       printf ("id to transfer from :\n");
       scanf ("%i",&id1);
       printf ("id to transfer for :\n");
       scanf ("%i",&id2);
       printf ("cash you want to transfer :\n");
       scanf ("%f",&cash);
       for (i=0;i<counter;i++)
       {
           if (customer[i].id==id1)
           {
               id1=i;
           }
           if (customer[i].id==id2)
           {
               id2=i;
           }
       }
       customer[id1].cash-=cash;
       customer[id2].cash+=cash;
   }
   void delete_customer(void)
   {
       int id,i;
      label3: printf("customer id :\n");
       scanf("%i",&id);
       for (i=0;i<counter;i++)
       {
           if (id==customer[i].id)
           {
              id=i;
              break;
           }
       }
       if (id==i)
       {
            for (int j=id;j<counter;j++)
                {
                       customer[j]=customer[j+1];
                }
                counter--;
       }
       else
        {
           printf("Wrong id.\n");
           goto label3;
        }
   }
