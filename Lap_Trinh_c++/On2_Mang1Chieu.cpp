/*-----------------------START--------------------------*/
/*
Power by: Minh Huu @copyright - time: 4/1/2024
langauge: C++ - IDE: VSCode
*/
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int square(int);
void test_square();
double max(double, double, double);
void test_max();
void random_num();
void thamchieu(int,int);
void thamtri(int, int);
int chongham(int x);
int chongham(double y);
void test_chongham();

int m = 5;
/*-----------------------MAIN--------------------------*/
int main()
{
    random_num();
    // test_max(); 
    // test_square();
    cout <<"num: "<<m<<"\n";

    int n1 = 5, n2 = 8;
    thamtri(n1,n2);
    cout <<"\n tham tri: "<< n1 <<" "<<n2 <<endl;
    // thamchieu(n1,n2);
    cout <<"\n tham chieu: "<< n1 <<" "<<n2 <<endl;
    return 0;
}
/*-----------------------FUNCTION--------------------------*/
void test_square()
{
    for(int i = 1; i <=10; i++)
    {
        cout <<square(i)<<"\t";
    }
}
void test_max(){
    double a,b,c;
    cout <<"\nnhap gia tri 3 so: ";
    cin >>a>>b>>c;
    cout <<"\ngia tri max: "<<max(a,b,c);
}
int square(int x)
{
    return x*x;
}
double max(double a, double b, double c)
{
    double num_max = a;
    if(b > num_max)
    {
        num_max = b;
    }else if(c > num_max){
        num_max = c;
    }
    return num_max;
}
void random_num()
{
    int m = 2;
    srand(time(NULL));
    int sord = rand() % 10000 +1;
    cout <<m<<"random: "<< sord<<endl;

}

void thamchieu(int &n1, int &n2)
{
    n1 = n1 + 10;
    n2 = n2 + 20;
}
void thamtri(int n1, int n2)
{
    n1 = n1 + 10;
    n2 = n2 + 20;
}

int chongham(int x)
{
    return x*x;
}
int chongham(double y)
{
    return (y*y +1);
}
void test_chongham()
{
    int x;
    double y;
    cout <<"\nnhap gia tri x: ";
    cin >>x >>y;
    cout <<"\ngiam doc he so +1: "<<chongham(y);
    cout <<"\nhe so: "<<chongham(y);
}
/*-----------------------END--------------------------*/


