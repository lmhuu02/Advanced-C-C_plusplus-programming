/*
power by le minh huu 20/9/2022
sach co thuoc tinh: ma sach, ten, so luong, the loai, gia tien, tac gia
thuc hien:
    1. struct quan ly n cuon sach
    2. ham nhap xuat thong tin
    3. loai sach nao co nhieu nhat la bao nhieu cuon
    4. in thong tin sach: "lap trinh c nang cao" tac gia: "pham van at"
    5. sap xep ds dua tren ten sach
    6. dem so loai sach duoc nhap tu ban phim
    7. xoa thong tin sach co ma nhap tu ban phim

*/
#include <stdio.h>
#include <stdio.h>
#include <string.h>

struct sach{
    char masach[50];
    char tensach[50];
    char theloai[50];
    char tacgia[50];
    int soluong;
    int giatien;
};

/*nhap thong tin sach*/
void nhap(sach cuonsach[], int n)
{
    printf("\n--------nhap thong tin sach----------\n");
    int i;
    for(i = 0; i < n; i++)
    {
        printf("\ncuon sach thu: %d\n",i+1);
        printf("nhap ma: ");
        fflush(stdin);
        gets(cuonsach[i].masach);
        printf("nhap ten: ");
        gets(cuonsach[i].tensach);
        printf("nhap the loai: ");
        gets(cuonsach[i].theloai);
        printf("nhap tac gia: ");
        gets(cuonsach[i].tacgia);
        fflush(stdin);
        printf("nhap so luong: ");
        scanf("%d", &cuonsach[i].soluong);
        printf("nhap gia tien: ");
        scanf("%d", &cuonsach[i].giatien);

    }

}
/*in thong tin sach*/
void xuat(sach cuonsach[], int n)
{
    printf("\n--------in thong tin sach----------\n");
    int i;
    for(i = 0; i < n; i++)
    {
        printf("\ncuon sach thu: %d\n",i+1);
        printf("ma sach: %s\t\tten sach: %s\n", cuonsach[i].masach, cuonsach[i].tensach);
        printf("the loai: %s\t\ttac gia: %s\n", cuonsach[i].theloai,cuonsach[i].tacgia);
        printf("so luong: %d\t\tgia tien: %d\n", cuonsach[i].soluong, cuonsach[i].giatien);

    }

}
/*in thong tin 1 cuon sach*/
void xuat1(sach cuonsach[], int i)
{
        printf("\ncuon sach thu: %d\n",i+1);
        printf("ma sach: %s\t\tten sach: %s\n", cuonsach[i].masach, cuonsach[i].tensach);
        printf("the loai: %s\t\ttac gia: %s\n", cuonsach[i].theloai,cuonsach[i].tacgia);
        printf("so luong: %d\t\tgia tien: %d\n", cuonsach[i].soluong, cuonsach[i].giatien);
}


/*  ERROR, YOU NEED FIX BUG AGAIN*/
/*tim loai sach co so luong nhieu nhat*/
void demSachmax(sach cuonsach[], int n)
{
    int max = cuonsach[0].soluong;
    int i, count = 0;
    for(i = 1; i < n; i++)
    {
        if(max < cuonsach[i].soluong)
        {
            max = cuonsach[i].soluong;
            count++;
        }

    }
    printf("\n--------in thong tin sach so luong lon nhat----------\n");
    xuat1(cuonsach, count);
}

/*  ERROR, YOU NEED FIX BUG AGAIN*/
/*tim loai sach co so luong nhieu nhat*/
void demSachmaxfix(sach cuonsach[], int n)
{
    int i, j, x = 0;
    int tongsach[n];
    int id[n][n];

    for(i = 0; i < n - 1; i++)
    {
        tongsach[i] = cuonsach[i].soluong;

        for(j = i+1; j < n; j++)
        {
            /*so sanh cuoi sach thu i xem co giong the loai sau khong. neu giong thi lam*/
            if(strcmp(cuonsach[i].theloai, cuonsach[j].theloai) == 0)
            {
                /*tinh tong so luong cuon sach thuoc cung loai sach voi loai sach dau tien*/
                tongsach[i] = tongsach[i] + cuonsach[j].soluong;
                /*luu vi tri cac cuon sach trung the loai*/
                id[i][x] = j;
                x++;
            }
        }

        x = 0;
        if(i == id[i][x])
        {

        }
     
    }
}




/*in thong tin sach lap trinh nang cao*/
void sachnangcao(sach cuonsach[], int n)
{
    /*luu y: can phai cho ky tu cuoi cung cua chuoi copy = \0 vd temp[20]= '\0' */
    char sachtemp[] = "Lap trinh c nang cao";    /*20 kytu*/
    char tacgiatemp[] = "Pham Van At";      /*11 kytu*/
    char chuoitemp1[50];
    char chuoitemp2[50];
    int i, vitri = 0;
    for(i = 0; i < n; i++)
    {
        /*coppy chuoi ky tu co so luong ...*/
        strncpy(chuoitemp1,cuonsach[i].tensach,20);
        strncpy(chuoitemp2,cuonsach[i].tacgia,11);
        
        /*gan ky tu cuoi cung cua chuoi == NULL */
        chuoitemp1[20] = '\0';
        chuoitemp2[11] = '\0';

        /*so sanh chuoi copy voi chuoi can so sanh: strcmp*/
        if(strcmp(chuoitemp1,sachtemp) == 0 && strcmp(chuoitemp2,tacgiatemp) == 0)
        {
            vitri++;
            printf("\nthong tin sach: lap trinh c nang cao tac gia: Pham Van At: \n");
            xuat1(cuonsach,(i));
        }
    }
    if(vitri == 0)
    {
        printf("khong co cuon sach: Lap trinh c nang cao tac gia: Pham Van At\n");
    }
}

/*sap xep danh sach theo ten sach*/
void sapxep(sach cuonsach[], int n)
{
    /*lenh strcmp(a[],b[])   = 0 -> bang nhau, a > b -> = 1*/
    int i,j;
    // char temp[50];    /*khong the dung bien temp nay ma chan bien cua struc mooi chua duoc het du lieu*/
    for(i = 0; i < n - 1; i++)
    {
        for(j = i+1; j < n; j++)
        {
            /*neu ten sach truoc > ten sach sau*/
            if(strcmp(cuonsach[i].tensach,cuonsach[j].tensach) >= 0)
            {
                /*bien temp phai thuoc kieu sach moi co the chua het du lieu*/
                sach temp = cuonsach[i]; 
                cuonsach[i] =cuonsach[j]; 
                cuonsach[j] = temp;
            }
        }

    }

}
/*nhap the loai sach dem so luong */
void demsach(sach cuonsach[], int n)
{
    char theloai[50];
    int i, dem = 0;
    printf("\n nhap the loai sach tin kiem: ");
    fflush(stdin);
    gets(theloai);

    for(i = 0; i < n; i++)
    {
        // /*do do dai chuoi cua the loai sach*/
        // strlen(cuonsach[i].theloai);
        
        if(strcmp(theloai, cuonsach[i].theloai) == 0)
        {
            dem = dem + cuonsach[i].soluong;
        }

    }
    printf("the loai: %s co %d cuon sach\n", theloai, dem);
}

/*nhap ma sach xoa thong tin sach  cua ma do*/
void xoasach(sach cuonsach[], int *n)
{
    char masach[50];
    int i, dem = 0;
    printf("\n nhap ma sach can xoa: ");
    fflush(stdin);
    gets(masach);
    for(i = 0; i < *n; i++)
    {

        if(strcmp(masach, cuonsach[i].masach) == 0)
        { 
                /*neu vi tri xoa la o dau hoac giua*/
                cuonsach[i] = cuonsach[i+1]; 
                    *n = *n - 1;
                /*neu o cuoi danh sach*/
                if(i == (*n-1))
                {
                    *n = *n - 1;
                }
        }

    }
        printf("\n danh sach sau khi da xoa ma so: %s\n", masach);
}

/*function main*/
int main()
{
    int n;
    printf("nhap so luong sach: ");
    scanf("%d", &n);
    sach cuonsach[n];

    /*nhap xuat thong tin*/
    nhap(cuonsach, n);
    xuat(cuonsach, n);

    demSachmax(cuonsach, n);

    sachnangcao(cuonsach, n);
    demsach(cuonsach, n);

  /*in ra danh sach da sap xep*/
    sapxep(cuonsach, n);
    printf("\n-------in thong tin sach da sap xep-------------\n");
    xuat(cuonsach,n);
    /*xoa thong tin sach co ma nhap vao tu ban phim*/
    xoasach(cuonsach, &n);
    xuat(cuonsach,n);

    return 0;
}