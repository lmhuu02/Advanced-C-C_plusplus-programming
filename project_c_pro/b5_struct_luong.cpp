/*
power by le minh huu 7/9/2022
struct quan ly nhan vien
    ma nhan vien
    ho ten
    chuc vu(cong nhan, quan ly). he so chuc vu: cong nhan = 1.5, quan ly = 3
    thuong theo thang
-nhap hien thi n cong nhan
-tinh luong: 5000*he so chuc vu + thuong
-in ra cong nhan co luong cao/ thap nhat
-tinh tb luong cua all cong nhan
-in thong tin nhan vien co ten an
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define hs_cn   1.5
#define hs_ql   3

// #define chucvu(number)   if(number == 0) "nhanvien" if(number == 1) "quan ly"


/*init struct nhan vien*/
struct nhanvien{
    char mnv[50];
    char hoten[50];
    int thuong;
    char chucvu[50];
    int luong;
};

/*nhap thong tin n nhan vien*/
void nhap(nhanvien nv[], int n)
{
    printf("\n-------------nhap thon tin-----------------\n");
    printf("note: chuc vu: = 0 -> cong nhan. = 1 -> quan ly\n");
    int i;
    for(i = 0; i < n; i++)
    {
        printf("\nnhan vien: %d\n", i+1);
        printf("ma nhan vien: ");
        fflush(stdin);
        gets(nv[i].mnv);
        printf("ho ten: ");
        gets(nv[i].hoten);
        printf("chuc vu: ");
        gets(nv[i].chucvu);
        printf("thuong: ");
        fflush(stdin);
        scanf("%d", &nv[i].thuong);
    }
}
/*xuat thong tin n nhan vien*/
void xuat(nhanvien nv[], int n)
{
    printf("\n-------------in thon tin-----------------\n");
    int i = 0;
    for(i = 0; i < n; i++)
    {
        printf("\n========nhan vien %d=========\n", i+1);
        printf("ma nv: %s\t\tho ten: %s\n",nv[i].mnv, nv[i].hoten);
        printf("chuc vu: %s\t\tthuong: %d",nv[i].chucvu, nv[i].thuong);
        printf("\nluong nhan vien: %d\n", nv[i].luong);
    }
    
}
/*tinh luong nhan vien*/
void luong(nhanvien nv[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(strcmp(nv[i].chucvu,"quan ly") == 0)
        {
            nv[i].luong = 5000*hs_ql + nv[i].thuong;
        }else if(strcmp(nv[i].chucvu, "cong nhan") == 0)
        {
            nv[i].luong = 5000*hs_cn + nv[i].thuong;
        }
    }

}
/*tinh luong trung binh cong all cong nhan*/
void tbluong(nhanvien nv[], int n)
{
    int i, luongnv = 0;
    float luongtb = 0;
    for(i = 0; i < n; i++)
    {
        luongnv = luongnv + (nv[i].luong);
        // printf("luong: %d\n",nv[i].luong);
    }
    luongtb = (float)luongnv / (float)n;
    // printf("tong luong:  %d\n", luongnv);
    printf("\nluong tb cua tat ca nhan vien trong cty la: %.2f\n", luongtb);
}
/*in thong tin nhan vien co luong min/max*/
void minmax(nhanvien nv[], int n)
{
    int i, j, min = 0, max = 0;
    int checkmin = 0, checkmax = 0;
    /*gan luong min/max cho nhan vien dau tien de kiem tra*/
    min = nv[0].luong;
    max = nv[0].luong;
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            /*check luong nv min*/
            if(nv[j].luong < min)
            {
                min = nv[j].luong;
                checkmin = j;
            }

            /*check luong nv min*/
            if(nv[j].luong > max)
            {
                max = nv[j].luong;
                checkmax = j;
            }

        }
    }
    printf("\nluong min and max cua nhan vien la: \n");
    printf("luong vn: %s     min: %d\n",nv[checkmin].hoten, min);
    printf("luong vn: %s     max: %d\n",nv[checkmax].hoten, max);
}
/*in thong tin nhan vien co ten han - ERROR NOT RUN, YOU NEED FIX BUG AGAIN*/
void timkiem(nhanvien nv[], int n)
{
    /*
    giai thuat:
        - tao mot mang char tam thoi luu ten nhan vien truyen vao.
        - tao mot mang char luu 3 ky tu cuoi cua ten nhan vien vua truyen vao su dung ham copychuoi
        - su dung ham so sanh chuoi 3 ky tu cuoi voi ten cho truoc + dk truoc 3 ky tu do phai la khoang chong.
        - kiem tra neu dung thi in ra thong tin 
    */
    int i, m, number = 0;
    for(i = 0; i < n; i++)
    {
        /*khoi tao chuoi ten can tim kiem*/
        char exp[] = "han";
        m = strlen(nv[i].hoten);
        char copyname[m]; 
        // printf("=====================\n");
        /*tinh do dai ten nhan vien*/
        
        strcpy(copyname,nv[i].hoten);
        // printf("%s\n", copyname);
        // printf("aaa: %s\n", nv[i].hoten);
        
        /*copy 3 ky tu cuoi cua ten nhan vien vao chuoi tempchar*/
        char tempchar[40];
        strncmp(tempchar,copyname + (m - 3), m);     //n - 3 de lay tu 3 ky tu cuoi cung

        /*so sanh strcmp*/
        if(strcmp(copyname,exp) == 0 && copyname[n-4] == ' ')
        {
            printf("\n========nhan vien %d=========\n", i+1);
            printf("ma nv: %s\t\tho ten: %s\n",nv[i].mnv, nv[i].hoten);
            printf("chuc vu: %s\t\tthuong: %d",nv[i].chucvu, nv[i].thuong);
            printf("\nluong nhan vien: %d\n", nv[i].luong);
        }else{
            printf("khong co ai ten han ca!\n");
        }
    }
}

int main()
{
    int n;
    printf("nhap so nhan vien cua cong ty: ");
    scanf("%d", &n);
    nhanvien nv[n];

    /*nhap xuat nhan vien*/
    nhap(nv,n);
    luong(nv,n);
    xuat(nv,n);
    tbluong(nv, n);
    minmax(nv, n);
    timkiem(nv, n);
    return 0;
}




/*code by Phan Xuan Kien*/
void checkten(char fullname[],char subname[]){
	// lay do dai cua chuoi fullname
	int nf = strlen(fullname);
	// lay do dai chuoi subname
	int ns = strlen(subname);
	char ss[40] ;
	// cat di so ki tu muon kiem tra cua fullname
	strncpy(ss,fullname+nf-ns,nf);
	printf("%d",strcmp(subname,ss));
	//so sanh
	if(strcmp(subname,ss)==0&&fullname[nf-ns-1]==' ') printf("trung ten");
	else printf("ko trung");
}

bool checkten(char name[40]){
	
	char ten1[] = "han";
	
	int n = strlen(name);
	char ss[40] ;
	strncpy(ss,name+n-3,n);
	printf("%d",strcmp(ten1,ss));
	if(strcmp(name,ss)==0&&name[n-4]==' ') return true;
	else return false;
}
