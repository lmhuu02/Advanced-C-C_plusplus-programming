#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main(){
	ifstream readfile("input.txt");
	vector<int> myvector;   /*khai bao vecter*/
	while(!readfile.eof())
	{
		int a;
		readfile>>a;
		myvector.push_back(a);  /*ghi gia tri a vao vi tri cuoi cung trong vecter*/
	}
	cout<<"\n Su dung vector: \n";
	for(int i=0;i<myvector.size();i++)
		cout<<myvector[i]<<" ";
	readfile.close();

    /*xoa phan tu le*/
    for(int i = myvector.size(); i >= 0; i--)
    {
        if(myvector[i] % 2 != 0)
        {
            /*xoa phan tu o vi tri i trong mang vecter*/
            myvector.erase(myvector.begin()+i);
        }
    }
    /*hien thi sau xoa*/
    cout <<"\n so le sau khi xoa: ";
    for(int i = 0; i < myvector.size(); i++)
    {
        cout<<myvector[i]<<" ";
    }
    readfile.close();
}
