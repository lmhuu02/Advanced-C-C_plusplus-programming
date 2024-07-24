#include <iostream>
#include <exception>

using namespace std;

/*tu tao mot ngoai le cho rieng minh, tuong tu nhu ham chuan out_of_range
class MyException ke thu tu ham cha exception*/
class MyException : public exception{
    public:
        const char* what() const throw(){
            return "Ngoai le la o day!";
        }
};
class MyException1 : public exception{
    public:
        const char* what() const throw(){
            return "Ngoai le la o cho nay nua!";
        }
};

int main()
{
    /*vd 1*/
    try{
        int age;
        cout <<"nhap vao so tuoi: ";
        cin >>age;
        if(age <= 0)
        {
            throw out_of_range("tuoi khong hop le");
        }
        cout <<"\ntuoi vua nhap la: "<<age<<endl;
    }
    catch(const exception& e){
        cout <<"\nNgoai le: "<<e.what() <<endl;
    }

    /*vd 2*/
    try{
        int age;
        cout <<"nhap vao so tuoi: ";
        cin >>age;
        if(age <10)
        {
            throw MyException();
        }
        try{
            if (age >12)
            {
                throw MyException1();
            }
        }catch(const MyException1& e){
            cout <<"exception: "<<e.what() <<endl;
        }
    }catch(const MyException& e){
        cout <<"NGOai Le: "<< e.what() <<endl; 
    }
    return 0;
}