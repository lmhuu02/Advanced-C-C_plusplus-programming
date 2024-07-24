/*
power by Le Minh Huu - KTMT K19A - ICTU @copyright
time: 25/2/2402
C++ VSCode Exception array file in out
*/
#include <iostream>
#include <fstream>
#include <exception>
#include <string>

using namespace std;

class MyException : public exception{
    public:
        const char* what() const throw(){
            return "day khong phai so phan tu mang";
        }
};
class Exc_file : public exception{
    public:
        const char* what() const throw(){
            return "loi khong mo file, khong ghi duoc file";
        }
};

int main(){
    int n;
    try{
        do{
            cout <<"\nnhap so phan tu cua mang: ";
            cin >>n;
        }while(n > 10 || n < 0);
        
    }catch(const MyException& e){
        cout<<"EXCEPTION: "<<e.what()<<endl;
    }
    
    //nhap phan tu mang
    int arr[n];
    cout <<"\nnhap phan tu mang: ";
    for(int i = 0; i < n; i++)
    {
        cout <<"\nphan tu thu "<<i+1<<" : ";
        cin >>arr[i];
    }

    //in phan tu
    try{
        int numElements = sizeof(arr) / sizeof(arr[0]);
        if(numElements == 0)
        {
            throw "mang rong khong co phan tu";            
        }
        cout <<"\nPhan tu mang: ";
        for(int i = 0; i < n; i++)
        {
            cout <<arr[i]<<" ";
        }
    }catch(const char* mgs){
        cerr <<mgs<<endl;
    }

    //ghi mang vao file mang1.txt
    try{
        ofstream writefile("mang1.txt");
        for(int i = 0; i < n; i++)
        {
            writefile<<" "<<arr[i];
        }
        writefile.close();
    }catch(const Exc_file& e){
        cout <<"\n Ngoai le: "<<e.what()<<endl;
    }

    //sap xep mang giam dan
    int temp;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(arr[i] < arr[j])
            {
                
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
               
            }
        }
    }
     //ghi gia tri vao file 
    try{
        ofstream writefile("mang2.txt");
        for(int i = 0; i < n; i++)
        {
            writefile<<" "<<arr[i];
        }
        writefile.close();
    }catch(const Exc_file& e){
        cout <<"\n Ngoai le: "<<e.what()<<endl;
    }
}
