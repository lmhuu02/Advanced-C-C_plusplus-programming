#include<iostream>
#include<thread>
#include <algorithm>
using namespace std;
void nhapmang(int array[],int size){
	for(int i=0;i<size;i++){
		cout<<"Nhap phan tu thu"<<i<<":";
		cin>>array[i];
	}
}
void xuatmang(const int array[],int size){
	cout<<"Phan tu vua nhap la:\n";
	for(int i=0;i<size;i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
}
void sapXepGiam(int array[],int size){
	for(int i=0;i<size-1;i++){
		for(int j=i+1;j<size;j++){
			if(array[i]<array[j]){
				int tam=array[i];
				array[i]=array[j];
				array[j]=tam;
			}
		}
	}
	cout<<"Mang sau khi sap xep giam: \n";
	for(int i=0;i<size;i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
}
void xoaPhanTu(int array[], int &size, int viTri){
	if(viTri<0 || viTri>=size){
		cout<<"Vi tri xoa khong hop le\n";
		return;
	}
	for(int i=viTri;i<size-1;i++){
		array[i]=array[i+1];
	}
	size--;
}
int main(){
	int n;
	int *arr= new int[n];
	cout<<"Nhap so phan tu: ";
	cin>>n;
	thread inputThread(nhapmang,arr,n);
	inputThread.join();
	thread displayThread(xuatmang,arr,n);
	displayThread.join();
	thread sortThread(sapXepGiam,arr,n);
	sortThread.join();
	int a;
	cout<<"Nhap vi tri can xoa: ";
	cin>>a;
	thread deleteThread(xoaPhanTu,arr,ref(n),a);
	deleteThread.join();
	cout<<"Mang sau khi xoa phan tu o vi tri "<<a<< "la:\n";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	delete[] arr;
	return 0;
}
