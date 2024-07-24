#include <stdio.h>
#include <stdlib.h>
//b1: tao cau truc cua 1 node
struct NODE{
	int Data;
	NODE *Next;
};
//b2: tao cau truc cua danh sach, gom 2 node head,tail
struct LIST{
	NODE *phead;
	NODE *ptail;
};
//b3: khoi tao ds rong~
void khoitaoList(LIST &l){
	l.phead = NULL;
	l.ptail = NULL;
}
//b4: tao ra 1 node doc lap co data = x
NODE *makeNode(int x){
	NODE *P;
	P=(NODE *) malloc(sizeof(NODE));
	P->Data=x;
	P->Next=NULL;
	return P;
}
// them node doc lap vao dau dslk
void ThemDau(LIST &l, NODE *p){
	if(l.phead==NULL) l.phead = l.ptail =p;
	else {
		p->Next = l.phead;
		l.phead = p;
	}
	// source them vao cuoi
//	if(l.phead==NULL) l.phead = l.ptail =p;
//	else {
//		l.ptail->Next = p;
//		l.ptail =p;
//	}
}
// hien thi toan bo ds
void hienthi(LIST l){
	for(NODE *k = l.phead; k!=NULL; k =k->Next){
		printf("%2d",k->Data);
	}
}

int dodai(LIST l){
	int dem=0;
	for(NODE *k = l.phead; k!=NULL; k =k->Next){
		dem++;
	}
	return dem;
}
// 1 so bai toan tim kiem
int datanhohon0(LIST l){
	int dem1=0;
		for(NODE *k = l.phead; k!=NULL; k =k->Next){
		if(k->Data<0)dem1++;
		}return dem1;
}
int databang6(LIST l){
	int dem2=0;
		for(NODE *k = l.phead; k!=NULL; k =k->Next){
		if(k->Data==6)dem2++;
		}return dem2;
}
int main(){
	// nhap so luong node
	int n;
	printf("nhap so luong pan tu: \n");
	scanf("%d",&n);
	// khai bao ds
	LIST l;
	// goi ham khoi tao ds
	khoitaoList(l);
	// su dung vong for de nhap gia tri cho tung node
	for(int i=0;i<n;i++){
		int gt;
		
		printf("Nhap gia tri: \n");
		scanf("%d",&gt);
		// khoi tao node p co gia tri = gt
		NODE *p = makeNode(gt);
		// them node p vao dau ds
		ThemDau(l,p);
	}
	// hien thi ds
	hienthi(l);
	printf("\n Co %d node co data nho hon 0",datanhohon0(l));
	printf("\n Co %d node co data = 6",databang6(l));
}
