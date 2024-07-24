#include <iostream>

#define MAX 200

using namespace std;

void nhap(int[],int&);
void xuat(int[],int);
int kiemtra(int,int);
void demSHH(int[],int);

int main()
{
    int arr[MAX];
    int n;
    nhap(arr,n);
    xuat(arr,n);
    demSHH(arr,n);
}

void nhap(int arr[MAX], int &n)
{
    int i = 0;
    int x;
    do{
        cout <<"\nnhap phan tu "<<i<<": ";
        cin >>x;
        arr[i] = x;
        n = i;
        i++;
        // cout <<"\naaaa"<<arr[i]<<" "<<n;
    }while(x != -1);
}
void xuat(int arr[MAX], int n){
    cout <<"\nxuat mang: ";
    for(int i = 0; i < n; i++)
    {
        cout <<"\nphan tu: "<<i<<": "<<arr[i];
    }
}
int kiemtra(int x)
{
    int sum_shh = 0;
    for(int i = 1; i < x; i++)
    {        
        if(x % i == 0)
        {
            sum_shh += i;
        }
    }
    if(sum_shh == x){
        return 1;
    }else{
        return 0;
    }
}

void demSHH(int arr[MAX], int n)
{
    int dem = 0;
    for(int i = 0; i < n; i++){
        if(kiemtra(arr[i]) == true)
        {
            cout <<"\n"<<arr[i];
            dem++;
        }
    }
    if(dem == 0)
    {
        cout <<"\nkhong co so hoan hao nao trong mang!";
    }else{
        cout <<"\ntong cac so hoan hao trong mang la: "<<dem;
    }
}