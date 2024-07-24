#include <iostream>
#include <fstream>
#include <cstring> 

using namespace std;

void demtu(string s){
	int n = s.length(); /*dem kich thuoc chuoi s*/
	int dem =1;

	char * array = new char[n+1];
	strcpy(array, s.c_str()); 
	
    for(int i=0;i<n;i++){
		if(array[i]==' ') dem++;
	}
	cout<<"\n trong chuoi co "<<dem<<" tu";
}

int main() {
    /*ghi vao file chuoi*/
    ofstream writeFile("demoString.txt");
    if (writeFile.is_open()) {
   
        string data = "Hello, World!";
        writeFile << data <<  endl;
        writeFile.close();

         cout << "Chuoi da duoc ghi vao file thanh cong." <<  endl;
    } else {
         cerr << "Khong the mo file de ghi." <<  endl;
    } 
    
    /*docc tu file ra */
    string data;
    ifstream readFile("demoString.txt");
    if (readFile.is_open()) {
        
		getline(readFile,data);   
		cout << "Chuoi doc tu file: " <<  data;
		demtu(data);
        readFile.close();		
    } else {
        cerr << "Khong the mo file de doc." <<  endl;
    }

    /*chuyen doi chuoi sang char*/
    cout <<"\nchuyen doi chuoi sang char: ";
    const char *chuoi_dt = data.c_str();
    int leng = data.length();
    int dem_ch = 0;
    for(int i = 0; i < leng; i++)
    {
        cout <<chuoi_dt[i];
        /*dem tu ch*/
        if(chuoi_dt[i] == 'c')
        {
            if(chuoi_dt[i+1] == 'h')
            {
                dem_ch++;
            }
        }
    }
    if(dem_ch != 0)
    {
        cout <<"\ntrong chuoi co "<<dem_ch<<" ky tu ch";
    }else{
        cerr <<"\ntrong chuoi khong co ky tu ch";
    }

    /*chuyen doi chuoi thanh chu in hoa*/
    char dt[leng];
    for(int i = 0; i < leng; i++)
    {
        dt[i] = toupper(chuoi_dt[i]);
    }
    cout <<"\n chuoi chuyen sang in hoa: \n";
    for(int i = 0; i < leng; i++)
    {
        cout <<dt[i];
    }
}
