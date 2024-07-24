#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class DoiTuong {
public:
     string name;
     string address;

    DoiTuong() {}

    DoiTuong(const  string& t1, const  string& t2) : name(t1), address(t2) {}
};

int main() {
   
     ofstream ghi_file("ten_file.txt");

    if (ghi_file.is_open()) {
     
        ghi_file << 2 <<  endl;


        DoiTuong doi_tuong1("1", "2");
        ghi_file << doi_tuong1.name << " " << doi_tuong1.address <<  endl;

    
        DoiTuong doi_tuong2("3", "4");
        ghi_file << doi_tuong2.name << " " << doi_tuong2.address <<  endl;

   
        ghi_file.close();
    } else {
         cerr << "Khong the mo file de ghi." <<  endl;
        return 1;
    }
 
     ifstream doc_file("ten_file.txt");

    if (doc_file.is_open()) {
   
        int n;
        doc_file >> n;

        for (int i = 0; i < n; ++i) {
             string t1, t2;
            doc_file >> t1 >> t2;
             cout << "Doi tuong " << i + 1 << ": Thuoc tinh 1 = " << t1 << ", Thuoc tinh 2 = " << t2 <<  endl;
        }

        doc_file.close();
    } else {
         cerr << "Khong the mo file de doc." <<  endl;
        return 1;
    }

    return 0;
}