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

/*kiem tra ds rong*/
int isempty(list L)
{
    /*kiem tra neu danh sach L = rong thi tra ve 1 con neu != -> tra ve 0*/
    return(L == NULL);
}


/*tao Node P co du lieu la x*/
node *MakeNode(node *p, item x)
{
    p = (node*)malloc(sizeof(node));    /*cap phat dong cho con tro p*/
    p->next = NULL; /*p tro den phan tu dau tien cua list L*/
    p->data = x;    /*ghi gtri x vao truong data*/
    return p;   /*tra ve mot node p gon data va p-> next*/
}

/*tinh do dai ds -> duyet tu dau den khi nao tro den NULL thi dung*/
int len(list L)
{
    int dem = 0;
    node *q = L;    /*tao mot node q*/
    // q = L;      /*tro node q den phan tu dau tien list L*/
    /*lap den khi nao q tro den Null thi ket thu*/
    while(q != NULL)
    {
        dem++;  /*khi q->next chua den cuoi thi tang dem*/
        q = q->next;    /*cho q tro den o nho tiep theo*/
    }
    return dem; /*tra ve so phan tu ds*/
}

/*insert frist, truyen vao gia tri x*/
void insert(list &L, item x)
{
    node *p;    /*khai bao con tro p kieu node*/
    p = MakeNode(p,x);  /*tao node p*/
    p->next = L;    /*p tro den vi tri dau tien cua ds L*/
    L = p;  /*l tro den vi tri dau tien cu ds la p*/
}

/*insert k tao con tro q tro tu dau den k -1*/
void insert_k(list &L, item x, int k)
{
    node *p, *q = L;
    int i = 1;
    /*kiem tra vi tri chen */
    if(k < 1 || k > len(L)+1)
    {
        printf("\nvi tri chen khong hop le!\n");
    }else{  /*vi tri chen hop le*/
        /*tao node p chen gia tri x*/
        p = MakeNode(p,x);
        /*neu chen vao vi tri dau tien*/
        if(k == 1)
        {
            insert(L,x);
        }else{  /*chen vao vi tri khac 1, tro den k -1*/
            while(q != NULL && i != k-1 )
            {
                i++;
                q = q->next;
            }
            /*khi den vi tri k-1 roi*/
            p->next = q->next;
            q->next = p;
        }
        
    }

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
        if(x != 0)
        {
            insert_k(L,x,len(L)+1);
        }
    }while(x != 0);
}
/*output data*/
void output(list L)
{
    printf("\nin thong tin ra man hinh:\n");
    node *p = L;
    while(p != NULL)
    {
        printf("\t%d", p->data);
        p = p->next;
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
