#include <iostream> //
#include <fstream>
#include <thread>
#include <stdexcept>
using namespace std;

void doc(){
	try{
		ifstream docfile;//khai bao doi tuong co chuc nang docfile
		docfile.open("cau1.txt");//mo file de doc
		if(!docfile.is_open()){
			throw runtime_error("File khong duoc mo");
		}
		int a;//khai bao bien
		while(docfile>>a){//lap while
			cout<<a<<" ";//khong doc khoang trang
		}
		docfile.close();
	}catch(const exception& e){
		cerr<<"Ngoai le: "<<e.what();
	}
	cout<<endl;//xuong dong
}
void dockitu(){
	ifstream docfile;
	docfile.open("cau1.txt");
	int dem=0;
	char b;
	while(docfile.get(b)){
		if(b=='n'){
			dem++;
		}
	}
	cout<<dem;
	docfile.close();
}

int main(){
	try{
		thread docfile(doc);
		docfile.join();
		
		thread dockitu1(dockitu);
		dockitu1.join();
	}catch(const exception& e){
		cerr<<"Ngoai le luong: "<<e.what();
	}
	return 0;//
}
