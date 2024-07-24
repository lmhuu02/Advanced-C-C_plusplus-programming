#include<iostream>
#include<fstream>
#include<thread>
#include<stdexcept>
using namespace std;
void readFromFile(string filename, string& content){

	ifstream inFile(filename);
	if(!inFile){
		throw runtime_error("Ngoai le 1:Khong the mo tep!");
	}
	string line;
	while(getline(inFile, line)){
		content+=line;
	}
	inFile.close();
	
	
	
}
void displayContent(const string &content){
	cout<<"Noi dung duoc mo la:\n";
	cout<<content<<endl;
}
int countCharacter(const string& content, char character){
	int count=0;
	for(char c:content){
		if(c==character){
			count++;
		}
	}
	if(count ==0){
		throw runtime_error("Khong tim thay ky tu nao");
	}
	return count;
}

int main(){
	try{
	string content;
	readFromFile("input2.txt",content);
	thread displayThread(displayContent,content);
	displayThread.join();
	char target='n';
	int charTarget=countCharacter(content,target);
	cout<<"ky ty "<<target<<" trong tep la:"<<charTarget<<endl;
	}catch(const exception& e){
	cerr<<e.what()<<endl;
	}
	
	return 0;
}

