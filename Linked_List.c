#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
    int data;
    struct List *next;
} *Vector;

Vector Create_New_Node(int value){
    Vector node;
    node = (Vector)malloc(sizeof(struct List));
    node->data = value;
    node->next = NULL;
    return node;
}
Vector Vector_push_back(Vector node, int value){
    Vector temp,p;
    temp = Create_New_Node(value);
    if (node == NULL){
        node = temp;
    }else
    {
        p = node;
        while (p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
    return node;
}

Vector Init_Linked_List()
{
    Vector first = NULL;
    int n, value;
    do 
    {
        printf("Nhap so phan tu n= ");
        scanf("%d",&n);
    } while (n<=0);

    for (int i=0; i < n; i++)
    {
        printf("Nhap gia tri so %d = ",i+1);
        scanf("%d",&value);
        first = Vector_push_back(first,value);
    }
    return first;
}

int Get(Vector node,int index){
    int i = 0;
    Vector p = node;
    while (p->next != NULL && i != index){
        i++;
        p = p->next;
    }
    return p->data;
}
int main(int argc, char const *argv[])
{
    Vector vt = Init_Linked_List();
    printf("Gia tri so 3 %d",Get(vt,2));
    return 0;
}


