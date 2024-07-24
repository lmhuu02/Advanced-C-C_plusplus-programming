#include <iostream>

using namespace std;

void bai1_tinhtong();
void bai2_pheptinh();
void bai3_giaido();
void bai4_tbc();

int main()
{
    cout<<"hello\n";
    // bai1_tinhtong();
    bai2_pheptinh();
    // bai3_giaido();
}

void bai1_tinhtong()
{
    float sum = 0;
    int n;
    cout<<"nhap vao gia tri n: ";
    cin>>n;
    int j = 2;
    int i;
    for(i = 1; i <= n; i++)
    {
        sum = sum + (float)i/(float)j;
        // cout<<sum<<" "<<i<<" "<<j<<" ";
        j++;
    }
    cout<<"tinh tong phep tinh: "<<sum;

    i=1;
    j=2;
    int dem = 1;
    do{
        
       sum = sum + (float)i/(float)j; 
       i++;
       j++;
       dem++;
    }while(sum <= (float)100.0);
    cout<<"\nde tong < 100 thi n = "<<dem;
}
void bai2_pheptinh()
{   
    char pheptinh;
    float a,b;
    float ketqua = 0;
    cout<<"nhap phep tinh theo bieu thuc: a PT b: ";
    cin>>a>>pheptinh>>b;
    cout<<"phep tinh la: "<<a<<pheptinh<<b;
    switch (pheptinh)
    {
    case '+':
        ketqua = a + b;
        cout<<"\nket qua: a+b = "<<ketqua;
        break;
    
    case '-':
        ketqua = a - b;
        cout<<"\nket qua: a-b = "<<ketqua;
        break;
    
    case '*':
        ketqua = a * b;
        cout<<"\nket qua: a*b = "<<ketqua;
        break;
    
    case '/':
        if(b != 0)
        {
            ketqua = a / b;
            cout<<"\nket qua: a/b = "<<ketqua;
        }
        else
        {
            cout<<"\nkhong thuc hien duoc phep tinh";
        }
        break;
    
    default:
        cout<<"\nloi khi nhap phep tinh";
        break;
    }
}
void bai3_giaido()
{
    //hoi so ga va tho biet tong so dau va chan:
    //dau moi con 1 cai -> tong so la 35
    //chan ga co 2 chan, tho 4 chan
    //dk: ga+tho=35 && 2ga+4tho=94
    const int head = 35;
    const int  foot= 94;
    int chicken, rabbit;  
    for(chicken = 1; chicken <= 35; chicken++)
    {
        for(rabbit = 1; rabbit <= 35; rabbit++)
        {
            if((chicken+rabbit) == 35 && (2*chicken+4*rabbit) == 94)
            {
                cout<<"\nchicken = "<<chicken<<"\t rabbit = "<<rabbit;
                break;
            }
        }
    }
}
void bai4_tbc()
{
    int n;
    int tong = 0;
    float tbc = 0;
    cout<<"\nnhap so nguyen n: ";
    cin >>n;
    for(int i = 0; i < n; i++)
    {
        tong = tong + i;
    }
    tbc = tong/n;
    cout<<"\ntong n so vua nhap la: "<<tong;
    cout<<"\ntb cong cac so la: "<<tbc;
}