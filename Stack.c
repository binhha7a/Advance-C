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
void pull(Stack node){
    Stack p = node;
    Stack temp;
    if (top > -1){
        if (p->next == NULL){
            free(p);
            top--;
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
    if (p == NULL){
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
int main(int argc, char const *argv[])
{
    //printf("Enter size of stack ");
    //scanf("%d",&size);
    size = 5;
    Stack vt = init_stack(size);
    push(vt,100);
    push(vt,111);
    printf("data = %d,position = %d , add= %x\n",vt->data,vt->position,vt);
    Show_all_node(vt);
    return 0;
}
