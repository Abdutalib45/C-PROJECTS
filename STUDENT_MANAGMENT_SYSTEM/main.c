#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include"student.h"

void display (data*pd)
{
    int i;
    printf("\t\t\t\tStudent Name: %s\n",pd->name);
    printf("\t\t\t\tStudent Department: %d\n",pd->department);
    printf("\t\t\t\tStudent Roll: %s\n",pd->roll);
    printf("\t\t\t\tStudent SPGA: ");

    for(i=0;i<12;i++)
    printf("\t\t\t\t  %f\n",pd->sgpa[i]);

}
int main()
{
    data Data;
    Queue system;
    queue_create(&system);
    int i;
    uint8_t key=0,option;
main: printf("\t============== Student Management System ==============\n\n\t\t\tLab Final Spring 2017\n\n\t\t\t     The A Team\n\n\t\t\t   ABUTALIB SCHOOL\n");
    printf("\t\t    ==============================\n\n");
    printf("\t\t\tPress any key to enter");
    scanf("%c",&key);
    printf("\n\n");
    while (1)
    {
        printf("\t ============== Student Management System ==============\n\n\t   ***************************************************\n\n");
        printf("\t\t\t\t1. Add student\n\t\t\t\t2.Modify student\n\t\t\t\t3. Show All Student\n\t\t\t\t4. Individual View\n\t\t\t\t5. Remove Student\n\t\t\t\t7. Logout\n");
        printf("\t   ***************************************************\n\t\t\t\tEnter your option");
        scanf("%d",&option);
        switch (option)
        {
        case 1 :
            printf("\t ============== Student Management System ==============\n\t\t\tEnter Full Name of student: ");
            fflush(stdin);
            gets(Data.name);
            printf("\t\t\tEnter Department of student: ");
            gets(Data.department);
            printf("\t\t\tEnter roll of student: ");
            scanf("%d",Data.roll);
            printf("\t\t\tEnter SPGA of student: ");
            for(i=0;i<12;i++)
            {
                scanf("%f",Data.sgpa);
            }
            queue_push(&system,&Data);

            break;
        case 2 :
            printf("\t ============== Student Management System ==============\n");
            printf("\t\t\tEnter the student roll: ");
            scanf("%d",&i);
            printf("\t\t\tEnter Full Name of student: ");
            gets(Data.name);
            printf("\t\t\tEnter Department of student: ");
            gets(Data.department);
            printf("\t\t\tEnter roll of student: ");
            scanf("%d",Data.roll);
            printf("\t\t\tEnter SPGA of student: ");
            for(i=0;i<12;i++)
            {
                scanf("%f",Data.sgpa);
            }
            queue_modify(&system,&Data,i);


            break;
        case 3 :
            printf("\t ============== Student Management System ==============\n");

            if(queue_print(&system,&display)==failed)
            {
                printf("\t\t\t*** empty ***\n");
            }

            break;
        case 4 :
            printf("\t ============== Student Management System ==============\n");
            printf("\t\t\tEnter Student Roll to modify: \n");
            scanf("%d",&i);
            if(queue_print_element(&system,&display,i)==failed)
            {
                printf("\t\t\tRoll is incorrect\n");
            }
            break;
        case 5 :
            printf("\t ============== Student Management System ==============\n");
            printf("\t\t\tEnter Student Roll to delete: \n");
            scanf("%d",&i);
            queue_remove(&system,i);
            break;
        case 6 :
            goto main;
            break;
        }




    }
    return 0;
}
