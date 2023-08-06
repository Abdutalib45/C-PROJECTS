typedef struct data{

    char name[40];
    char department[10];
    int roll;
    float sgpa[12];

}data;
typedef enum status{

    efalse,
    etrue,
    done,
    failed


}status;
typedef struct node{

    data student;
    struct node* next;

}node;

typedef struct Queue{

    node*head;
    int lenght;

}Queue;

status queue_create(Queue*pq);
status queue_push (Queue*pq,data*pd);
status queue_empty (Queue*pq);
status push_first (Queue*pq,data*pd);
status queue_pop(Queue*pq,data*pd);
status queue_print (Queue*pq,void (*pf)(data*));
status queue_print_element (Queue*pq,void (*pf)(data*),int roll);


