#include <iostream>

using namespace std;

class person{
    public:
        person();
        void show();
        void setID(int,int);

    public: 
        int id;
        int age;

};

person::person(){
    id = 0;
    age = 0;
}
void person::show(){
    cout <<"show something";
}
void person::setID(int value, int value2){
    id = value;
    age = value2;
}

class sum_num{
    public:
        sum_num();
        void nhap(float,float);
        void sum();
        void show();
    private:
        float tongSo;
        float num1;
        float num2;
};

sum_num::sum_num(){
    tongSo = 0;
    num1 = 0;
    num2 = 0;

}

void sum_num::nhap(float a, float b){
    num1 = a;
    num2 = b;

}
void sum_num::sum(){
    tongSo = num1+num2;
}
void sum_num::show(){
    cout<<"\ntong 2 so: "<<tongSo;
}
int main()
{
    person s1;
    s1.setID(102, 21);
    s1.show();
    cout <<"\nnum ID: "<<s1.id;
    cout <<"\nnum age: "<<s1.age;

    cout<<"\n\n";
    cout<<"\nnhap so 1, 2:";
    int a,b;
    cin >>a >>b;
    sum_num tong;
    tong.nhap(a,b);
    tong.sum();
    tong.show();
    
}