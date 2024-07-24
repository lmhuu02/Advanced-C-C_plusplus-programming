/*
Dạng 1:
Viết chương trình đọc nội dung trong tệp input.txt. Xây dựng các tiến trình thực hiện các chức năng cụ thể sau:
a.	Hiển thị nội dung đọc được lên màn hình.
b.	Tìm kiếm trong nội dung tệp có bao nhiêu kí tự ‘n’. Hiển thị kết quả ra màn hình.
c.	Bắt 02 ngoại lệ bất kì trong bài.
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	/*
	fstream: file chung
	ifstream: doc file
	ofstream: ghi file
	*/
	//tao file ghi mang gia tri vao
	ofstream writefile;
	writefile.open("ghifile1.txt");
	
	//nhap du lieu
	
	
	
	writefile.close();
}
