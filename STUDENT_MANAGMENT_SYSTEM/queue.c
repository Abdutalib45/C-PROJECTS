#include"student.h"
#include <stdlib.h>

status queue_create(Queue*pq)
{
    pq->head =NULL;
    pq->lenght=0;
    return done;
}

status queue_push (Queue*pq,data*pd)
{
    if (queue_empty(pq)==etrue)
    {
        push_first(pq,pd);
        return done;
    }
    else
    {
        node*temp=pq->head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }

        temp->next=(node*)malloc(sizeof(node));
        if(temp->next==NULL)
            return failed;
        temp->next->student=*pd;
        temp->next->next=NULL;
        pq->lenght++;
    }


}



status queue_empty (Queue*pq)
{
    if (pq->lenght == 0 )
        return etrue;
    else
        return efalse;
}
status push_first (Queue*pq,data*pd)
{
    node*temp = (node*)malloc(sizeof(node));
    if(temp!=NULL)
        return failed;
    else
    {
        pq->head =temp;
        pq->head->student=*pd;
        pq->head->next= NULL;
        pq->lenght++;
        return done;

    }
}
status queue_pop(Queue*pq,data*pd)
{
    if(queue_empty(pq)==etrue)
        return failed;
    else
    {
        node*temp=pq->head;
        *pd=pq->head->student;
        pq->lenght--;
        pq->head=pq->head->next;
        free(temp);
        return done;
    }
}

status queue_print (Queue*pq,void (*pf)(data*))
{
    if (queue_empty(pq)==etrue)
        return failed;
    else
    {
        node*temp=pq->head;
        while (temp!=NULL)
        {
            (*pf)(&temp->student);
            temp=temp->next;
        }
        return done;
    }
}
status queue_modify(Queue*pq,data*pd,int roll)
{
    node*temp=pq->head;
    while(temp->student.roll!=roll&&temp)
    {
        temp=temp->next;
    }
    if(temp)
    {
        temp->student=*pd;
        return done;
    }
    return failed;

}
status queue_print_element (Queue*pq,void (*pf)(data*),int roll)
{
    node*temp=pq->head;
    while(temp->student.roll!=roll&&temp)
    {
        temp=temp->next;
    }
    if(temp)
    {
        (*pf)(&temp->student);
        return done;
    }
    return failed;
}
status queue_remove (Queue*pq,data*pd,int roll)
{
    node*temp=pq->head;
    while(temp->next->student.roll!=roll&&temp->next)
    {
        temp=temp->next;
    }
    if(temp->next)
    {
        node*temp2=temp->next;
        temp->next=temp->next->next;
        free(temp2);
        return done;
    }
    return failed;
}
