/*
power by le minh huu 14/9/2022
de bai:
    quan ly diem sv ktmt - ktys
        msv
        ho ten
        so tc dang ky
        diem tb
    1. ham nhap xuat n sinh vien
    2. dem so sv co so tc duoi 14 va diem tb duoi 2.0
    3.ktra ds co bao nhieu ban sv co dang ma  sv ktmt: ktmt123, y sinh: ktys123
    4. sinh vien co diem cao nhat thap nhat thuoc lop nao

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*struct sinh vien*/
struct sinhvien
{
    char msv[50];
    char ten[50];
    int soTC;
    float diemtb;
};

/*nhap sv*/
void nhap(sinhvien sv[], int n)
{
    int i;
    printf("\n------------nhap thong tin------------\n");
    for(i = 0; i < n; i++)
    {
        printf("\nsinh vien thu: %d\n", i+1);
        fflush(stdin);  /*xoa bo nho dem*/
        printf("nhap ma sv: ");
        gets(sv[i].msv);
        printf("nhap ten: ");
        gets(sv[i].ten);
        fflush(stdin);  /*xoa bo nho dem*/
        printf("nhap so tin chi: ");
        scanf("%d", &sv[i].soTC);
        fflush(stdin);  /*xoa bo nho dem*/
        printf("nhap diem tb: ");
        scanf("%f", &sv[i].diemtb);
    }

}
/*xuat sv*/
void xuat(sinhvien sv[], int n)
{
    int i;
    printf("\n-------------in thong tin sinh vien-----------------\n");
    for(i = 0; i < n; i++)
    {
        printf("sinh vien thu: %d\n", i+1);
        printf("msv: %s\t\tten: %s\n", sv[i].msv, sv[i].ten);
        printf("so TC: %d\t\tdiem tb:%.2f\n", sv[i].soTC, sv[i].diemtb);
    }

}
/*dem sv co diem tb < 2.0, so tc < 14*/
void demsv(sinhvien sv[], int n)
{
    int i, dem = 0;
    for(i = 0; i < n; i++)
    {
        if(14 > sv[i].soTC && 2.0 > sv[i].diemtb)
        {
            dem++;
        }
    }
    printf("\n so sinh vien co dem tb < 2.0 va so tc < 14 la: %d\n", dem);
}
/*sv co diem cao nhat thuoc lop nao*/
void maxmindiem(sinhvien sv[], int n)
{
    int i, demmax = 0, demmin = 0;
    /*khoi tao gia tri max */
    float max = sv[0].diemtb;
    float min = sv[0].diemtb;
    for(i = 1; i < n; i++)
    {
        /*tim sv diem tb max*/
        if(max < sv[i].diemtb)
        {
            max = sv[i].diemtb;
            demmax = i;
        }
        /*tim sv diem tb max*/
        if(min > sv[i].diemtb)
        {
            min = sv[i].diemtb;
            demmin = i;
        }
    }
    printf("\n======thong tin sinh vien==========\n");

    /*tao mot chuoi tam chi gom 4 ky tu*/
    char tempchar[40];
    char tempchar1[40];
    /*copy 4 ky tu dau cua chuoi masv sang tempchar*/
    strncpy(tempchar,sv[demmax].msv,4);
    strncpy(tempchar1,sv[demmin].msv,4);
    // printf("\n\n%s\n\n", tempchar);
        printf("sinh vien co diem cao nhat\n");
        printf("ten: %s\t\tlop: %s\n", sv[demmax].ten,tempchar);   
        printf("sinh vien co diem thap nhat\n");
        printf("ten: %s\t\tlop: %s\n", sv[demmin].ten, tempchar1); 
    

    /*kiem tra neu la ktmt*/
    // if(strcmp((tempchar,"ktmt") == 0 || strcmp(tempchar,"KTMT") == 0) || )
    // {
    //     printf("sinh vien co diem cao nhat\n");
    //     printf("ten: %s\t\tlop: KTMT\n", sv[demmax].ten);   
    //     printf("sinh vien co diem thap nhat\n");
    //     printf("ten: %s\t\tlop: KTMT\n", sv[demmin].ten);    
    // }
    // else if(strcmp(tempchar,"ktys") == 0 || strcmp(tempchar,"KTYS") == 0)
    // {
    //        /*kiem tra neu la ktys*/
    //     printf("sinh vien co diem cao nhat\n");
    //     printf("ten: %s\t\tlop: KTYS\n", sv[demmax].ten);    
    //     printf("sinh vien co diem thap nhat\n");
    //     printf("ten: %s\t\tlop: KTYS\n", sv[demmin].ten); 
    // }
    // else{
    //     printf("sinh vien co diem cao nhat\n");
    //     printf("ten: %s\t\tlop: ngoai ktmt va ktys\n", sv[demmax].ten);    
    //     printf("sinh vien co diem thap nhat\n");
    //     printf("ten: %s\t\tlop: ngoai ktmt va ktys\n", sv[demmin].ten); 
    // }
    
}
/*tim kiem sinh vien*/
void timkiem(sinhvien sv[], int n)
{
    int i, dem = 0;
    for(i = 0; i < n; i++)
    {
        /*tao mot chuoi tam chi gom 4 ky tu*/
        char temp[14];
        // char tempchar[50];

        /*copy ma sv vao bien temp char*/
        // strcpy(tempchar,sv[i].msv);
        
        /*copy 4 ky tu dau cua chuoi masv sang tempchar*/
        // strcpy(tempchar,sv[dem].msv);

        strncpy(temp,sv[i].msv,4);
        //  printf("\n\n %s\n\n",temp);
         temp[4] = '\0';
        /*kiem tra neu la ktmt va ktys*/
        // if((strcmp(temp,"ktmt") == 0 || strcmp(temp,"KTMT") == 0) || (strcmp(temp,"ktys") == 0 || strcmp(temp,"KTYS") == 0))
        // {
        //     dem++;  
        // }

        if(strcmp(temp,"ktmt") == 0  || strcmp(temp,"ktys") == 0 )
        {
            dem++;  
        }

    }

    if(dem != 0)
    {
        printf("so sinh vien thuoc lop ktmt va ktys la: %d\n", dem);
    }else{
        printf("khong co sinh vien nao thuoc ktmt va ktys\n");
    }
}

/*function main*/
int main()
{
    int n;
    printf("nhap so sinh vien: ");
    scanf("%d", &n);
    sinhvien sv[n];

    /*nhap xuat*/
    nhap(sv,n);
    xuat(sv,n);
    demsv(sv,n);
    maxmindiem(sv,n);
    timkiem(sv,n);

    return 0;
}



