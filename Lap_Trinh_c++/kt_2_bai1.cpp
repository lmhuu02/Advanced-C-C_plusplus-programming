#include <iostream>
#include <string.h>

using namespace std;

class sinhvien{
    public:
        sinhvien();
        void nhapThongTin(string,string,float); //msv, ho ten, diem
        void timKiem(sinhvien[], string); //nhap ho ten
        string getHoTen();
        string getMsv();
        float getDiem();

        void setMsv(string);
        void setHoTen(string);
        void setDiem(float);

    private:
        string msv;
        string hoten;
        float diem;
};

sinhvien::sinhvien(){
    msv = "";
    hoten = "";
    diem = 0;
}

void sinhvien::setMsv(string msv)
{
    this->msv;
}
void sinhvien::setHoTen(string hoten)
{
    this->hoten;
}
void sinhvien::setDiem(float diem)
{
    this->diem;
}

string sinhvien::getMsv()
{
   return (this->msv);
}
string sinhvien::getHoTen()
{
    return (this->hoten);
}
float sinhvien::getDiem()
{
   return (this->diem);
}
void sinhvien::nhapThongTin(string msv1, string hoten1, float diem1)
{
    msv = msv1;
    hoten = hoten1;
    diem = diem1;
}
/*ss chuoi compade*/
 void timKiem(sinhvien sv[],string hoten)
 {
    string str1;
    int dem = 0;
    for(int i = 0; i < 3; i++)
    {
        str1 = sv[i].getHoTen();
        if(str1.compare(hoten) == 0){
            cout<<"\n ma sinh vien la: "<< sv[i].getMsv();
            dem++;
        }
    }
    if(dem == 0)
    {
        cout <<"\nkhong tim thay sinh vien "<<hoten<<" trong ds";
    }
 }
int main()
{
    sinhvien sv[3];
    string masv,ht;
    float diem1;
    cout <<"\nnhap thong tin sinh vien: ";
    for(int i = 0; i <3; i++)
    {
        cout <<"\nsinh vien thu "<<(i+1)<<" ";
        
        cout <<"\nmsv: ";
        // cin >>masv;
        fflush(stdin);
        getline(cin,masv);
        getline(cin,masv);
        fflush(stdin);
        cout <<"\nhoten: ";
        getline(cin,ht);
        // cin >>ht;
        fflush(stdin);
        cout <<"\ndiem: ";
        cin >>diem1;
        fflush(stdin);
        // sv[i].setMsv(masv);
        // sv[i].setHoTen(ht);
        // sv[i].setDiem(diem1);
        sv[i].nhapThongTin(masv,ht,diem1);
    }
    cout <<"\nhien thi thong tin sinh vien: ";
    for(int i = 0; i < 3; i++){
        cout <<"\nsinh vien thu "<<(i+1)<<" : ";
        cout<<sv[i].getMsv() <<" "<<sv[i].getHoTen()<<" "<<sv[i].getDiem();    
    }
    string str = "nguyen van cao";
    string str1;
    // timKiem(sv,str);
    int dem = 0;
    for(int i = 0; i < 3; i++)
    {
        str1 = sv[i].getHoTen();
        if(str1.compare(str) == 0){
            cout<<"\n ma sinh vien la: "<< sv[i].getMsv();
            dem++;
        }
    }
    if(dem == 0)
    {
        cout <<"\nkhong tim thay sinh vien "<<str<<" trong ds";
    }
}