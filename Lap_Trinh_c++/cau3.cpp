#include <iostream>
#include <fstream>
#include <stdexcept>
#include <thread>
using namespace std;

void dem(){
	try{
		ifstream docfile; //docfile
		string a;
		int dem=0;
		docfile.open("cau1.txt");
		if(!docfile.is_open()){
			throw runtime_error("Khong mo duoc file!");
		}
		while(docfile>>a){
			dem++;
		}
		cout<<dem;
		docfile.close();
		cout<<endl;	
	}
	catch(const exception& e){
		cerr<<"Ngoai le: "<<e.what();
	}
}
void hienthi(){
	ifstream docfile;
	string a;
	int dem=0;
	docfile.open("cau1.txt");
	while(docfile>>a){
		cout<<a<<" ";
	}
	docfile.close();
}
int main(){
	try{
		thread dem1(dem);
		dem1.join();
		
		thread hienthi1(hienthi);
		hienthi1.join();
	}catch(const exception& e){
		cerr<<"Ngoai le luong!"<<e.what();
	}
}
