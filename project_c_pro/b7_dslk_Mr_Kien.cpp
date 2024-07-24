/*

1.  tao node
2. tao list struct  tro dau va cuoi
3. khoi tao node 
4. them dau cuoi giua
5. hien thi

*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    node *next;
};

struct LIST
{
    node *head;
    node *tail;
};

void init(LIST &L)
{
    L.head = NULL;
    L.tail = NULL;
}

node *MakeNode(int x)
{
    node *p = (node*)malloc(sizeof(node));
    p->data = x;
    p->next = NULL;
    return p;
}

void themdau(LIST &L,node *p)
{
    if(L.head == NULL)
    {
        L.head = L.tail = p;
    }else{
        p->next = L.head;
        L.head = p;
    }
}

void hienthi(LIST L)
{
//	printf("so");
    for(node *k = L.head; k != NULL; k = k->next)
    {
        printf("\tSo: %d", k->data);
    }
}

int main()
{
    LIST L;
    int a;
    init(L);
    for(int i = 0; i < 3; i++)
    {
    	printf("nhap so thu %d la: \n",i+1);
        scanf("%d", &a);
        node *p = MakeNode(a);
        themdau(L, p);
    }
    hienthi(L);
    return 0;
}
