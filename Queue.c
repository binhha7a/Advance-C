#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
int front,rear,size;
typedef struct Queue_parameter
{
    int data;
    struct Queue_parameter *next;
    int position;
} *Queue;

Queue Init_Queue(int temp){
    front = 0;
    rear = -1;
    size = temp;
    Queue p = malloc(sizeof(struct Queue_parameter));
    p->next = NULL;
    return p;
}
void Dequeue(Queue vt){
    if (rear - front > 0){
        front++;
        Queue p = vt->next;
        vt->next = vt->next->next;
        free(p);
    }
}
void Enqueue(Queue vt, int value){
    if (rear - front < size){
        Queue p = vt;
        while (p->next != NULL){
            p = p->next;
        }
        rear++;
        Queue new = malloc(sizeof(struct Queue_parameter));
        new->data = value;
        new->next = NULL;
        new->position = rear;
        p->next = new;
    }
}
void Show_all_node(Queue node){
    int i=0;
    Queue p = node;
    if (rear - front < 0){
        printf("Khong co phan tu");

    } else {
    //printf("Node %d = %d, position %d,next = %x, add = %x\n",i,p->data,p->position,p->next,p);
    while (p->next != NULL){
        p = p->next;
        i++;
        printf("Node %d = %d, position %d,next = %x, add =%x\n",i,p->data,p->position,p->next,p);
    };
    }
}
int IsEmpty(){
    if (rear<front) return 1;
    return 0;
}
int IsFull(){
    if (rear - front == size) return 1;
    return 0;
}
void Enter_Queue(Queue node)
{
    int n, value;
    do 
    {
        printf("Nhap so phan tu n= ");
        scanf("%d",&n);
    } while (n<=0);

    for (int i=0; i < n; i++)
    {
        printf("Nhap gia tri so %d = ",i);
        scanf("%d",&value);
        Enqueue(node,value);
    }
}
int main(int argc, char const *argv[])
{
    int temp;
    printf("Enter size of Queue ");
    scanf("%d",&temp);
    Queue vt = Init_Queue(temp);
    Enter_Queue(vt);
    Dequeue(vt);
    Show_all_node(vt);
    return 0;
}
