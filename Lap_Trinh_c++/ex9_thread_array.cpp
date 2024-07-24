
#include <iostream>
#include <thread>
using namespace std;
const int arraySize = 5; 

void nhapmang(int array[], int size) {
  
    cout << "Nhap phan tu mang:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> array[i];
    }
}
void hienthi(const int array[], int size) {
  
    cout << "Mang vua nhap la:\n";
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int myArray[arraySize];
	// nhapmang(myArray,arraySize);

   thread inputThread(nhapmang, myArray, arraySize);
    inputThread.join();
    thread displayThread(hienthi, myArray, arraySize);
    // this_thread::sleep_for(chrono::seconds(10));
    cout<<"Da nhap xong mang! n";
   
    displayThread.join();

    return 0;
}
