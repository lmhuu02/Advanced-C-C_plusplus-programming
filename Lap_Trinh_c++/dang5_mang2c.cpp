#include<iostream>
#include<thread>
#include<cmath>
using namespace std;
const int Max_Size=100;
void nhapmang2(int array[][Max_Size],int n,int m){
	cout<<"Nhap cac phan tu cho mang "<<n<<" x "<<m<<" :\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<"Nhap phan thu a["<<i<<"]["<<j<<"]: ";
			cin>>array[i][j];
		}
	}
}
void xuatmang2(const int array[][Max_Size], int n, int m){
	cout<<"Cac phan tu vua nhap la:\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<array[i][j]<< " ";
			
		}
		cout<<endl;	

	} 
}
void duongcheoP(int array[][Max_Size],int n,int m){
	if(n!=m){
		cout<<"Day khong phai ma tran vuong\n";
		return;
	}
	cout<<"Duong cheo phu la:\n";
	for(int i=0;i<n;i++){
		
			cout<<array[i][m-1-i]<<" ";
		
	}
}
bool isChinhPhuong(int num){
	for(int i=1;i<=num;i++){
		int mu=i*i;
		if(mu==num) return true;
		if(mu>num) return false;
	}
	return false;
}
int countCP(int array[][Max_Size], int n, int m){
	int count=0;
	cout<<"\nCac so chinh phuong:";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(isChinhPhuong(array[i][j])){
				count++;
				cout<<array[i][j]<<" ";
			}

		}
	}
	return count;
}
int main(){
	int n,m;
	cout<<"Nhap hang n= ";
	cin>>n;
	cout<<"Nhap hang m= ";
	cin>>m;
	int array[Max_Size][Max_Size];
	thread inputThread(nhapmang2,array,n,m);
	inputThread.join();
	thread displayThread(xuatmang2,array,n,m);
	displayThread.join();
	thread cheoThread(duongcheoP,array,n,m);
	cheoThread.join();
	int dem=countCP(array,n,m);
	cout<<"\nCo "<<dem<< "so chinh phuong\n";
	return 0;
}
