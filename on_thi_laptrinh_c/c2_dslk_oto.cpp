/*
power by le minh huu 16/11/2022 @LeHuu02 @copyright
yeu cau:
    - tao mot dslk doi tuong xe: ten, hang, phienban, noisx, giaban
    - nhap xuat ds
    - dem oto sx tai viet nam
    - xoa o to thu 2, xoa o to co gia > 200000
    lam them...
    - them phan tu vao dau, cuoi va vao vi tri k hoac sau phan tu co gia tri a
    - xoa ptu dau cuoi va vi tri k hoac co gia tri a; 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct oto{
    char ten[100];
    char hangxe[100];
    char phienban[100];
    char noisx[100];
    int giaban;
};
struct NODE{
    oto data;
    NODE *next;
};
struct list{
    NODE *phead;
    NODE *ptall;
};
NODE *makeNode(oto data){
    NODE *p = (NODE*)malloc(sizeof(NODE));
    p->data = data;
    p->next = NULL;
    return p;
}
void khoitao(list &l){
    l.phead = l.ptall = NULL;
}
void themcuoi(list &l, oto xe){
    NODE *p = makeNode(xe);
    if(l.phead == NULL){
        l.phead = l.ptall = p;
    }else{
        l.ptall->next = p;
        l.ptall = p;
    }
}
void xoadau(list &l){
    l.phead = l.phead->next;
}
void nhapds(list &l){
    int n;
    oto xe;
    printf("\nnhap so luong xe: ");
    scanf("%d", &n);
    printf("\n nhap thong tin xe: ");
    for(int i = 0; i < n; i++){
        printf("\nxe thu %d: ", i+1);
        fflush(stdin);
        printf("\nten xe: ");
        gets(xe.ten);
        printf("hang xe: ");
        gets(xe.hangxe);
        printf("phien ban: ");
        gets(xe.phienban);
        printf("noi sx: ");
        gets(xe.noisx);
        fflush(stdin);
        printf("gia ban: ");
        scanf("%d", &xe.giaban);
        themcuoi(l,xe);
    }
}
void xuat(list l){
    printf("\nin thong tin xe: ");
    printf("\n==========================================\n");
    int i = 0;
    for(NODE *p = l.phead; p != NULL; p = p->next){
        i++;
        printf("\nxe thu %d: ", i);
        printf("\nten: %s\thang: %s\tphien ban: %s", p->data.ten, p->data.hangxe, p->data.phienban);
        printf("\nnoi sx: %s\tgia ban: %d", p->data.noisx, p->data.giaban);
    }
}
void demxe(list l){
    int dem = 0;
    for(NODE *p = l.phead; p != NULL; p = p->next){
        if(strcmp(p->data.noisx, "Viet Nam") == 0){
            dem++;
        }
    }
    if(dem == 0){
        printf("\nkhong co xe den tu Viet Nam: ");
    }else{
        printf("\nco %d xe den tu Viet Nam.", dem);
    }
}
void xoaxe(list &l){
    //su dung 2 vong for de duyet tim vi tri can xo va for2 xoa vi tri vua tim duoc
    int dem = 0, t = 0;
    //duyet tim vi tri can xoa
    for(NODE *m = l.phead; m != NULL; m = m->next){
        dem++;
        if(m->data.giaban > 20000){
                t = 0;
                //neu vi tri = 1 -> xoa dau
                if(dem == 1){
                    xoadau(l);
                }
            //xoa phan tu tai vi tri vua tim
            for(NODE *p = l.phead; p != NULL; p = p->next){
                t++;
                if(t == dem - 1){
                    p->next = p->next->next;
                }
            }
        }
    }
}
void xoa2(list &l){
    //xoa xe o vi tri thu 2
    NODE *k = l.phead;
    k->next = k->next->next;
}
void timkiem(list l){
    //nhap ten xe in ra thong tin
    char nhap[100]; //tao chuoi nhap ten xe can tim
    printf("\nnhap ten xe can tim: ");
    fflush(stdin);  //xoa bo nho dem
    gets(nhap);
    int n;  //dem xe chuoi vua nhap la bao nhieu ky tu luu vao bien n
    n = strlen(nhap);
    char temp[n];
    for(NODE *p = l.phead; p != NULL; p = p->next){
        if(strcmp(p->data.ten, strcpy(temp,nhap)) == 0){
            printf("\nthong tin xe can tim: ");
            printf("\nten: %s\thang: %s\tphien ban: %s", p->data.ten, p->data.hangxe, p->data.phienban);
            printf("\nnoi sx: %s\tgia ban: %d", p->data.noisx, p->data.giaban);
        }
    }
}
int main(){
    list l;
    khoitao(l);
    nhapds(l);
    xuat(l);
    // demxe(l);
    // xoadau(l);
    // printf("\nds da xoa dau: ");
    // xuat(l);
    // printf("\nds da xoa thu 2: ");
    // xoa2(l);
    // printf("\nds da xoa xe gia > 20000: ");
    // xoaxe(l);
    timkiem(l);    
    // xuat(l);
    return 0;
}