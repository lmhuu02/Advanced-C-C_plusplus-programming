/*
power by le minh huu 16/11/2022 @LeHuu02 @copyright
yeu cau:
    - tao mot dslk so nguyen: nhap xuat ds
    - them phan tu vao dau, cuoi va vao vi tri k hoac sau phan tu co gia tri a
    - xoa ptu dau cuoi va vi tri k hoac co gia tri a;
    thuc hien:
        tao node, list, makenode, nhap xuat.
        khoi tao node, them/xoa dau them cuoi, them/xoa vi tri k, gtri a 
*/
#include <stdio.h>
#include <stdlib.h>

struct NODE{
    int data;
    NODE *next;
};
struct list{
    NODE *phead;
    NODE *ptall;
};
NODE *makeNode(int x){
    NODE *p;
    p = (NODE*)malloc(sizeof(NODE));
    p->data = x;
    p->next = NULL;
    return p;
}
void khoitao(list &l){
    l.phead = l.ptall =NULL;
}
void themdau(list &l, NODE *p){
    if(l.phead == NULL){
        l.phead = l.ptall = p;
    }else{
        p->next = l.phead;
        l.phead = p;        
    }
}
void themcuoi(list &l, int x){
    NODE *p = makeNode(x);
    if(l.phead == NULL){
        l.phead = l.ptall = p;
    }else{
        l.ptall->next = p;
        l.ptall = p;
    }
}
void nhapdsdau(list &l, NODE *p){
    int x;
    printf("\nnhap ds: ");
    for(int i = 0; i < 3; i++){
        scanf("%d", &x);
        p = makeNode(x);
        themdau(l,p);
    }
}
void nhapds(list &l){
    int x, n;
    printf("\nnhap ds: ");
    scanf("%d", &n);
    printf("\ncontinue: \n");
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        themcuoi(l,x);
    }
}
void xuatds(list &l){
    NODE *p;
    printf("\nds vua nhap: ");
    for(p = l.phead; p != NULL; p = p->next){
        printf("%d\t", p->data);
    }
}
void xoadau(list &l){
    l.phead = l.phead->next;
}
void xoacuoi(list &l){
     NODE *k;
     for(k = l.phead; k != NULL; k = k->next){        
        if(k->next == l.ptall){
            k->next = NULL;
            l.ptall = k;            
        }
     }
}
void xoak(list &l){
    int k, dem = 0;
    printf("\nnhap vi tri xoa: ");
    scanf("%d", &k);
    for(NODE *p = l.phead; p != NULL; p = p->next){
        dem++;
        if(dem == k - 1){            
            p->next = p->next->next;
        }
    }
}
void xoax(list &l){ //van ERROR: CHAY XONG HAM NAY THI THOAT LUON CHUONG TRINH -> DE CUOI
    int a;
    printf("\nnhap gia tri xoa: ");
    scanf("%d", &a);
    printf("\n ds sau khi xoa: ");
    for(NODE *p = l.phead; p != NULL; p = p->next){
        printf("%d\t",p->data);
        if(p->next->data == a){ // so sanh gia tri ngay sau p voi gia tri can xoa a
            // k->next = p->next;
            // printf("\nso sanh so sau - so a: %d - %d",p->next->data, a);
            p->next = p->next->next;    //thuc hien nhay qua gia tri a
            // printf("\nsau khi xoa: %d - %d",p->data, a);
        }
    }
    printf("\nERROR - KHONG IN DUOC CHU XIN CHAO: ");
}
void xoagt(list &l){
    int x, t, dem = 0;
    printf("\nnhap gia tri can xoa: ");
    scanf("%d", &x);
    //tim vi tri cua gia tri  can xoa roi luu vi tri vao bien t
    for(NODE *p = l.phead; p != NULL; p = p->next){
        dem++;
        if(p->data == x){
            t = dem;
        }
    }
    //thuc hien xoa tai vi tri t vua tim duoc o tren
    int a = 0;
    for(NODE *k = l.phead; k != NULL; k = k->next){
        a++;
        if(a == t - 1){ // vi tri truoc t thi cho tro qua vi tri t
            k->next = k->next->next;
        }
    }
}
void xoagtx2lan(list &l){
    
}

void themk(list &l){
    int k, x, dem = 0;
    printf("\nnhap vi tri k: ");
    scanf("%d", &k);
    printf("\nnhap gia tri them: ");
    scanf("%d", &x);
    for(NODE *p = l.phead; p != NULL; p = p->next){
        dem++;
        if(dem == k - 1){   //vi tri ngay truoc k
            NODE *a = makeNode(x);
            a->next = p->next;
            p->next = a;
        }
    }
}
void themsaux(list &l){
    int dem = 0, x, a;
    printf("\nnhap gia tri da dinh: ");
    scanf("%d", &x);
    printf("\ngia tri can them la: ");
    scanf("%d", &a);
    for(NODE *p = l.phead; p != NULL; p = p->next){
        if(p->data == x){
            NODE *k = makeNode(a);
            k->next = p->next;
            p->next = k;
        }
    }
}
void them2lanx(list &l){
    int dem = 0, x, a;
    printf("\nnhap gia tri them sau no: ");
    scanf("%d", &x);
    printf("\ngia tri can them la: ");
    scanf("%d", &a);
    for(NODE *p = l.phead; p != NULL; p = p->next){
        if(p->data == x){
            if(p->data == 3){
                NODE *k = makeNode(a);
                k->next = p->next;
                p->next = k; 
            }
            NODE *k = makeNode(a);
            k->next = p->next;
            p->next = k;
            
        }
    }
}
int main(){
    list l;
    NODE *p;
    // int x;
    // p = makeNode(x);
    khoitao(l);
    // nhapdsdau(l,p);
    nhapds(l);
    xuatds(l);
    // xoadau(l);
    // xoacuoi(l);    
    // xoak(l);
    // xuatds(l);
    // themk(l);
    // xuatds(l);
    // themsaux(l);
    // xuatds(l);
    them2lanx(l);
    xuatds(l);
    xoagt(l);
    xuatds(l);
    return 0;
}