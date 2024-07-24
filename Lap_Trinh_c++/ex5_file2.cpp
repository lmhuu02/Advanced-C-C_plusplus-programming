/*==========================START FILE=======================*/
/*power by: Le Minh Huu @copyright - Time: 17/1/2024
IDE: VSCode - Langauge: C++ - File in C++
*/
#include <iostream>
#include <fstream>

using namespace std;

void ReadF(string);
void WriteF(string);
void DemSo(string);
void XoaSo(string, string);

/*==========================MAIN=======================*/
int main()
{
    // string name = "data.txt";
    // WriteF(name);
    // ReadF(name);
    string name1 = "input.txt";
    string namefile1 = "output.txt";
    cout <<"\ndoc noi dung tu file input.txt: \n";
    // DemSo(name1);
    XoaSo(name1, namefile1);
    // ReadF(name1);
    // cout <<"\n so le vua xoa la: ";
    // ReadF(namefile1);

}

/*==========================FUNCTION=======================*/


void DemSo(string namefile){
    /*ifstream: in file stream*/
    ifstream readfile(namefile);
    int dem = 0;
    /*eof: end of file*/
    while(!readfile.eof())
    {
        int a;
        readfile>>a;    //ghi gia tri vua doc duoc ra bien a
        cout<< " "<<a;  //hien thi bien a vua ghi len man hinh
        if(a % 2 == 0)
        {
            dem++;
        }
    }
    if(dem != 0)
    {
        cout <<"\n trong file co: "<< dem << " so chan";
    }else{
        cout <<"\n trong file k co so chan nao";
    }
}

void XoaSo(string namefile, string namefile1){
    /*ifstream: in file stream*/
    ifstream readfile(namefile);
    int dem_chan = 0;
    int dem_le = 0;
    
    /*dem so phan tu chan va le trong file. dem tu dau den cuoi file*/
    /*doc cac phan tu trong file tu dau den khi nao den cuoi: .eof end of file*/
    while(!readfile.eof())
    {
        int a;
        readfile>>a;    //ghi gia tri vua doc duoc ra bien a
        // cout<< " "<<a;  //hien thi bien a vua ghi len man hinh
        if(a % 2 == 0)
        {
            dem_chan++;
            // cout <<" \n chan "<<a;
        }else{
            dem_le++;
            // cout <<" \n le "<< a;
        }
    }
    /*in ra tong so chan va le trong file: */
    cout <<"\n dem chan: "<<dem_chan;
    cout <<"\n dem le: "<<dem_le;

    /*khai bao 2 mang chan va le de luu gia tri chan va le*/
    int chan[dem_chan];
    int le[dem_le];
    int i = 0, j = 0;
    cout <<" BUG 1";

    /*ghi gia tri vao mang, chuyen con tro den phan tu dau tien trong file*/
    readfile.seekg(0);
     while(!readfile.eof())
    {
        cout <<" BUG 2";
        int a;
        readfile>>a;    //ghi gia tri vua doc duoc ra bien a
        // cout<< " "<<a;  //hien thi bien a vua ghi len man hinh
        if(a % 2 == 0)
        {
            chan[i] = a;
            i++;
        }else{
            le[j] = a;
            j++;
        }
    }
    cout <<" in chuoi chan vao file: ";
    ofstream writefile(namefile);
    for(i = 0; i < dem_chan; i++){
        writefile<<" "<<chan[i]; /*ghi vao file*/
        cout <<" "<<chan[i];
    }
    writefile.close();  /*dong file 1*/

    cout <<" in chuoi le vao file: ";
    ofstream writefile_1(namefile1);
    for(i = 0; i < dem_le; i++){
        writefile_1<<" "<<le[i];    /* ghi vao file*/
        cout <<" "<<le[i];
    }
    writefile_1.close(); /*dong file 2*/
}

void ReadF(string namefile){
    /*ifstream: in file stream*/
    ifstream readfile(namefile);
    /*eof: end of file*/
    while(!readfile.eof())
    {
        int a;
        readfile>>a;    //ghi gia tri vua doc duoc ra bien a
        cout<< " "<<a;  //hien thi bien a vua ghi len man hinh
    }
}

void WriteF(string namefile){
    /*ofstream: out file stream*/
    ofstream writefile(namefile);
    for(int i = 0; i < 10; i++)
    {
        int a;
        cin>>a;
        writefile<<" "<<a;

    }
    writefile.close();
}
/*==========================END FILE=======================*/