#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50
struct sinhvien{
	char masv[N];
	char tensv[N];
	char diachi[N];
	char monhoc[N];
	int  diem;

};
// void xuat1(list ,node , int );
struct node{
	sinhvien data;
	node *pnext;
	
};
struct list{
	node *phead;
	node *ptail;
};
void khoitao(list &l){
	l.phead=NULL;
	l.ptail=NULL;
	
}
node *makenode(sinhvien data){
	node *p=(node*)malloc(sizeof(node));
	p->data=data;
	p->pnext=NULL;
	return p;
	
}
void themdau(list &l,node *p){
	if(l.ptail==NULL)
	l.phead=l.ptail=p;
	else{
		p->pnext=l.phead;
		l.phead=p;
		
	}
}
void themcuoi(list &l,node *p){
	if(l.phead==NULL)
	l.phead=l.ptail=p;
	else{
		l.ptail->pnext=p;
		l.ptail=p;
	}
}
void XoaDau(list &l){
    //tao node p
    node *p = new node;
    //gan p bang node pHead dau tien cua danh sach 
    p = l.phead;
    //thay doi lai pHead cua danh sach
    l.phead = l.phead->pnext;
    //gan node p ban dau tro den NULL
    p->pnext = NULL;
    //xoa node p
    delete p;
}
void XoaCuoi(list &l)
{
    //duyet cac phan tu co trong danh sach
    for(node *k = l.phead; k != NULL; k = k ->pnext)
    {
        //neu duyet den phan tu pTail cuoi trong danh sach
        if(k->pnext == l.ptail)
        {
            //xoa phan tu cuoi
            delete l.ptail;
            //tro phan tu truoc phan tu cuoi ve NULL
            k->pnext = NULL;
            //thay doi lai phan tu cuoi pTail cua danh sach
            l.ptail = k;
        }
    }
}
int Len(list l) {
	int dem=0;
	while(l.phead!=NULL) {
		dem++;
		l.phead=l.phead->pnext;
	}
	return dem;
}
int xoak(list &l,int k) {

	node* p=l.phead;
	if(k<1 || k> Len(l)+1) {
		printf("vi tri xoa khong hop le\n");
		return 0;
	} else {
		// if(k==1) {
    		// l.phead = l.phead->pnext;
			// return 1;
		// }//else if(k == Len(l)){
			//XoaCuoi(l);
			// return 1;
		//} 
		// else {
			int i=1;
			while(p!=NULL) {
				i++;
				if(i==k) {
					p->pnext=p->pnext->pnext;
					// return 1;
					printf("vi tri k: %d", i);
				}
				// p=p->pnext;
			}
		// }
	}
}
/* duyet ds tu dau den cuoi, ktra neu dtb sv < 5 goi ham xoa k*/
void xoatb5 (list &l){
	node *p = l.phead;
	int k = 0;
	while(p != NULL){
		k++;	
		printf("dem k: %d\n", k);	
		printf("dtb: %d\n", p->data.diem);
		if(p->data.diem < 5){			
			printf("d 5: %d\n", p->data.diem);
			// xoak(l, k);			
			p->pnext=p->pnext->pnext;			
		}
		p = p->pnext;
	}
}

void input(list &l){
	sinhvien sv;
	int i=0;
	int n;
	 printf("nhap so sinh vien: ");
    scanf("%d",&n);
	printf("nhap thong tin sinh vien: \n");  
    for(i=0;i<n;i++){
	
	printf(" sinh vien thu  %d: \n",i);
    fflush(stdin);
    printf("nhap ma sinh vien: ");
    gets(sv.masv);
    fflush(stdin);
	printf("nhaptensv: ");
	gets(sv.tensv);
	
	printf("nhap dia chi sv: ");
	gets(sv.diachi);
	printf("nhap mon hoc: ");
	gets(sv.monhoc);
	printf("nhap diem: ");
scanf("%d",&sv.diem);

	
            node *p = makenode(sv);
            themcuoi(l,p);
}

}
void xuat1(list l,node *k, int i){
	printf("sinh vien thu: %d\n",i);
	printf("masv: %s\t\tten sv: %s\t\tdiachi: %s\t\tmonhoc: %s\t\tdiem: %d\n",k->data.masv,k->data.tensv,k->data.diachi,k->data.monhoc,k->data.diem);

} 
void xuat(list l){
	int i=0;
	printf("in phan tu vua  nhap: \n");
	for(node *k =l.phead;k!=NULL;k=k->pnext){
		i++;
		xuat1(l,k,i);
	}
}
void timsv(list l){
	int i=0,demsv=0;
	printf("thong tin sv hoc mon java: \n");
	for(node *k=l.phead;k!=NULL;k=k->pnext){
		i++;
		if(strcmp(k->data.monhoc,"java")==0 && k->data.diem>8 ){
		
		
			xuat1(l,k,i);
			demsv++;
			
		}
	}
}

int main(){
	int n;			
	list l;
	int a;
	khoitao(l);
	input(l);
    xuat(l);
    // timsv(l);
  // xoasvnhohon5(l);
  printf("ds sv sau khi xoa sv tb < 5\n");
   xoatb5(l);
   printf("he slo\n");
    xuat(l);
	return 0;
}
