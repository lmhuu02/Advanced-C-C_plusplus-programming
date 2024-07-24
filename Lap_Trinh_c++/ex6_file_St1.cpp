#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    /*ghi file*/
    ofstream writeFile("String.txt");
    if(writeFile.is_open())
    {
        string data = "Hello world!";
        writeFile <<data <<endl;
        writeFile.close();
        cout <<"\n String da ghi vao file: ";
    }else{
        cerr << "\nCan Not open file do write ";
    }

    /*doc file*/
    ifstream readFile("String.txt");
    if(readFile.is_open())
    {
        string data_in;
        getline(readFile,data_in);
        cout <<"\n chuoi da duoc doc tu file "<< data_in;
        readFile.close();
    }else{
        cerr <<"\n khong ther mo file de doc ";
    }

}