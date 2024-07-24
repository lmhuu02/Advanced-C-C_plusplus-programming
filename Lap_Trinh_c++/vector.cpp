#include <iostream>
#include <vector>

using namespace std;

//push_back day du lieu vao vector

int main()
{
	vector<int> v;
	v.push_back(44);
	v.push_back(21);
	cout <<v.size() <<endl;
	v.push_back(18);
	v.push_back(11);
	cout <<v.size() <<endl;
	cout <<"phan tu o giua la: " << v[1] <<endl;
	cout <<"in ra tat cac gia tri vector: ";
	for(int i = 0; i < v.size(); i++)
	{
		cout <<"\n" << v[i] <<endl;
	}
	for(int x : v){
		cout << x << endl;
	}
	
	
}
