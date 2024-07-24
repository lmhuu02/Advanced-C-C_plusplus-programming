#include <stdio.h>
#include <stdlib.H>

struct node{
    int data;
    node *next;
};
struct list{
    node *phead;
    node *ptail;
};
void init(list &l){
    l.phead = NULL;
    l.ptail = NULL;
}
node *makenode(int x){
    node *p = (node*)malloc(sizeof(node));
    p->next = NULL;
    p->data = x;
    return p;
}
void insert_last(list &l, node *p){
    if(l.phead == NULL){    // neu ds chua tro den dau thi 
        l.phead = l.ptail = p;  //cho tro den node p
    }else{        
        l.ptail->next = p;  //node cuoi ds tro den vi tri node p
        l.ptail = p;        // node cuoi ds tro den vi tri p -> bao toan l.tail la vi tri cuoi ds
    }
}
void input(list &l){
    int x, i = 0;        
    printf("nhap thong tin:\n");
    do{        
        i++;
        printf("nhap phan tu %d: ", i);
        scanf("%d", &x);
       node *p = makenode(x);
        if(x != 0){
            insert_last(l,p);
        }
    }while(x != 0);
}
void del_first(list &l){    
    l.phead = l.phead->next;
}
void del_last(list &l){
    int i = 0;
    for(node *p = l.phead; p != NULL; p = p->next){
        i++;
        if(i)
    }
}
void output(list l){
    int i = 0;
    node *p = l.phead;
    while(p != NULL ){
        printf(" %d\t", p->data);
        p = p->next;
    }    
}
void insert_k(list &l){
    int i = 0, x, k;
    printf("\nnhap vi tri can chen: ");
    scanf("%d", &k);
    if(k < 1){
        printf("vi tri chen khong hop le: ");
    }
    for(node *qq = l.phead; qq != NULL; qq = qq->next){
        i++;
        if(i == (k-1)){
            printf("nhap gia tri can chen: ");
            scanf("%d", &x);
            node *p = makenode(x);
            p->next = qq->next;
            qq->next = p;
            break;
        }        
    }
}

int main(){
    list l;
    input(l);
    output(l);
    insert_k(l);
    output(l);
    return 0;
}
