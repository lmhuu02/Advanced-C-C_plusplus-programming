#include <iostream>
#include <thread>
using namespace std;
void nhap(int* n, int* m,int a[][99]){
	int i,j;
	cout<<"Nhap so hang n= ";
	cin>>*n;
	cout<<"Nhap so cot m=";
	cin>>*m;
	for(i=0;i<*n;i++){
		for(j=0;j<*m;j++){
			cin>>a[i][j];
		}
	}
}
void hienthi1(int n, int m, int a[][99]){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
void hienthi2(int n, int m, int a[][99]){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i+j==n-1){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
}
int main(){
	int n,m,i,j;
	int a[99][99];
	thread th_nhap(nhap, &n, &m, a);
	th_nhap.join();
	
	thread hienthi(hienthi1,n, m, a);
	hienthi.join();
	
	thread hienthi3(hienthi2,n, m, a);
	hienthi3.join();
	
}
