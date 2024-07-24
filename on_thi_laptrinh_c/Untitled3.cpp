#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>
struct lop
{
	char ma[10],ten[20],khoa[10],truong[20];
	int sosv;
};
typedef struct lop LOP;
struct node 
{
	LOP* lophoc;
	struct node * next; 
};
typedef struct node NODE;
struct danhsach
{
		NODE*dau,*cuoi;	
};
typedef struct danhsach DANHSACH;
void khoitaodanhsach (DANHSACH& L )
{
	L.dau=NULL ;
	L.cuoi=NULL ;
}
LOP* Nhap1()
{
	LOP *Q;Q=(LOP *) malloc (sizeof (LOP));
	printf("Ten:");fflush(stdin); 
	gets(Q->ten);
	printf("Ma:");fflush(stdin);
	gets(Q->ma);
	printf("Khoa:");fflush(stdin);
	gets(Q->khoa);
	printf("Truong:");fflush(stdin);
	gets(Q->truong);
	printf("So sinh vien:"); fflush(stdin);
	scanf("%d",&Q->sosv);
	return Q;
}
 NODE *khoitao(LOP * A)
{
	NODE *P; P=(NODE *) malloc (sizeof (NODE));
	P->lophoc=A;
	P->next=NULL;
	return P;
} 
void Themvaodau(DANHSACH&L, NODE*P)
{
	if(L.dau==NULL)
	{
		L.dau=L.cuoi=P;
	}
	else 
	{
		P->next=L.dau;
		L.dau=P;
	}
} 
void themcuoi(DANHSACH&L, NODE*P)
{
	if(L.dau==NULL)
	{
		L.dau=L.cuoi=P;
	}
	else 
	{
		L.cuoi->next=P;
		L.cuoi=P;
	}
}
void Nhap(DANHSACH & L)
{
	int i, n; i=0;
	NODE *lopp;
	printf("Nhap so lop:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	
		printf("%d:", i+1); 
		lopp=khoitao(Nhap1());
		themcuoi(L,lopp);
	} 
}
void Xuat(DANHSACH &L)
{	NODE*P;int i;i=0; 
	P=L.dau;
	while(P!=NULL)
	{
	printf("%d.Ten lop:%s\t Ma lop:%s\t Khoa:%s\tTruong:%s\tSo^ sv:%.d\n",i+1,P->lophoc->ten,P->lophoc->ma,P->lophoc->khoa,P->lophoc->truong,P->lophoc->sosv);fflush(stdin);	
	P=P->next;i++; 
	}	
} 
void lopduoi30(DANHSACH & L)
{
	NODE*P;int i;i=0;
	printf("Danh sa´ch lop co duoi 30 sinh vien :\n"); 
	P=L.dau;
	while(P!=NULL)
	{
		if(P->lophoc->sosv<=30)
		{	
		printf("%d.Ten lop:%s\t Ma lop:%s\t Khoa:%s\tTruong:%s\tSo^ sv:%.d\n",i+1,P->lophoc->ten,P->lophoc->ma,P->lophoc->khoa,P->lophoc->truong,P->lophoc->sosv);fflush(stdin);			i++;	
		i++;	
		}
		P=P->next;
	}	if(i==0) printf("Khong co!!");
}
void lopcoten(DANHSACH &L)
{
	NODE*P;int i;i=0;
	P=L.dau;
	printf("Lop co ten DTTT K16 la`:"); 
	while(P!=NULL)
	{
		if(strcmp(P->lophoc->ten,"DTTT K16")==0 && P->lophoc->sosv<=30)
		{	
		printf("%d.Ten lop:%s\t Ma lop:%s\t Khoa:%s\tTruong:%s\tSo^ sv:%.d\n",i+1,P->lophoc->ten,P->lophoc->ma,P->lophoc->khoa,P->lophoc->truong,P->lophoc->sosv);fflush(stdin);			i++;	
		}
		P=P->next;
	}	if(i==0) printf("Khong co!!");
}
int main ()
{
	printf("-NHAP DANH SACH-\n");
	DANHSACH L;
	khoitaodanhsach(L);
	Nhap(L);
	printf("-DANH SACH -\n");
 	Xuat(L);
	lopcoten(L);
	lopduoi30(L);
	
	return 0;
}
