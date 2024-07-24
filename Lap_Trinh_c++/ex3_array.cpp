/*-----------------------START--------------------------*/
/*
Power by: Minh Huu @copyright - time: 4/1/2024
langauge: C++ - IDE: VSCode   -     array
*/
#include <iostream>
#include <iomanip>

using namespace std;
#define MAX 100

void nhap(int[], int);
void xuat(int[], int);
void timkiem(int[], int, int);
void them_giatri(int[], int&);
void xoa_vitri(int[], int&);
int tk_vitri(int[], int, int );
void xoa_giatri(int[], int&);
void sua_giatri(int[], int);
void sapxep_giam(int[], int);
void dem_gt_khac(int[], int);
void giatri_xh_nhieu_nhat(int[], int);

/*-----------------------MAIN--------------------------*/
int main()
{
    int n;
    int arr[MAX];
    cout <<"\nnhap phan tu toi da cua mang: ";
    cin >>n;
    nhap(arr, n);
    xuat(arr, n);

    // int x;
    // cout <<"\nnhap phan tu can tim: ";
    // cin >>x;
    // timkiem(arr,n,x);
    // them_giatri(arr,n);
    // xuat(arr, n);
    // xoa_vitri(arr, n);
    // xuat(arr, n);
    // sua_giatri(arr,n);
    // xuat(arr, n);
    // xoa_giatri(arr,n);
    // xuat(arr,n);

    sapxep_giam(arr,n);
    xuat(arr,n);
    return 0;
}

/*-----------------------FUNCTION---------------------*/
void nhap(int arr[MAX], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout <<"nhap phan tu "<<i+1<<": ";
        cin>>arr[i];
    }
    
}
void xuat(int arr[MAX], int n){
    cout <<"\nxuat mang: ";
    for(int i = 0; i < n; i++)
    {
        cout <<setw(4)<<arr[i];
    }
}
void timkiem(int arr[MAX], int n, int x)
{
    int dem_pt = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == x){
            dem_pt++;
            cout <<"\ngia tri "<<x<<" o vi tri "<<(i+1);
        }
    }
    if(dem_pt == 0)
    {
        cout <<"\nkhong tim thay phan tu co gia tri: "<<x;
    }
}
void them_giatri(int arr[MAX], int &n)
{
    int x,k;
    if(n < MAX){
        cout <<"\nnhap vi tri can them: ";
        cin >>k;
        if(k >= 0 && k <= n)
        {
            cout <<"\nnhap gia tri can them: ";
            cin >>x;
            /*roi tu vi tri k den het sang phai 1 dv*/
            for(int i = n+1; i >= (k); i--)
            {
                arr[i] = arr[i-1];
            }
            arr[k] = x;
            n = n + 1;
        }else{
            cout <<"\nvi tri them khong hop le! ";
        }
    }else if(n >= MAX)
    {
        cout <<"\nmang da day. full data";
    }
    
}
void xoa_vitri(int arr[MAX], int &n)
{
    int k;
    /*xoa vi tri k trong mang*/
    if(n != 0)
    {
        cout <<"\nnhap vi tri can xoa: ";
        cin >>k;
        if(k <= n && k > 0)
        {
            for(int i = k-1; i < n; i++)
            {
                arr[i] = arr[i+1];
            }
            n = n - 1;
        }else{
            cout <<"\n vi tri xoa khong hop le!";
        }
    }else{
        cout <<"\nkhong co phan tu nao trong mang de xoa! ";
    }
}
void sua_giatri(int arr[MAX], int n)
{
    int k,x;
    /*sua vi tri k trong mang*/
    if(n != 0)
    {
        cout <<"\nnhap vi tri can sua: ";
        cin >>k;
        if(k <= n && k > 0)
        {
            cout <<"\nnhap gia tri can sua: ";
            cin >>x;
            arr[k-1] = x;
        }else{
            cout <<"\n vi tri sua khong hop le!";
        }
    }else{
        cout <<"\nkhong co phan tu nao trong mang de sua! ";
    }
}
int tk_vitri(int arr[MAX], int n, int x)
{
    int vitri_k =0;
    /*tim vi tri cua gia tri x*/
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == x)
        {
            vitri_k = i;
            return vitri_k;
        }
    }
}
void xoa_giatri(int arr[MAX], int &n)
{
    int x,k;
    cout <<"\nnhap gia tri muon xoa: ";
    cin >>x;
    /*xoa vi tri k trong mang*/
    if(n != 0)
    {
        do{
            k = tk_vitri(arr,n,x);
            if(k == 0)
            {
                break;
            }          
            for(int i = k; i < n; i++)
            {
                arr[i] = arr[i+1];
            }
            n = n - 1;
        }while(k);           
    }else{
        cout <<"\nkhong co phan tu nao trong mang de xoa! ";
    }
}
void sapxep_giam(int arr[], int n)
{
    int temp;
    for(int i = 0; i < (n-1); i++)
    {
        for(int j = i; j < n; j++)
        {
            /*so truoc nho hon so sau*/
            if(arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
/*-----------------------END--------------------------*/