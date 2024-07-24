/*
power by le minh huu 7/9/2022
tao struct sinh vien:
	ma sinh vien
	ho ten
	lop
	diem trung binh
- tao ham nhap hien thi cua n sinh vien
hien thi sinh vien co diem tb <=8.5
lop ktmmt-ys co bao nhieu ban ten han
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*init struc sv*/
struct sinhvien{
	char msv[60];
	char ten[50];
	char lop[30];
	float dtb;
};

/*nhap n sinh vien*/
void nhap(sinhvien sv[], int n)
{
	printf("\n------------------nhap thong tin ----------------\n");
	int i;
	for(i = 0; i < n; i++)
	{
		printf("\nnhap sinh vien thu: %d\n",  i+1);
		printf("ma sinh vien: ");
		fflush(stdin);
		gets(sv[i].msv);
		printf("ten sinh vien: ");
		gets(sv[i].ten);
		printf("lop: ");
		gets(sv[i].lop);
		fflush(stdin);
		printf("diem tb: ");
		scanf("%f", &sv[i].dtb);
	}

}

/*xuat n sinh vien*/
void xuat(sinhvien sv[], int n)
{
	printf("\n--------------------in thong tin-----------------\n");
	int i;
	for(i = 0; i < n; i++)
	{
		printf("\n==========sinh vien: %d============\n", i+1);
		printf("msv: %s\t\tten sv: %s\n",sv[i].msv,sv[i].ten);
		printf("lop: %s\t\tdiem tb: %.2f\n",sv[i].lop,sv[i].dtb);
	}

}

/*in ten sinh vien co diem tb >8.5*/
void diemtb(sinhvien sv[], int n)
{
	printf("sinh vien co diem trung binh >= 8.5 la: ");
	int i;
	for(i = 0; i < n; i++)
	{
		if(sv[i].dtb >= 8.5)
		{
			printf("%s\t", sv[i].ten);
		}
	}
}

/*dem so sinh vien co ten han*/
void timkiem(sinhvien sv[], int n)
{
	int i, demsv = 0;
	for(i = 0; i < n; i++)
	{
		if(strcmp(sv[i].ten, "han") == 0 && strcmp(sv[i].lop, "ktmt") == 0)
		{
			demsv++;
		}
	}
	printf("\nso sinh vien ten han la: %d\n",demsv);
}

int main()
{
	int n;
	printf("nhap so sinh vien: ");
	scanf("%d", &n);
	sinhvien sv[n];

	/*nhap xuat sv*/
	nhap(sv, n);
	xuat(sv, n);

	/*in ten sv co diem tb >= 8.5*/
	diemtb(sv, n);

	/*in so sinh vien co ten han va lop ktmt ys*/
	timkiem(sv, n);
	return 0;
}


/*
CODE BY BUI THI TRANG 6/9/2022
#include<stdio.h>
#include<string.h>
struct Congnhan{
	int id;
	char name[40];
};
void nhap(Congnhan &cn){
	printf("nhap id cong nhan: ");
	scanf("%d", &cn.id);
	printf("nhap ten cong nhan: ");
	fflush(stdin);
	gets(cn.name);
}
void xuat(Congnhan cn){
	printf("id: %d", cn.id);
	printf("\nten: %s", cn.name);
}
int main(){
	int n;
	
	printf("Nhap so cong nhan: ");
	scanf("%d", &n);
	Congnhan cn[n]; // tao ra mang cn
	printf("Nhap thong tin cac cong nhan: \n");
	for(int i = 0 ; i < n ; i ++) {
		printf("\nNhap cong nhan thu %d \n", i);
		nhap(cn[i]);
	}
	printf("thong tin cac cong nhan la: \n");
	for(int i = 0 ; i < n ; i ++) {
		printf("\nThong tin cong nhan thu %d \n", i);
		xuat(cn[i]);
	}
return 0;
}

*/