/*
power by le minh huu 16/11/2022 @LeHuu02 @copyright
yeu cau:
    - tao mot dslk doi tuong sinh vien: masv, tensv, diachi, diem, monhoc
    - nhap xuat ds
    - tim va in sinh vien hoc mon java co diem < 5
    - xoa sv co diem < 5
    - dem so sinh vien o thai nguyen
    lam them...
    - them phan tu vao dau, cuoi va vao vi tri k hoac sau phan tu co gia tri a
    - xoa ptu dau cuoi va vi tri k hoac co gia tri a; 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct sinhvien{
    char masv[100];
    char tensv[100];
    char diachi[100];
    char monhoc[100];
    float diemtb;
};
struct NODE{
    sinhvien data;
    NODE *next;
};
struct list{
    NODE *phead;
    NODE *ptall;
};
NODE *makeNode(sinhvien sv){
    NODE *p;
    p = (NODE *)malloc(sizeof(NODE));
    p->data = sv;
    p->next = NULL;
    return p;
}
void khoitao(list &l){
    l.phead = l.ptall = NULL;
}
void themcuoi(list &l, sinhvien sv){
    NODE *p = makeNode(sv);
    if(l.phead == NULL){
        l.phead = l.ptall = p;
    }else{
        l.ptall->next = p;
        l.ptall = p;
    }
}
void nhapds(list &l){
    int n;
    sinhvien sv;
    printf("\nnhap so luong sinh vien: ");
    scanf("%d", &n);
    printf("\nnhap thong tin sinh vien: ");
    for(int i = 0; i < n; i++){
        fflush(stdin);
        printf("\nsinh vien: %d", i+1);
        printf("\nma sv: ");
        gets(sv.masv);
        printf("nhap ten: ");
        gets(sv.tensv);
        printf("nhap dia chi: ");
        gets(sv.diachi);
        printf("nhap mon hoc: ");
        gets(sv.monhoc);
        fflush(stdin);
        printf("nhap diem: ");
        scanf("%f", &sv.diemtb);
        themcuoi(l,sv);
    }
}
void xuat(list l){
    int i = 0;
    printf("\nin danh sach vua nhap: ");
    printf("\n===========================================\n");
    for(NODE *p = l.phead; p != NULL; p = p->next){
        i++;
        printf("\nsinh vien thu: %d: ", i);
        printf("\nten: %s\t ma sv: %s\tdiachi: %s\t", p->data.tensv, p->data.masv, p->data.diachi);
        printf("\nmon hoc: %s\tdiem tb: %.2f\t", p->data.monhoc, p->data.diemtb);
    }
}
void timsv(list l){
    int dem = 0, i = 0;
    printf("\ndanh sach sinh vien co dem < 5 trong mon java la: ");
    for(NODE *p = l.phead; p != NULL; p = p ->next){
        if(p->data.diemtb < 5 && strcmp(p->data.monhoc, "java") == 0){
            i++;
            printf("\nsinh vien thu: %d: ", i);
            printf("\nten: %s\t ma sv: %s\tdiachi: %s\t", p->data.tensv, p->data.masv, p->data.diachi);
            printf("\nmon hoc: %s\tdiem tb: %.2f\t", p->data.monhoc, p->data.diemtb);
        }
    }
}
void xoadau(list &l){
    l.phead = l.phead->next;
}
void xoacuoi(list &l){
    //duyet het ds
    for(NODE *p = l.phead; p != NULL; p = p->next){
        //duyet den phan tu truoc pt cuoi
        if(p->next = l.ptall){
            l.ptall = p;
            p->next = NULL;
        }
    }
}
void xoasv5(list &l){
    /*
    vong lap tu dau den cuoi ds. trong vong lap cung co 2 vong lap tuong tu 
        de thuc hien tim kiem vi tri va thuc hien xoa gia tri tai vi tri vua tim duoc
    */
   int dem = 0, t = 0;
   //duyet  lan luot ds
//    for(NODE *p = l.phead; p  != NULL; p =  p->next){
        //tim vi tri can xoa
        for(NODE *m = l.phead; m != NULL; m = m->next){
            dem++;
            if(m->data.diemtb < 5){
                if(dem == 1){
                    xoadau(l);
                }
                t = 0;
            //xoa vi tri vua tim duoc
            for(NODE *p = l.phead; p != NULL; p = p->next){
                t++;
                if(t = dem - 1){
                    p->next = p->next->next;
                }   
            }    
            }
        }
//    }
}
void demsvtn(list l){
    int dem = 0, i = 0;
    for(NODE *p = l.phead; p != NULL; p = p->next){
        if(strcmp(p->data.diachi, "thai nguyen") == 0){
            dem++;
        }
    }
    if(dem == 0){
        printf("\nkhong co sinh vien nao tai thai nguyen ");
    }else{
        printf("\nco tong so %d sinh vien tai thai nguyen ", dem);
    }
}
int main(){
    list l;
    khoitao(l);
    nhapds(l);
    xuat(l);
    timsv(l);
    demsvtn(l);
    xoasv5(l);
    printf("\nds sau khi xoa sv co diem < 5");
    xuat(l);
    return 0;
}