#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
typedef int item;

struct sv{
	char ten[50];
	char lop[50];
	float dtb;
};
struct List{
	sv sv[100];
	int size;
};
//ham khoi tao
void init(List &L){
	L.size=0;
}

//Ham nhap du lieu
void Input(List &L){
	printf("Nhap vao so sinh vien: ");
	scanf("%d",&L.size);
	int i;
	for(i=0;i<L.size;i++){
		printf("nhap thong tin sinh vien %d: \n ",(i+1));
		printf("ho ten: ");
		scanf("%s",&L.sv[i].ten);
		printf("lop: ");
		scanf("%s",&L.sv[i].lop);
		printf("Diem trung binh: \n");scanf("%f",&L.sv[i].dtb);
	}
}


//Ham hien thi
void Output(List L){
	printf("\n Danh sach cac sinh vien la: \n");
	int i;
	for(i=0;i<L.size;i++){
		printf("\n%d.ho ten: %s ",(i+1),&L.sv[i].ten);
		printf("\nlop: %s",&L.sv[i].lop);
		printf("\nDiem trung binh: %.2f",L.sv[i].dtb);
	}
}

//th�m vao ds
int Insert_k (List&L, int k)
{
	if(L.size==N)
	{
		printf("Danh sach day !");
		return 0;
	}
//	printf("\n Nhap vi tri chen!\n");
//	scanf("%d",&k);
	if(k<1 || k>L.size+1)
	{
		printf("Vi tri chen khong hop le !\n");
		return 0;
	}
	printf("\n Nhap gia tri can chen:\n ");
	int i;
	for (i = L.size+1; i > k; i--){
	L.sv[i] = L.sv[i-1];
//	L.size++;
	}
	printf("ho ten: ");scanf("%s",&L.sv[k-1].ten);
	
	printf("lop: ");scanf("%s",&L.sv[k-1].lop);
		
	printf("Diem trung binh: \n");scanf("%f",&L.sv[k-1].dtb);
//	return 1;
	L.size++;

}

//tim ten sv
void timsv_ten(List&L,int n)
{
	char ten[50];
	printf("\nNhap ten sv can tim kiem: ");
//	scanf("%s",&ten);
	fflush(stdin);
	gets(ten);
	int i;
	int timsv=0;
	for(int i=0;i<n;i++)
	{
		if(strcmp(ten,L.sv[i].ten) == 0)
		{ 
		printf("\nHien thi ttsv : ",L.sv[i]);
		printf("\nTen SV: %s",L.sv[i].ten);
		printf("\nlop: %s",L.sv[i].lop);
		printf("\nDiem trung binh: %.2f",L.sv[i].dtb);
		timsv++;
		}
	}
	if(timsv==0){
		printf("\nkhong co sv nao can tim");
	}
}

//dem so sv co diem trung binh lon hon 5
void demtb(List L ){
int dem=0;
for(int i=0;i<L.size;i++){	
if(L.sv[i].dtb>5){
	dem++;
}
}
printf("\ndem so sv co dtb lon hon 5: %d",dem);
}

/*xoa sv co diem tb < 5*/
void xoasv(List &L){
	printf("\nds sv co diem > 5 la: \n");
	for(int i = 0; i < L.size;i++){
		if(L.sv[i].dtb < 5){
			for(int j = i; j < L.size - 1; j++){
				L.sv[j] =L.sv[j+1];
			}
			L.size--;
		}
	}
}

int main(){
	int x;
	int k;
	int n;
	List danhsach;
	init(danhsach);
	Input(danhsach);
	Output(danhsach);
//	demtb(danhsach);
//	printf("\nvitri chen: ");
//	scanf("%d",&k);
////	if(Insert_k(danhsach,k));
//	Insert_k(danhsach,k);
//	Output(danhsach);
////	char ten[50];
//	timsv_ten(danhsach,n);
	xoasv(danhsach);
	Output(danhsach);
	return 0;
}
