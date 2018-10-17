#include <iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

class Student{
	int rollNo;
	char name[1010];
public:
	Student(int v,char n[]){
		rollNo=v;
		strcpy(name,n);
	} 
	void printStuds(){
		cout<<"Roll Number : "<<rollNo<<"\nName :"<<name<<"\n";
	}
};


int main(){
	int rn;
	char n[10010];
	cout<<"Enter roll no. :";
	cin>>rn;
	cout<<"Enter name :";
	cin.ignore();
	gets(n);
	Student s(rn,n);
	s.printStuds();
	return 0;
}