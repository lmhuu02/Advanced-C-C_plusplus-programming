/*
power by le minh huu 28/9/2022
danh sach lien ket don 
readme: 
    1. khai bao con tro list kieu node
    2. kiem tra ds rong, khoi tao ds rong
    3. tinh do dai ds
    4. tao mot node -> makenode
    5. input, output.
*/

#include <stdio.h>
#include <stdlib.h>

/*dinh nghia kieu dl item thuoc kieu int*/
typedef int item;

/*dinh nghia con tro list kieu node*/
struct node
{
    item data;
    node *next;
};
typedef node *list; /*danh sach cac node: list*/

/*khoi tao ds list rong phai truyen vao tham chieu tu ham main de co the thay doi gia tri*/
void init(list &L)
{
    L = NULL;
}

/*tao Node P co du lieu la x*/
node *MakeNode(node *p, item x)
{
    p = (node*)malloc(sizeof(node));    /*cap phat dong cho con tro p*/
    p->next = NULL; /*p tro den phan tu dau tien cua list L*/
    p->data = x;    /*ghi gtri x vao truong data*/
    return p;   /*tra ve mot node p gon data va p-> next*/
}


/*input data*/
void input(list &L)
{
    printf("\nnhap thong tin: \n");
    item x;
    int i = 0;
    do{
        i++;
        printf("\nphan tu thu %d: ", i);
        scanf("%d", &x);
        
        // if(x != 0)
        // {
            node  *q = L;
            q = MakeNode(q,x);
            q = q->next; 
            // q->data = x;
        // }
    }while(x != 0);
}
/*output data*/
void output(list L)
{
    printf("\nin thong tin ra man hinh:\n");
    node *q = L;
    q = q->next;
    printf("\tso: %d", q->data);
    while(q != NULL)
    {
        printf("laan");
        printf("\tso: %d", q->data);
        q = q->next;
    }
}

/*function main*/
int main()
{
    list L;
    init(L);
    input(L);
    output(L);

    return 0;
}







	#include "stdio.h"
	#include "stdlib.h"
	struct NODE {
		int data;
		NODE *pnext;
	};
	
	struct LIST{
		NODE *phead;
		NODE *ptail;
	};
	void khoitao(LIST &l){
		l.phead = NULL;
		l.ptail = NULL;
	}
	// KHOI TAO NODE
	
	NODE *pkhoitaoNODE(int a){
		NODE* p = (NODE*)malloc(sizeof(NODE));
		p->data = a;
		p->pnext = NULL;
		return p;
	}
	void Themdau(LIST &l, NODE *p){
		if(l.phead==NULL)
		l.phead = l.ptail = p;
		else {
			p->pnext = l.phead;
			l.phead =p;
		}
	}
	void ThemCuoi(LIST &l, NODE *p){
		if(l.phead==NULL)
		l.phead = l.ptail = p;
		else {
			l.ptail ->pnext = p;
			l.ptail = p;
		}
	}
	void hienthi(LIST l ){
		for(NODE *k = l.phead; k!=NULL; k =k->pnext)
		printf("%2d", k->data);
	}
	int main(){
		LIST l;
		int a;
		khoitao(l);
		// khoi taoo node

		for(int i=0; i<5;i++){
			scanf("%d",&a);
			NODE* p = pkhoitaoNODE(a);
			//Themdau(l,p);
			ThemCuoi(l,p);
		}
		hienthi(l);
	}