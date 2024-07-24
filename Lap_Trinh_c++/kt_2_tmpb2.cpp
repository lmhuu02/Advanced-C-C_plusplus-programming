#include <iostream>
#include <fstream>

using namespace std;

#define MAXN 100
#define MAXM 100

void ReadF(string);

int main()
{
    cout <<" BUG a";
    string namefile = "kt_2_input.txt";
    int arr[MAXN][MAXM];
    int n = 0,m = 0;
    cout <<" BUG b";
    ReadF(namefile);
}
void ReadF(string namefile){
    int arr[MAXM][MAXN];
    int n; int m;
    int count_line =  0;
    int count_num =  0;
    /*ifstream: in file stream*/
    ifstream readfile(namefile);
    /*eof: end of file - dem so dong trong file*/
    cout <<" BUG 0";
    while(!readfile.eof())
    {   
        count_line++;
        // Chuyển con trỏ xuống dòng tiếp theo
        readfile.ignore(); 
    }
    /*dem so ky tu trong file*/
    readfile.seekg(0);  /*chuyen con tro len phan tu dau tien*/
    while(!readfile.eof())
    {   
        int a;
        readfile>>a;
        cout <<" "<<a;
        count_num++;       
    }
    n = count_line/2; //so hang
    m = count_num/count_line;   //so cot
    cout <<"\n so 10 hang, so cot: "<< n <<" "<<m;
  

}