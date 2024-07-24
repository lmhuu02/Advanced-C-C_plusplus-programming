#include <iostream>
#include <string>

using namespace std;

string isInteger(const string& s)
{
    try{
        stoi(s);
        return "day la so nguyen";
    }catch(const invalid_argument){
        return "day khong phai so nguyen";
    }catch(const out_of_range){
        return "gia tri khong xac dinh";
    }
}

int main()
{
    string input;
    cout <<"enter an integer: ";
    cin>>input;
    cout <<isInteger(input);
    return 0;
}