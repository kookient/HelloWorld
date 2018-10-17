#include <iostream>
using namespace std;

const int MAXSIZE=20;
struct stack{
	int arr[MAXSIZE];
	int top;
};


void push(stack *s,int val){
	if(s->top==MAXSIZE){
		cout<<"\nStack is full.";
	}
	s->top++;
	s->arr[s->top]=val;
}
int pop(stack *s,)
int main(){
	stack st;
	st.top=-1;
	do{
		printf("\n1. push elements to stack.");
		printf("\n2. Pop Element from stack.");
		printf("\n3. Print Stack.");
		printf("\n4. Exit");
		cin>>ch;
		switch(ch){
			case 1:
			cin>>val;push(&st,val);break;
			case 2:int popped=pop(&st)
			cout<<"\n\nPopped element is : "<<popped;break;
			case 3:show(st);break;
			case 4:break;
		}
	}while(ch!=4);
}