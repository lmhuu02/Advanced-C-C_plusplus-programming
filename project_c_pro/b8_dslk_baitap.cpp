/*
POWER BY LE MINH HUU 6/10/2022
Cho thông tin về một chiếc Ô Tô bao gồm: Tên ô tô, hãng sản xuất,
 phiên bản, nơi sản xuất, giá bán. Hãy thực hiện các công việc sau sử dụng danh sách liên kết:
a, Nhập vào một danh sách Ô Tô sử dụng danh sách liên kết.
b, In danh sách Ô Tô vừa nhập lên màn hình.
c, Tìm danh sách Ô Tô nhập khẩu từ Hungary.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50

struct oto{
    char ten[N];
    char hang[N];
    char phienban[N];
    char sanxuat[N];
    int giaban;
};
struct node{
    oto data;
    node *pnext;
};
struct list{
    node *phead;
    node *ptail;
};
void khoitao(list &l){
    l.phead = NULL;
    l.ptail = NULL;
}
node *makenode(oto data){
    node *p = (node*)malloc(sizeof(node));
    p->data = data;
    p->pnext = NULL;
    return p;
}
void themdau(list &l, node *p){
    if(l.ptail == NULL)
        l.phead = l.ptail = p;
    else{
        p->pnext = l.phead;
        l.phead = p;
    }
}
void themcuoi(list &l, node *p){
    if(l.phead == NULL)
        l.phead = l.ptail = p;
    else{
        l.ptail->pnext = p;
        l.ptail = p;

    }
}
void input(list &l){
    oto data;
    int i = 0;
    printf("nhap thong tin xe: ");
    do{
        i++;
        printf("nhap xe thu: %d\n ", i);
        fflush(stdin);
        printf("nhap ten xe: ");
        gets(data.ten);
        if(strcmp(data.ten,"ok") != 0){
            node *p = makenode(data);
            themcuoi(l,p);
        }else if(strcmp(data.ten,"ok") == 0){
            break;
        }
        printf("nhap hang xe: ");
        gets(data.hang);
        printf("nhap phien ban: ");
        gets(data.phienban);
        printf("nhap noi san xuat: ");
        gets(data.sanxuat);
        fflush(stdin);
        printf("nhap gia ban: ");
        scanf("%d", &data.giaban);
    }while(strcmp(data.ten,"ok") != 0);
}

void hienthi(list l){
    printf("in phan tu vua nhap: \n");
    for(node *k = l.phead; k != NULL; k = k->pnext ){
        printf("nhap xe thu: %d\n ", i);
        fflush(stdin);
        printf("nhap ten xe: ");
        gets(data.ten);
     
        printf("nhap hang xe: ");
        gets(data.hang);
        printf("nhap phien ban: ");
        gets(data.phienban);
        printf("nhap noi san xuat: ");
        gets(data.sanxuat);
        fflush(stdin);
        printf("nhap gia ban: ");
        scanf("%d", &data.giaban);
        
    }
}

int main(){
    list l;
    int a;
    khoitao(l);
    input(l);
    hienthi(l);
    return 0;
}







    // do{
    //     printf("nhap: ");
    //     scanf("%d", &a);
    //     node *p = makenode(a);
    //     // themdau(l,p);
    //     if(a != 0){
    //         themcuoi(l,p);
    //     }        
    // }while(a != 0);