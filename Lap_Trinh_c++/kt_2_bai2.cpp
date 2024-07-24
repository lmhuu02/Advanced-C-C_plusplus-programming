#include <iostream>
#include <fstream>

using namespace std;

#define MAXN 100
#define MAXM 100

void ReadF(string, int [MAXN][MAXM], int&,int&);
void cheoChinh(int [MAXN][MAXM], int, int);
void minNum(int [MAXN][MAXM], int, int);
void WriteF(string, int [MAXN][MAXM], int, int);

int main()
{
    string namefile = "kt_2_input.txt";
    int arr[MAXN][MAXM];
    int n = 0,m = 0;
    ReadF(namefile,arr,n,m);
    cheoChinh(arr,n,m);
    minNum(arr,n,m);
    string uname = "kt_2_output.txt";
    WriteF(uname, arr,n, m);
}

void ReadF(string namefile, int arr[MAXM][MAXN], int &n, int &m){
    /*ifstream: in file stream*/
    ifstream readfile(namefile);
    readfile>>n;
    readfile>>m;  
    cout <<"\n so hang, so cot: "<< n <<" "<<m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
           readfile>>arr[i][j];
        }
    }

    cout <<"\ndoc file: \n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
           cout <<arr[i][j]<<" ";
        }
        cout <<"\n";
    }
}
void cheoChinh(int arr[MAXN][MAXN], int n,int m)
{
    cout <<"\nduong cheo chinh trong mang la: ";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(i == j)
            {
                cout <<arr[i][j]<<" ";
            }           
        }
    }
}
void minNum(int arr[MAXN][MAXN], int n,int m)
{
    int min = arr[0][0];
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            if(min > arr[i][j])
            {
                min = arr[i][j];
            }           
        }
    }
    cout <<"\nphan tu nho nhat trong mang la: "<<min;
}
void WriteF(string uname, int arr[MAXN][MAXM], int n, int m)
{
    ofstream writefile(uname);
    for(int i = 0; i < n; i++)
    {
        writefile<<" "<<arr[i][0];
    }
    writefile.close();
}
