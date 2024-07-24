#include <iostream>

using namespace std;

int UCLN(int,int);
void Rutgon(int,int);

int main()
{
    int a,b;
    cout <<"\nnhap phan so a/b: ";
    cin >>a>>b;
    if(b == 0){
        cout <<"\n phan so khong ton tai!";
    }else{
        cout <<"\n a/b: "<<a<<"/"<<b;
        Rutgon(a,b);
    }
    
}


int UCLN(int num1, int num2){
    int uocChung;
   for(int i = 1; i <= num1 || i <= num2; i++)
   {
        if(num1 % i ==0 && num2 % i == 0)
        {
            uocChung = i;
        }
   } 
   return uocChung;
}

void Rutgon(int num1, int num2)
{
    int uocChung = UCLN(num1, num2);
    int n1,n2;
    n1 = num1/uocChung;
    n2 = num2/uocChung;
    if(n2 == 1){
        cout <<"\nphan so sau khi rut gon: "<<n1;
    }else{
        cout <<"\nphan so sau khi rut gon: "<<n1<<"/"<<n2;
    }
}
    