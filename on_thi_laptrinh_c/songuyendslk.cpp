#include<stdio.h>
#include<stdlib.h>
// quan ly danh sach so nguyen 
struct node{
	int data;
	node *next;
	
};
struct list{
	node *phead;
	node *ptail;
	
};
//khoi tao list
void khoitaolist(list &l){
	l.phead=NULL;
	l.ptail=NULL;
	}
	node *makenode(int x){
		node *p;
		p=(node *) malloc(sizeof(node));
		p->data=x;
		p->next=NULL;
		return p;
		}
void themdau(list &l,node *p){
	if(l.phead==NULL) l.phead=l.ptail=p;
	else{
	p->next =l.phead;
	l.phead=p;
	}
	}
int Len(list l) {
	int dem=0;
	while(l.phead!=NULL) {
		dem++;
		l.phead=l.phead->next;
	}
	return dem;
}

	void XoaDau(list &l){
    //tao node p
    node *p = new node;
    //gan p bang node pHead dau tien cua danh sach 
    p = l.phead;
    //thay doi lai pHead cua danh sach
    l.phead = l.phead->next;
    //gan node p ban dau tro den NULL
    p->next = NULL;
    //xoa node p
    delete p;
}
void XoaCuoi(list &l)
{
    //duyet cac phan tu co trong danh sach
    for(node *k = l.phead; k != NULL; k = k ->next)
    {
        //neu duyet den phan tu pTail cuoi trong danh sach
        if(k->next == l.ptail)
        {
            //xoa phan tu cuoi
            delete l.ptail;
            //tro phan tu truoc phan tu cuoi ve NULL
            k->next = NULL;
            //thay doi lai phan tu cuoi pTail cua danh sach
            l.ptail = k;
        }
    }
}
int xoak(list &l,int k) {

	node* p=l.phead;
	if(k<1 || k> Len(l)+1) {
		printf("vi tri xoa khong hop le\n");
		return 0;
	} else {
		if(k==1) {
			XoaDau(l);
			return 1;
		} else {
			int i=1;
			while(p!=NULL) {
				i++;
				if(i==k) {
					p->next=p->next->next;
					return 1;
				}
				p=p->next;
			}
		}
	}
}
void hienthi(list l){
		printf("danh sach so nguyen: \n");
	for(node *k=l.phead; k!=NULL; k=k->next){
	
		printf("%2d \n",k->data);
		}
		}
		//xay dung ham hien thi do dai dslk
	void dodai(list l){
		int dem=0;
	for(node *k=l.phead; k!=NULL; k=k->next){
		dem++;
		}
	printf("\ndo dai danh sach l=%d\n",dem);
		}
		//có bao nhieu node data<0
	void datanhohon0(list l){
			int dem1=0;
	for(node *k=l.phead; k!=NULL; k=k->next){
		if(k->data<0)
		
	dem1++;
		}
		printf("co %d node co data nho hon 0\n",dem1);
		}
		void databang6(list l){
			int dem2=0;
	for(node *k=l.phead; k!=NULL; k=k->next){
		if(k->data==6)
		
	dem2++;
		}
		printf("co %d node co data bang6\n",dem2);
		}
int searchvitri(list l,int a) {//tra ve vi tri cua node a
	node *p=l.phead;
	int i=0;
	while(p!=NULL) {
		i++;
		if(p->data==a) {
			return i;
		}
		p=p->next;
	}
	return 0;
}
	//them node sau node cos gia tri b
	void addat(list &l){

	int data,b;
	printf("nhap gia tri: \n");
	scanf("%d",&b);
	for(node *k=l.phead;k!=NULL;k=k->next){
	
		if(k->data==b){
			node *g=makenode(b);
			g->next=k->next;
			k->next=g;
			k=k->next;
		}
	}
	hienthi(l);
}





		//có bao nhieu node dât=6
int main(){
			int n,k,a,b;	
			printf("nhap so luong phan tu: ");
			scanf("%d",&n);
			list l;
			khoitaolist(l);
			//khoi tao node;
			for(int i=1;i<5;i++){
				int a;
				scanf("%d",&a);
				node* p=makenode(a);
			
				themdau(l,p);
				}
				
				dodai(l);
		//	datanhohon0(l);
		//	databang6(l);
			addat(l);
				printf("\nnhap gia tri muon xoa: ");
	scanf("%d",&a);

	k=searchvitri(l,a);
		
			xoak(l,k);
			hienthi(l);
							}
