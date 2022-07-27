#include <stdio.h>
#include <stdlib.h>
int top;
int size;

typedef struct stack_data {
    int data;
    int position;
    struct stack_data *next;
} *Stack;

Stack init_stack(int temp){
    top = -1;
    size = temp;
    Stack p = malloc(sizeof(struct stack_data));
    p->position = -1;
    p->next = NULL;
    return p;
}
void push(Stack node, int value)
{
    Stack p = node;
    if (p->position == -1) {
        top++;
        p->data = value;
        p->position=top;
        p->next = NULL;
    } else {
        while (p->next != NULL){
            p = p->next;
        }
        Stack new = malloc(sizeof(struct stack_data));
        top++;
        new->data = value;
        new->position = top;
        new->next = NULL;
        p->next = new;
    }
};
void pop(Stack node){
    Stack p = node;
    Stack temp;
    if (top > -1){
        if (p->position == 0 && p->next == NULL){
            top = -1;
        } else {
            while (p->next != NULL){
                temp = p;
                p = p->next;
            }
            temp->next = NULL;
            free(p);
            top--;
        }
    }
}
int IsEmpty(){
    if (top == -1) return 1;
    else return 0;
}
int IsFull(){
    if (top == size) return 1;
    else return 0;
}
int Last_node(Stack node){
    Stack p = node;
    while (p->position != top){
        p = p->next;
    }
    return p->data;
}
void Show_all_node(Stack node){
    int i=0;
    Stack p = node;
    if (p == NULL || top == -1){
        printf("Khong co phan tu");

    } else {
    printf("Node %d = %d, position %d,next = %x, add = %x\n",i,p->data,p->position,p->next,p);
    while (p->next != NULL){
        p = p->next;
        i++;
        printf("Node %d = %d, position %d,next = %x, add =%x\n",i,p->data,p->position,p->next,p);
    };
    }
}
void Enter_Stack(Stack node)
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
        push(node,value);
    }
}
int main(int argc, char const *argv[])
{

    size = 5;
    Stack vt = init_stack(size);
    Enter_Stack(vt);
    int i;
    printf("Nhap so phan tu muon remove ");
    scanf("%d",&i);
    while (i>0){
        i--;
        pop(vt);
    }
    Show_all_node(vt);
    return 0;
}
