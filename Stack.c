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
    Stack p = NULL;
    return p;
}
void push(Stack node, int value)
{
    // if (top == size){
    //     printf("Stack is full, cannot push");
    // } else {
    //     Stack p = node;
    //     if (p == NULL){
    //         top++;
    //         p->data = value;
    //         p->position = top;
    //         p->next = NULL;
    //     } else {
    //         while (p->next != NULL){
    //             p = p->next;
    //         }
        
    //     top++;
    //     Stack new;
    //     p->next = new;
    //     new->data = value;
    //     new->position = top;
    //     }
    // }
    Stack p = node;
    if (p == NULL) {
        top++;
        p->data = value;
        p->position = top;
    } else {
        while (p->next != NULL){
            p = p->next;
        }
        Stack new;
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
            p = NULL;
            top--;
        } else {
            while (p->next != NULL){
                temp = p;
                p = p->next;
            }
            temp->next = NULL;
            p = NULL;
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
    printf("Node %d = %d\n",i,p->data);
    while (p->next != NULL){
        p = p->next;
        i++;
        printf("Node %d = %d\n",i,p->data);
    };
    }
}
int main(int argc, char const *argv[])
{
    printf("Enter size of stack ");
    scanf("%d",&size);
    Stack vt = init_stack(size);
    push(vt,100);
    Show_all_node(vt);
    return 0;
}
