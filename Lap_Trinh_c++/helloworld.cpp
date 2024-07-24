/*=============================START FILE====================*/
#include <iostream>
#include <math.h>

using namespace std;

void helloif();
void while1();
void laikep();
void switch1();
/*=============================MAIN====================*/
int main()
{
    // while1();
    laikep();
    return 0;
}

/*=============================FUNCTION====================*/
void switch1()
{

}

void laikep()
{
    //lai kep a = p*(1+r)^n
    float p = 1000;
    float r = 0.05;
    int n = 10;
    float a = 0;
    for(int i = 1; i <= n; i++)
    {
        a =  (a+p)*pow((1.0+r),i);
        cout<<"\nlãi kép năm "<<i <<" = "<<a;
    }
}

void while1()
{
    cout<<"hi ";
    int product = 2;
    while(product <=100)
    {
        product = 2*product;
    }
    cout<<"product: "<<product;
}

void hello_if()
{
    int grade;
    std::cout<< "hello world!\n";
    cout<<"nhap gia tri great: ";
    cin>>grade;
    if(grade >= 60)
    {
        cout<<"passed\n";
    }else if(grade <60)
    {
        cout<<"failed\n";
    }
    else{
        cout<<"grade nho hon 60\n";
    }
}
/*=============================END FILE====================*/