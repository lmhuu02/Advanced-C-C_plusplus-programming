#include <iostream>
#include <thread>

using namespace std;

void inle()
{
    for(int i = 1; i<10000;i+=2)
    {
        cout <<" le"<<i<<"  \n";
    }
}

void inchan()
{
    for(int i = 0; i<10000;i+=2)
    {
        cout <<" chan:"<<i<<"  \n";
    }
}

int main()
{
    thread funcTest1(inle);
    thread funcTest2(inchan);
    funcTest1.join();
    funcTest2.join();
}